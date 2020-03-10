/*
** EPITECH PROJECT, 2019
** Arcade - Nibbler
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
{
    _height = 10;
    _width = 10;
    initControls();
    initEntities();
}
Nibbler::~Nibbler()
{
}

size_t Nibbler::getMapHeight() const
{
    return _height;
}

size_t arc::Nibbler::getMapWidth() const
{
    return _width;
}

const std::string &Nibbler::getFont() const
{
    return _font;
}

const std::string &Nibbler::getMusic() const
{
    return _music;
}

const std::string &Nibbler::getSound() const
{
    return _sound;
}

const std::string &Nibbler::getScore()
{
    _strScore = std::to_string(_score);
    return _strScore;
}

const std::map<char, std::pair<std::string, Color>> &Nibbler::getVisualAssets() const
{
    return _visualAssets;
}

const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &Nibbler::getControls() const
{
    return _controls;
}

const std::vector<Entity> &Nibbler::getEntities() const
{
    return _entities;
}

const std::vector<std::pair<std::string, std::string>> &Nibbler::getGameControlsFormatString() const
{
    return _gameControls;
}

const std::vector<std::string> &Nibbler::getGameStatsFormatString() const
{
    return _gameStats;
}

void Nibbler::restart()
{
    initControls();
    initEntities();
}

void Nibbler::updateGame()
{
    //initialisation de sound si le serpent mange quelque chose.
}

bool Nibbler::isGameOver() const
{
}