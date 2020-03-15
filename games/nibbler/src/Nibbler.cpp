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

void Nibbler::restart()
{
    initNibbler();
}

void Nibbler::updateGame()
{
    _end = std::chrono::system_clock::now();
    // manageClock();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 200) {
        _start = std::chrono::system_clock::now();
        // updateOrientationSnake();
        moveSnake();
    }
    //mise à jour orientation snake   //clock
}

bool Nibbler::doYouEat()
{
    auto const &ptr = std::find_if(_entities.begin(), _entities.end(), [this] (std::shared_ptr<Entity> &p) {
        for (size_t i = 0; i < _apple.size(); i++) {
            if (p == _apple[i]) {
                if ((p->x == _snake.front()->x) && (p->y == _snake.front()->y)) {
                    return true;
                }
            }
        }
        return false;
    });
    if (ptr == _entities.end())
        return false;
    _entities.erase(ptr);
    _apple.clear();
    return true;
}

void Nibbler::updateOrientationSnake()
{
    int i = 0;

    for (i = _snake.size() - 1; i > 0; i--) {
        _snake[i]->orientation = _snake[i - 1]->orientation;
    }
}

bool Nibbler::isGameOver() const
{
    //Une partie du serpent touche un bord
}

extern "C" arc::IGame *instance_ctor()
{
    return (new arc::Nibbler());
}
