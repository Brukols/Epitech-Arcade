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

void arc::Core::functionPlay()
{
    _graph->setControls(_game->getControls());
    // _graph->setFont(_game->getFont());
    _graph->setMapSize(_game->getMapHeight(), _game->getMapWidth());
    _graph->setScene(arc::IGraphical::GAME);
    _graph->setFunctionMenu([this]() {});
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
        if (_graph->getScene() == arc::IGraphical::GAME) {
            if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::NUM9)
                setNextGame();
            if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::NUM2)
                setNextGame();
            if (_game->isGameOver()) {
                std::cout << "hello" << std::endl;
                insertScore(_graph->getUsername(), _game->getScore());
                _game->restart();
            }
            _game->updateGame();
            _graph->updateGameInfo(_game->getEntities());
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
