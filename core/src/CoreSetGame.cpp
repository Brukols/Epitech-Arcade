/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreSetGame
*/

#include "Core.hpp"
#include <filesystem>
#include "Folder.hpp"

const std::vector<std::string> arc::Core::getNamesSharedGames()
{
    std::vector<std::string> vector;

    std::for_each(_games.begin(), _games.end(), [this, &vector](const std::pair<std::string, std::unique_ptr<DLLoader<IGame>>> &pair) {
        vector.push_back(pair.first);
    });
    return (vector);
}

void arc::Core::setNextGame()
{
    _indexGame++;
    if (_indexGame == static_cast<int>(_games.size()))
        _indexGame = 0;
    _game = std::unique_ptr<IGame>(_games[_indexGame].second.get()->getInstance());
    functionPlay();
}

void arc::Core::setPrevGame()
{
    _indexGame--;
    if (_indexGame == -1)
        _indexGame = _games.size() - 1;
    _game = std::unique_ptr<IGame>(_games[_indexGame].second.get()->getInstance());
    functionPlay();
}

void arc::Core::initGames()
{
    Folder folder;
    std::vector<std::string> names;
    
    try {
        names = folder.getFilesFolder("./games");
    } catch(const DirectoryError &e) {
        throw e;
    }
    _games.clear();
    std::for_each(names.begin(), names.end(), [this](const std::string &name) {
        if (name.find("./games/lib_arcade_") != 0)
            return;
        if (name.substr(name.find_last_of(".") + 1) != "so")
            return;
        try {
            _games.push_back(std::pair<std::string, std::unique_ptr<DLLoader<IGame>>>(getLibName(name), new DLLoader<IGame>(name)));
        } catch(...) {}
    });
}

void arc::Core::setGame(const std::string &libname)
{
    int i = 0;

    _indexGame = -1;
    std::for_each(_games.begin(), _games.end(), [this, &libname, &i](const std::pair<std::string, std::unique_ptr<DLLoader<IGame>>> &pair) {
        if (pair.first == libname) {
            _game = std::unique_ptr<IGame>(pair.second.get()->getInstance());
            _indexGame = i;
        }
        i++;
    });
    if (_indexGame == -1)
        throw ArcadeError("Unable to found the game", "setGame");
}
