/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreSetGraphical
*/

#include "Core.hpp"
#include <filesystem>

const std::vector<std::string> arc::Core::getNamesSharedGraphs()
{
    std::vector<std::string> vector;

    std::for_each(_graphs.begin(), _graphs.end(), [this, &vector](const std::pair<std::string, std::unique_ptr<DLLoader<IGraphical>>> &pair) {
        vector.push_back(pair.first);
    });
    return (vector);
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
    _graph->setListLibraries(getNamesSharedGraphs(), [this](const std::string &name) {
        _nextGraphPath = name;
    }, _indexGraph);
    _graph->setListGames(getNamesSharedGames(), [this](const std::string &name) {
        setGame(name);
        _pathScoreFile = "." + _game->getTitle();
        _graph->setScores(getScores());
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
    _graph.reset();
    _graph = std::unique_ptr<IGraphical>(_graphs[_indexGraph].second.get()->getInstance());
    _graph->setListLibraries(getNamesSharedGraphs(), [this](const std::string &name) {
        _nextGraphPath = name;
    }, _indexGraph);
    _graph->setListGames(getNamesSharedGames(), [this](const std::string &name) {
        setGame(name);
        _pathScoreFile = "." + _game->getTitle();
        _graph->setScores(getScores());
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

void arc::Core::setGraphical(const std::string &libname)
{
    int i = 0;
    std::string username = (_graph ? _graph.get()->getUsername() : "");

    _indexGraph = -1;
    std::for_each(_graphs.begin(), _graphs.end(), [this, &libname, &i, &username](const std::pair<std::string, std::unique_ptr<DLLoader<IGraphical>>> &pair) {
        if (getLibName(pair.first) == getLibName(libname)) {
            _graph.reset();
            _graph = std::unique_ptr<IGraphical>(pair.second.get()->getInstance());
            _graph->setListLibraries(getNamesSharedGraphs(), [this](const std::string &name) {
                _nextGraphPath = name;
            }, i);
            _graph->setListGames(getNamesSharedGames(), [this](const std::string &name) {
                setGame(name);
                _pathScoreFile = "." + _game->getTitle();
                _graph->setScores(getScores());
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
            _pathScoreFile = "." + _game->getTitle();
            _graph->setScores(getScores());
        }, -1);
        _graph->setFunctionPlay([this]() {
            if (_game)
                functionPlay();
        });
        _indexGraph = 0;
    }
}