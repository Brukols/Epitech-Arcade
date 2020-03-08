/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLGraphcial
*/

#include "SFMLGraphical.hpp"
#include "Utils.hpp"
#include <iostream>

arc::SFMLGraphical::SFMLGraphical() : _window(sf::RenderWindow(sf::VideoMode(1920, 1080, 32), "SFML window", sf::Style::Fullscreen))
{
    initButtons();
}

arc::SFMLGraphical::~SFMLGraphical()
{
}

void arc::SFMLGraphical::setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    _listGames = games;
    _eventChooseGame = fct;
    (void)chosen;
}

void arc::SFMLGraphical::setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen)
{
    _listLibraries = libraries;
    _eventChooseLibrary = fct;
    (void)chosen;
}

void arc::SFMLGraphical::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _scores = scores;
}

void arc::SFMLGraphical::setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls)
{
    _controls = controls;
}

void arc::SFMLGraphical::setFunctionPlay(const std::function<void()> &function)
{
    _eventPlayButton = function;
}

void arc::SFMLGraphical::setFunctionRestart(const std::function<void()> &function)
{
    _eventRestartButton = function;
}

void arc::SFMLGraphical::setFunctionMenu(const std::function<void()> &function)
{
    _eventMenuButton = function;
}

void arc::SFMLGraphical::setFunctionTogglePause(const std::function<void()> &function)
{
    _eventTogglePauseButton = function;
}

const std::string &arc::SFMLGraphical::getUsername() const
{
    return (_username);
}

arc::IGraphical::Scene arc::SFMLGraphical::getScene() const
{
    return (_actualScene);
}

void arc::SFMLGraphical::setScene(Scene scene)
{
    _actualScene = scene;
}

void arc::SFMLGraphical::setHowToPlay(const std::vector<std::pair<std::string, std::string>> &info)
{
    _infoHowToPlay = info;
}

void arc::SFMLGraphical::setGameStatsFormatString(const std::vector<std::string> &info)
{
    _infoGameStat = info;
}

void arc::SFMLGraphical::setFont(const std::string &font)
{
    if (!_font.loadFromFile(font))
        return; // Throw a exeception
}

void arc::SFMLGraphical::setSprites(const std::map<char, std::string> &sprites)
{
    _sprites = sprites;
}

void arc::SFMLGraphical::setBackgroundColors(const std::map<char, Color> &backgroundColors)
{
    _backgroundColors = backgroundColors;
}

void arc::SFMLGraphical::updateGameInfo(const std::vector<Entity> &entities)
{
    _entities = entities;
}

extern "C" arc::IGraphical *instance_ctor()
{
    return (new arc::SFMLGraphical());
}
