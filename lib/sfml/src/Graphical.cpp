/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Graphcial
*/

#include <iostream>
#include "Graphical.hpp"
#include "Utils.hpp"
#include <iostream>
#include "SceneMenu.hpp"

arc::Graphical::Graphical() : _window(sf::RenderWindow(sf::VideoMode(1920, 1080, 32), " window", sf::Style::Fullscreen))
{
    _window.setFramerateLimit(60);
    _scenes[MAIN_MENU] = std::unique_ptr<IScene>(new SceneMenu());
    dynamic_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setFunctionExit([this]() {
        _exit = true;
    });
}

arc::Graphical::~Graphical()
{
}

void arc::Graphical::setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    dynamic_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setListGames(games, fct, chosen);
}
#include <iostream>
void arc::Graphical::setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen)
{
    dynamic_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setListLibraries(libraries, fct, chosen);
}

void arc::Graphical::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _scores = scores;
}

void arc::Graphical::setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls)
{
    _controls = controls;
}

void arc::Graphical::setFunctionPlay(const std::function<void()> &function)
{
    dynamic_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setFunctionPlay(function);
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

const std::string &arc::Graphical::getUsername() const
{
    return (_username);
}

arc::IGraphical::Scene arc::Graphical::getScene() const
{
    return (_actualScene);
}

void arc::Graphical::setScene(Scene scene)
{
    _actualScene = scene;
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

void arc::Graphical::setSprites(const std::map<char, std::string> &sprites)
{
    _sprites = sprites;
}

void arc::Graphical::setBackgroundColors(const std::map<char, Color> &backgroundColors)
{
    _backgroundColors = backgroundColors;
}

void arc::Graphical::updateGameInfo(const std::vector<Entity> &entities)
{
    _entities = entities;
}

extern "C" arc::IGraphical *instance_ctor()
{
    return (new arc::Graphical());
}
