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

arc::Core::Core(const std::string &libname)
try {
    _games.clear();
    _graphs.clear();
    initGraphs();
    initGames();
    setGraphical(libname);
} catch(const DlError &e) {
    throw e;
} catch(const DirectoryError &e) {
    throw e;
}

arc::Core::~Core()
{
}

void arc::Core::clean()
{
}

void arc::Core::functionPlay()
{
    _graph->setGameTitle(_game->getTitle());
    _graph->setControls(_game->getControls());
    _graph->setMapSize(_game->getMapHeight(), _game->getMapWidth());
    _graph->setGameStats(_game->getGameStats());
    _graph->setHowToPlay(_game->getGameControls());
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
    while (_graph->getEventType() != Event::QUIT) {
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
            if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::NUM2)
                setNextGame();
            if (_game->isGameOver()) {
                _pathScoreFile = "." + _game->getTitle();
                if (!_graph->getUsername().empty())
                    insertScore(_graph->getUsername(), _game->getScore());
                _graph->setScores(getScores());
                _graph->setScene(arc::IGraphical::END_GAME);
            } else {
                _game->updateGame();
                _graph->updateGameInfo(_game->getEntities());
            }
        }
        _graph->display();
    }
}


//PRIVATE

const std::string arc::Core::getLibName(const std::string &path)
{
    std::string tmp = path.substr(path.find("lib_arcade_"), path.length());

    tmp = tmp.substr(11, tmp.size() - 14);
    return (tmp);
}
