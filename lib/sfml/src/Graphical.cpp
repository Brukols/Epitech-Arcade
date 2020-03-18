/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Graphcial
*/

#include <iostream>
#include "sfml/Graphical.hpp"
#include "Utils.hpp"
#include <iostream>
#include "sfml/SceneMenu.hpp"
#include "sfml/SceneGame.hpp"

arc::Graphical::Graphical() : _window(sf::RenderWindow(sf::VideoMode(1920, 1080, 32), "Arcade", sf::Style::Fullscreen))
{
    _window.setFramerateLimit(60);
    _scenes[MAIN_MENU] = std::unique_ptr<IScene>(new SceneMenu());
    _scenes[GAME] = std::unique_ptr<IScene>(new SceneGame());
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setFunctionExit([this]() {
        _exit = true;
    });
    static_cast<SceneGame *>(_scenes[GAME].get())->eventFunctionBackToMenu([this]() {
        setScene(MAIN_MENU);
    });
}

arc::Graphical::~Graphical()
{
}

void arc::Graphical::setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setListGames(games, fct, chosen);
}

void arc::Graphical::setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen)
{
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setListLibraries(libraries, fct, chosen);
}

void arc::Graphical::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _scores = scores;
}

void arc::Graphical::setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->setControls(controls);
}

void arc::Graphical::setFunctionPlay(const std::function<void()> &function)
{
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setFunctionPlay(function);
}

void arc::Graphical::setFunctionRestart(const std::function<void()> &function)
{
    _eventRestartButton = function;
}

void arc::Graphical::setFunctionMenu(const std::function<void()> &function)
{
    _eventMenuButton = function;
}

void arc::Graphical::setFunctionTogglePause(const std::function<void()> &function)
{
    _eventTogglePauseButton = function;
}

const std::string &arc::Graphical::getUsername()
{
    return (static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->getUsername());
}

void arc::Graphical::setUsername(const std::string &name)
{
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setUsername(name);
}

arc::IGraphical::Scene arc::Graphical::getScene() const
{
    return (_actualScene);
}

void arc::Graphical::setScene(Scene scene)
{
    _actualScene = scene;
    _scenes[_actualScene].get()->init();
}

void arc::Graphical::setHowToPlay(const std::vector<std::pair<std::string, std::string>> &info)
{
    _infoHowToPlay = info;
}

void arc::Graphical::setGameStatsFormatString(const std::vector<std::string> &info)
{
    _infoGameStat = info;
}

void arc::Graphical::setFont(const std::string &font)
{
    if (!_font.loadFromFile(font))
        return; // Throw a exeception
}

void arc::Graphical::setVisualAssets(const std::map<char, std::pair<std::string, Color>> &sprites)
{
    (void)sprites;
}

void arc::Graphical::updateGameInfo(const std::vector<std::shared_ptr<Entity>> &gameMap)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->updateGameInfo(gameMap);
}

void arc::Graphical::setMapSize(size_t height, size_t width)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->setMapSize(height, width);
}

void arc::Graphical::setGameTitle(const std::string &game)
{
    (void)game;
}

extern "C" arc::IGraphical *instance_ctor()
{
    return (new arc::Graphical());
}
