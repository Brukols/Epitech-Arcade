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
    _graph->setVisualAssets(_game->getVisualAssets());
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
        if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::E)
            setNextGraphical();
        if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::R)
            setPrevGraphical();
        if (_graph->getScene() == arc::IGraphical::GAME) {
            if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::A)
                setNextGame();
            if (_graph->getEventType() == Event::Type::KEY_PRESSED && _graph->getKeyPressed() == Event::Key::Z)
                setNextGame();
            _game->updateGame();
            _graph->updateGameInfo(_game->getEntities());
        }
        _graph->display();
    }
}

void arc::Core::setNextGame()
{
    _indexGame++;
    if (_indexGame == static_cast<int>(_games.size()))
        _indexGame = 0;
    _game = std::unique_ptr<IGame>(_games[_indexGame].second.get()->getInstance());
    _graph->setControls(_game->getControls());
    // _graph->setFont(_game->getFont());
    _graph->setVisualAssets(_game->getVisualAssets());
    _graph->setMapSize(_game->getMapHeight(), _game->getMapWidth());
    _graph->setFunctionMenu([this]() {});
    _graph->setScene(arc::IGraphical::GAME);
}

void arc::Core::setPrevGame()
{
    _indexGame--;
    if (_indexGame == -1)
        _indexGame = _games.size() - 1;
    _game = std::unique_ptr<IGame>(_games[_indexGame].second.get()->getInstance());
    _graph->setControls(_game->getControls());
    // _graph->setFont(_game->getFont());
    _graph->setVisualAssets(_game->getVisualAssets());
    _graph->setMapSize(_game->getMapHeight(), _game->getMapWidth());
    _graph->setFunctionMenu([this]() {});
    _graph->setScene(arc::IGraphical::GAME);
}

void arc::Core::setNextGraphical()
{
    IGraphical::Scene scene = _graph.get()->getScene();
    std::string username = _graph.get()->getUsername();

    _indexGraph++;
    if (_indexGraph == static_cast<int>(_graphs.size())) {
        _indexGraph = 0;
    }
    _graph = std::unique_ptr<IGraphical>(_graphs[_indexGraph].second.get()->getInstance());
    _graph->setListLibraries(getNamesSharedGraphs(), [this](const std::string &name) {
        _nextGraphPath = name;
    }, _indexGraph);
    _graph->setListGames(getNamesSharedGames(), [this](const std::string &name) {
        setGame(name);
    }, _indexGame);
    _graph->setFunctionPlay([this]() {
        if (_game)
            functionPlay();
    });
    if (scene == IGraphical::GAME) {
        functionPlay();
    }
    _graph.get()->setScene(scene);
    _graph.get()->setUsername(username);
}

void arc::Core::setPrevGraphical()
{
    IGraphical::Scene scene = _graph.get()->getScene();
    std::string username = _graph.get()->getUsername();

    _indexGraph--;
    if (_indexGraph == -1) {
        _indexGraph = _graphs.size() - 1;
    }
    _graph = std::unique_ptr<IGraphical>(_graphs[_indexGraph].second.get()->getInstance());
    _graph->setListLibraries(getNamesSharedGraphs(), [this](const std::string &name) {
        _nextGraphPath = name;
    }, _indexGraph);
    _graph->setListGames(getNamesSharedGames(), [this](const std::string &name) {
        setGame(name);
    }, _indexGame);
    _graph->setFunctionPlay([this]() {
        if (_game)
            functionPlay();
    });
    if (scene == IGraphical::GAME) {
        functionPlay();
    }
    _graph.get()->setScene(scene);
    _graph.get()->setUsername(username);
}


//PRIVATE

const std::vector<std::string> arc::Core::getNamesSharedGraphs()
{
    std::vector<std::string> vector;

    std::for_each(_graphs.begin(), _graphs.end(), [this, &vector](const std::pair<std::string, std::unique_ptr<DLLoader<IGraphical>>> &pair) {
        vector.push_back(pair.first);
    });
    return (vector);
}

const std::vector<std::string> arc::Core::getNamesSharedGames()
{
    std::vector<std::string> vector;

    std::for_each(_games.begin(), _games.end(), [this, &vector](const std::pair<std::string, std::unique_ptr<DLLoader<IGame>>> &pair) {
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
            try {
                _graphs.push_back(std::pair<std::string, std::unique_ptr<DLLoader<IGraphical>>>(path, new DLLoader<IGraphical>(path)));
            } catch(...) {}
        }
    } catch(const std::exception& e) {
        throw DirectoryError("Directory lib does not exist", "initGraphs");
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
            try {
                _games.push_back(std::pair<std::string, std::unique_ptr<DLLoader<IGame>>>(path, new DLLoader<IGame>(path)));
            } catch(...) {}
        }
    } catch(const std::exception& e) {
        throw DirectoryError("Directory games does not exist", "initGames");
    }
}

void arc::Core::setGame(const std::string &libname)
{
    int i = 0;

    _indexGame = -1;
    std::for_each(_games.begin(), _games.end(), [this, &libname, &i](const std::pair<std::string, std::unique_ptr<DLLoader<IGame>>> &pair) {
        if (getLibName(pair.first) == getLibName(libname)) {
            _game = std::unique_ptr<IGame>(pair.second.get()->getInstance());
            _indexGame = i;
        }
        i++;
    });
    if (_indexGame == -1)
        throw ArcadeError("Unable to found the game", "setGame");
}

void arc::Core::setGraphical(const std::string &libname)
{
    int i = 0;
    std::string username = (_graph ? _graph.get()->getUsername() : "");

    _indexGraph = -1;
    std::for_each(_graphs.begin(), _graphs.end(), [this, &libname, &i, &username](const std::pair<std::string, std::unique_ptr<DLLoader<IGraphical>>> &pair) {
        if (getLibName(pair.first) == getLibName(libname)) {
            _graph = std::unique_ptr<IGraphical>(pair.second.get()->getInstance());
            _graph->setListLibraries(getNamesSharedGraphs(), [this](const std::string &name) {
                _nextGraphPath = name;
            }, i);
            _graph->setListGames(getNamesSharedGames(), [this](const std::string &name) {
                setGame(name);
            }, _indexGame);
            _graph->setFunctionPlay([this]() {
                if (_game)
                    functionPlay();
            });
            _graph->setUsername(username);
            _indexGraph = i;
        }
        i++;
    });
    if (_indexGraph == -1) {
        _initialGraph = std::unique_ptr<DLLoader<IGraphical>>(new DLLoader<IGraphical>(libname));
        _graph = std::unique_ptr<IGraphical>(_initialGraph.get()->getInstance());
        _graph->setListLibraries(getNamesSharedGraphs(), [this](const std::string &name) {
            _nextGraphPath = name;
        }, -1);
        _graph->setListGames(getNamesSharedGames(), [this](const std::string &name) {
            setGame(name);
        }, -1);
        _graph->setFunctionPlay([this]() {
            if (_game)
                functionPlay();
        });
        _indexGraph = 0;
    }
}