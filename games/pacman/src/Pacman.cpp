/*
** EPITECH PROJECT, 2019
** Arcade - Pacman
** File description:
** Pacman
*/

#include "Pacman.hpp"

Pacman::Pacman()
{
    initPacman();
}

Pacman::~Pacman()
{
}

size_t Pacman::getMapHeight() const
{
    return _height;
}

size_t arc::Pacman::getMapWidth() const
{
    return _width;
}

const std::string &Pacman::getMusic() const
{
    return _music;
}

const std::string &Pacman::getSound() const
{
    return _sound;
}

const std::string &Pacman::getScore()
{
    _strScore = std::to_string(_score);
    return _strScore;
}

const std::map<char, std::pair<std::string, Color>> &Pacman::getVisualAssets() const
{
    return _visualAssets;
}

const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &Pacman::getControls() const
{
    return _controls;
}

const std::vector<std::shared_ptr<Entity>> &Pacman::getEntities() const
{
    return _entities;
}

const std::vector<std::pair<std::string, std::string>> &Pacman::getGameControlsFormatString() const
{
    return _gameControls;
}

const std::vector<std::string> &Pacman::getGameStatsFormatString() const
{
    return _gameStats;
}

const std::string &Pacman::getTitle() const
{
    return _title;
}

extern "C" arc::IGame *instance_ctor()
{
    return (new arc::Pacman());
}
