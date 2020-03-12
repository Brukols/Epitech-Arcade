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
#include <filesystem>
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
    // _graph->setMusic(_game->getMusic());
    _graph->setVisualAssets(_game->getVisualAssets());
    _graph->setScene(arc::IGraphical::GAME);
    _graph->setFunctionMenu([this]() {
        playArcade();
    });
    while (_graph->getEventType() != Event::QUIT) {
        // _graph->updateGameInfo(_game->getEntities());
        _graph->display();
    }
}

void arc::Core::playArcade()
{
    _graph->setListLibraries(getNamesSharedLib(_graphs), [this](const std::string &name) {
        (void)name;
    }, -1);
    _graph->setListGames(getNamesSharedLib(_games), [this](const std::string &name) {
        setGame(name);
    }, -1);
    _graph->setFunctionPlay([this]() {
        functionPlay();
    });

    while (_graph->getEventType() != Event::QUIT) {
        _graph->display();
    }
}


//PRIVATE

const std::vector<std::string> arc::Core::getNamesSharedLib(const std::map<std::string, bool> &map)
{
    std::vector<std::string> vector;

    std::for_each(map.begin(), map.end(), [&vector, this](const std::pair<std::string, bool> &pair) {
        vector.push_back(pair.first);
    });
    return (vector);
}

const std::string arc::Core::getLibName(const std::string &path)
{
    std::string tmp = path.substr(path.find("lib_arcade_"), path.length());

    tmp = tmp.substr(11, tmp.size() - 14);
    return (tmp);
}

void arc::Core::initGraphs()
{
    try {
        for (const auto &entry : std::filesystem::directory_iterator("./lib")) {
            std::string path = entry.path();

            if (path.find("./lib/lib_arcade_") != 0)
                continue;
            if (path.substr(path.find_last_of(".") + 1) != "so")
                continue;
            _graphs[path] = false;
        }
    } catch(const std::exception& e) {
        throw DirectoryError("Direcory lib does not exist", "initGraphs");
    }
}

void arc::Core::initGames()
{
    try {
        for (const auto &entry : std::filesystem::directory_iterator("./games")) {
            std::string path = entry.path();

            if (path.find("./games/lib_arcade_") != 0)
                continue;
            if (path.substr(path.find_last_of(".") + 1) != "so")
                continue;
            _games[path] = false;
        }
    } catch(const std::exception& e) {
        throw DirectoryError("Direcory games does not exist", "initGames");
    }
}

void arc::Core::changeGame(Direction direction)
{
    std::string prev;
    bool changeNext = false;

    for (auto const &[key, val] : _games) {
        if (val == false && changeNext != true) {
            prev = key;
            continue;
        }
        if (changeNext == true)
            prev = key;
        changeNext = false;
        if (direction == NEXT) {
            changeNext = true;
            _games[key] = false;
            continue;
        }
        _games[prev] = true;
        setGame(prev);
    }
}

void arc::Core::changeGraphical(Direction direction)
{
    std::string prev;
    bool changeNext = false;

    for (auto const &[key, val] : _games) {
        if (val == false && changeNext != true) {
            prev = key;
            continue;
        }
        if (changeNext == true)
            prev = key;
        changeNext = false;
        if (direction == NEXT) {
            changeNext = true;
            _games[key] = false;
            continue;
        }
        _graphs[prev] = true;
        setGraphical(prev);
    }
}

void arc::Core::setGame(const std::string &libname)
try {
    _loaderGame = std::unique_ptr<DLLoader<IGame>>(new DLLoader<IGame>(libname));
    _game = std::unique_ptr<IGame>(_loaderGame.get()->getInstance());
} catch(const DlError &e) {
    throw e;
}

void arc::Core::setGraphical(const std::string &libname)
try {
    _loaderGraph = std::unique_ptr<DLLoader<IGraphical>>(new DLLoader<IGraphical>(libname));
    _graph = std::unique_ptr<IGraphical>(_loaderGraph.get()->getInstance());
} catch(const DlError &e) {
    throw e;
}