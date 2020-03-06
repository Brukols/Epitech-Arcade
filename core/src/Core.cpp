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

// PUBLIC

arc::Core::Core(const std::string &libname)
try {
    initGraphs();
    initGames();
    DLLoader<IGraphical> loader(libname);

    _graph = std::unique_ptr<IGraphical>(loader.getInstance());
} catch(const DlError &e) {
    throw e;
}

arc::Core::~Core()
{
}

void arc::Core::playArcade()
{
}


//PRIVATE

void arc::Core::initGraphs() noexcept
{
    for (const auto &entry : std::filesystem::directory_iterator("./lib")) {
        std::string path = entry.path();

        if (path.find("./lib/lib_arcade_") != 0)
            continue;
        if (path.substr(path.find_last_of(".") + 1) != "so")
            continue;
        _graphs[path] = false;
    }
}

void arc::Core::initGames() noexcept
{
    for (const auto &entry : std::filesystem::directory_iterator("./games")) {
        std::string path = entry.path();

        if (path.find("./games/lib_arcade_") != 0)
            continue;
        if (path.substr(path.find_last_of(".") + 1) != "so")
            continue;
        _games[path] = false;
    }
}

void arc::Core::changeGame(const std::string &name)
{
    try {
        DLLoader<IGame> loader(name);

        _game = std::unique_ptr<IGame>(loader.getInstance());
    } catch(const DlError &e) {
        throw e;
    }
}

void arc::Core::changeGraphical(const std::string &name)
{
    try {
        DLLoader<IGraphical> loader(name);

        _graph = std::unique_ptr<IGraphical>(loader.getInstance());
    } catch(const DlError &e) {
        throw e;
    }
}