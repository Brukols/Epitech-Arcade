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

void Nibbler::restart()
{
    initNibbler();
}

void Nibbler::updateGame()
{
    std::shared_ptr<Entity> bodySnake(new Entity);
    if (doYouEat() == true) {
        _score += 1;
        std::shared_ptr<Entity> tmp = _snake.back();
        bodySnake->spritePath = "";
        bodySnake->orientation = tmp->orientation;
        bodySnake->backgroundColor = tmp->backgroundColor;
        if (bodySnake->orientation == Orientation::UP) {
            bodySnake->x = tmp->x;
            bodySnake->y = tmp->y - 1;
        } else if (bodySnake->orientation == Orientation::RIGHT) {
            bodySnake->x = tmp->x -1;
            bodySnake->y = tmp->y;
        } else if (bodySnake->orientation == Orientation::LEFT) {
            bodySnake->x = tmp->x + 1;
            bodySnake->y = tmp->y;
        } else if (bodySnake->orientation == Orientation::DOWN) {
            bodySnake->x = tmp->x;
            bodySnake->y = tmp->y + 1;
        }
    }
    //manger
    //agrandir le snake

    //initialisation de sound si le serpent mange quelque chose.
    //mise à jour orientation snake
}

bool Nibbler::doYouEat()
{
    auto const &ptr = std::find_if(_apple.begin(), _apple.end(), [this] (std::shared_ptr<Entity> &p) {
        if ((p->x == _snake.front()->x) && (p->y == _snake.front()->y)) {
            return true;
        }
        return false;
    });
    if (ptr == _snake.end())
        return false;
    _apple.erase(ptr);
    return true;
}

bool Nibbler::isGameOver() const
{
    //Une partie du serpent touche un bord
}