/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLGraphcial
*/

#include "SFMLGraphical.hpp"
#include "Utils.hpp"
#include <iostream>

arc::SFMLGraphical::SFMLGraphical()
{
    _window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window"));
}

arc::SFMLGraphical::~SFMLGraphical()
{
}

size_t arc::SFMLGraphical::getScreenWidth() const
{
    return (0);
}

size_t arc::SFMLGraphical::getScreenHeight() const
{
    return (0);
}

void arc::SFMLGraphical::setScene(Scene scene)
{
    _actualScene = scene;
}

arc::IGraphical::Scene arc::SFMLGraphical::getScene() const
{
    return (_actualScene);
}

void arc::SFMLGraphical::setMainMenuOptions(const std::map<std::string, std::function<void()>> &mainMenu)
{
    _mainMenuOptions = mainMenu;
}

void arc::SFMLGraphical::setPauseMenuOptions(const std::map<std::string, std::function<void()>> &pauseMenu)
{
    _pauseMenuOptions = pauseMenu;
}

void arc::SFMLGraphical::setList(const std::vector<std::string> &list)
{
    (void)list;
}

void arc::SFMLGraphical::setGetInputMessage(const std::string &message)
{
    (void)message;
}

void arc::SFMLGraphical::setEndGameMessage(const std::string &message)
{
    (void)message;
}

void arc::SFMLGraphical::updateGameInfo(const std::vector<std::vector<char>> &gameMap)
{
    (void)gameMap;
}

const std::string &arc::SFMLGraphical::getInput() const
{
    return (_test);
}

void arc::SFMLGraphical::setSprites(const std::map<char, std::string> &sprites)
{
    (void)sprites;
}

void arc::SFMLGraphical::setBackgroundColors(const std::map<char, Color> &sprites)
{
    (void)sprites;
}

void arc::SFMLGraphical::setFont(const std::string &font)
{
    if (!_font.loadFromFile(font))
        return; // Throw a exeception
}

void arc::SFMLGraphical::setGameStatsFormatString(const std::string &info)
{
    (void)info;
}

void arc::SFMLGraphical::setHowToPlayFormatString(const std::string &info)
{
    (void)info;
}

extern "C" arc::IGraphical *instance_ctor()
{
    return (new arc::SFMLGraphical());
}
