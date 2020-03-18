/*
** EPITECH PROJECT, 2019
** Arcade - Nibbler
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

Nibbler::Nibbler()
{
    initNibbler();
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

const std::vector<std::shared_ptr<Entity>> &Nibbler::getEntities() const
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

const std::string &Nibbler::getTitle() const
{
    return _title;
}

extern "C" arc::IGame *instance_ctor()
{
    return (new arc::Nibbler());
}
