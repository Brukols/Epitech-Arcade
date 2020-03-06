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

// PUBLIC

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

void arc::Core::playArcade()
{
    while (_graph.get()->getKeyPressed() == Event::ESCAPE) {
        _graph.get()->display();
    }
}


//PRIVATE

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
{
    try {
        DLLoader<IGame> loader(libname);

        _game = std::unique_ptr<IGame>(loader.getInstance());
    } catch(const DlError &e) {
        throw e;
    }
} 

void arc::Core::setGraphical(const std::string &libname)
{
    try {
        DLLoader<IGraphical> loader(libname);

        _graph = std::unique_ptr<IGraphical>(loader.getInstance());
    } catch(const DlError &e) {
        throw e;
    }
}