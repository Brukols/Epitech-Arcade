/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Core
*/

#include "Core.hpp"
#include "DLLoader.hpp"
#include "IGraphical.hpp"
#include "Errors.hpp"
#include <iostream>
#include <algorithm>
#include "Utils.hpp"
#include "Score.hpp"

arc::Core::Core(const std::string &libname)
try {
    _games.clear();
    _graphs.clear();
    initGraphs();
    initGames();
    setGraphical(getLibName(libname));
} catch(const DlError &e) {
    throw e;
} catch(const DirectoryError &e) {
    throw e;
} catch(const std::exception &e) {
    throw FileError("Wrong name of file", "CoreInit");
}

arc::Core::~Core()
{
}

void arc::Core::clean()
{
}

const std::vector<std::pair<std::string, std::string>> arc::Core::getControls() const
{
    std::vector<std::pair<std::string, std::string>> controls;
    controls.push_back(std::make_pair("Previous graphics library", "1"));
    controls.push_back(std::make_pair("Next graphics library", "0"));
    controls.push_back(std::make_pair("Previous game", "2"));
    controls.push_back(std::make_pair("Next game", "9"));
    controls.push_back(std::make_pair("Restart the menu", "r"));
    controls.push_back(std::make_pair("Go back to menu", "m"));
    controls.push_back(std::make_pair("Pause", "space"));
    controls.push_back(std::make_pair("Exit", "escape"));

    if (_indexGame != -1) {
        std::vector<std::pair<std::string, std::string>> gameControls = _game->getGameControls();

        std::for_each(gameControls.begin(), gameControls.end(), [&controls](const std::pair<std::string, std::string> &pair) {
            controls.push_back(std::make_pair(pair.first, pair.second));
        });
    }
    return (controls);
}

void arc::Core::functionPlay()
{
    _graph->setGameTitle(_game->getTitle());
    _graph->setControls(_game->getControls());
    _graph->setMapSize(_game->getMapHeight(), _game->getMapWidth());
    _graph->setGameStats(_game->getGameStats());
    _graph->setHowToPlay(getControls());
    _graph->setScene(arc::IGraphical::GAME);
    _graph->setFunctionMenu([this]() {
        _graph->setScene(arc::IGraphical::MAIN_MENU);
        _game->restart();
    });
    _graph->setFunctionRestart([this]() {
        _graph->setScene(arc::IGraphical::GAME);
        _game->restart();
    });
}

void arc::Core::playArcade()
{
    while (_graph->getEventType() != Event::QUIT && _graph->getKeyPressed() != Event::Key::ESCAPE) {
        if (!_nextGraphPath.empty()) {
            setGraphical(_nextGraphPath);
            _nextGraphPath = "";
        }
        if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::NUM0)
            setNextGraphical();
        if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::NUM1)
            setPrevGraphical();

        // if scene game
        if (_graph->getScene() == arc::IGraphical::GAME) {
            if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::NUM9)
                setNextGame();
            else if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::NUM2)
                setPrevGame();
            else if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::PAUSE) {
                _pause = !_pause;
                _graph->setGamePause(_pause);
            } else if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::R) {
                _game->restart();
            } else if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::M) {
                _graph->setScene(arc::IGraphical::MAIN_MENU);
                _game->restart();
            }
            if (_game->isGameOver()) {
                _pathScoreFile = "." + _game->getTitle();
                Score score(_pathScoreFile);
                if (!_graph->getUsername().empty()) {
                    score.insertScore(_graph->getUsername(), _game->getScore());
                }
                _graph->setScores(score.getScores());
                _graph->setScene(arc::IGraphical::END_GAME);
            } else if (!_pause) {
                _game->updateGame();
                _graph->updateGameInfo(_game->getEntities());
            }
            _graph->setGameStats(_game->getGameStats());
        }
        _graph->display();
    }
    _graph.reset();
    _game.reset();
}


//PRIVATE

const std::string arc::Core::getLibName(const std::string &path)
{
    std::string tmp = path.substr(path.find("lib_arcade_"), path.length());

    tmp = tmp.substr(11, tmp.size() - 14);
    return (tmp);
}
