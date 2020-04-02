/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreSetGraphical
*/

#include "Core.hpp"
#include <filesystem>
#include "Folder.hpp"
#include "Score.hpp"

const std::vector<std::string> arc::Core::getNamesSharedGraphs()
{
    std::vector<std::string> vector;

    std::for_each(_graphs.begin(), _graphs.end(), [this, &vector](const std::pair<std::string, std::unique_ptr<DLLoader<IGraphical>>> &pair) {
        vector.push_back(pair.first);
    });
    return (vector);
}

void arc::Core::initGraphical(const std::string &username, IGraphical::Scene scene)
{
    if (_indexGame != -1) {
        _pathScoreFile = "." + _game->getTitle();
        Score score(_pathScoreFile);
        _graph->setScores(score.getScores());
        _graph->setGameTitle(_game->getTitle());
        _graph->setControls(_game->getControls());
        _graph->setMapSize(_game->getMapHeight(), _game->getMapWidth());
        _graph->setGameStats(_game->getGameStats());
        _graph->setGamePause(_pause);
    }
    _graph->setHowToPlay(getControls());
    _graph->setListLibraries(getNamesSharedGraphs(), [this](const std::string &name) {
        _nextGraphPath = name;
    }, _indexGraph);
    _graph->setListGames(getNamesSharedGames(), [this](const std::string &name) {
        setGame(name);
        _pathScoreFile = "." + _game->getTitle();
        Score score(_pathScoreFile);
        _graph->setScores(score.getScores());
        _graph->setHowToPlay(getControls());
    }, _indexGame);
    _graph->setFunctionPlay([this]() {
        if (_game)
            functionPlay();
    });
    _graph->setFunctionTogglePause([this]() {
        _pause = !_pause;
        _graph->setGamePause(_pause);
    });
    _graph->setFunctionMenu([this]() {
        _graph->setScene(arc::IGraphical::MAIN_MENU);
        _game->restart();
    });
    _graph->setFunctionRestart([this]() {
        _graph->setScene(arc::IGraphical::GAME);
        _game->restart();
    });
    if (scene == IGraphical::GAME) {
        functionPlay();
    }
    _graph.get()->setScene(scene);
    _graph.get()->setUsername(username);
}

void arc::Core::initGraphs()
{
    Folder folder;
    std::vector<std::string> names;
    
    try {
        names = folder.getFilesFolder("./lib");
    } catch(const DirectoryError &e) {
        throw e;
    }
    _graphs.clear();
    std::for_each(names.begin(), names.end(), [this](const std::string &name) {
        if (name.find("./lib/lib_arcade_") != 0)
            return;
        if (name.substr(name.find_last_of(".") + 1) != "so")
            return;
        try {
            _graphs.push_back(std::pair<std::string, std::unique_ptr<DLLoader<IGraphical>>>(getLibName(name), new DLLoader<IGraphical>(name)));
        } catch(...) {}
    });
}

void arc::Core::setNextGraphical()
{
    IGraphical::Scene scene = _graph.get()->getScene();
    std::string username = _graph.get()->getUsername();

    _indexGraph++;
    if (_indexGraph == static_cast<int>(_graphs.size())) {
        _indexGraph = 0;
    }
    _graph.reset();
    _graph = std::unique_ptr<IGraphical>(_graphs[_indexGraph].second.get()->getInstance());
    initGraphical(username, scene);
}

void arc::Core::setPrevGraphical()
{
    IGraphical::Scene scene = _graph.get()->getScene();
    std::string username = _graph.get()->getUsername();

    _indexGraph--;
    if (_indexGraph == -1) {
        _indexGraph = _graphs.size() - 1;
    }
    _graph.reset();
    _graph = std::unique_ptr<IGraphical>(_graphs[_indexGraph].second.get()->getInstance());
    initGraphical(username, scene);
}

void arc::Core::setGraphical(const std::string &libname)
{
    int i = 0;
    std::string username = (_graph ? _graph.get()->getUsername() : "");

    _indexGraph = -1;
    std::for_each(_graphs.begin(), _graphs.end(), [this, &libname, &i, &username](const std::pair<std::string, std::unique_ptr<DLLoader<IGraphical>>> &pair) {
        if (pair.first == libname) {
            _graph.reset();
            _graph = std::unique_ptr<IGraphical>(pair.second.get()->getInstance());
            _indexGraph = i;
            initGraphical(username, arc::IGraphical::MAIN_MENU);
        }
        i++;
    });
    if (_indexGraph == -1) {
        _initialGraph = std::unique_ptr<DLLoader<IGraphical>>(new DLLoader<IGraphical>(libname));
        _graph = std::unique_ptr<IGraphical>(_initialGraph.get()->getInstance());
        initGraphical("", arc::IGraphical::MAIN_MENU);
        _indexGraph = 0;
    }
}