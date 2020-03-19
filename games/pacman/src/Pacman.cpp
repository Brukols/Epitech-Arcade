/*
** EPITECH PROJECT, 2019
** Arcade - Pacman
** File description:
** Pacman
*/

#include "Pacman.hpp"

Pacman::Pacman()
{
    initPacmanGame();
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

const std::string &Pacman::getFont() const
{
    return _font;
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

void Pacman::restart()
{
    //initPacman();
}

void Pacman::updateGame()
{
    _end = std::chrono::system_clock::now();
    // manageClock();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 200) {
        _start = std::chrono::system_clock::now();
        // updateOrientationSnake();
        movePacman();
    }
    // if (isGameOver() == true)
    //     restart();
    //mise à jour orientation snake   //clock
}

// bool Pacman::doYouEat()
// {
    // auto const &ptr = std::find_if(_entities.begin(), _entities.end(), [this] (std::shared_ptr<Entity> &p) {
    //     for (size_t i = 0; i < _apple.size(); i++) {
    //         if (p == _apple[i]) {
    //             if ((p->x == _snake.front()->x) && (p->y == _snake.front()->y)) {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // });
    // if (ptr == _entities.end())
    //     return false;
    // _entities.erase(ptr);
    // _apple.clear();
    // return true;
// }

// void Pacman::updateOrientationPacman()
// {
// }

bool Pacman::isGameOver() const
{
//     if (_snake.front()->x == -1 || _snake.front()->x == _width || _snake.front()->y == -1 || _snake.front()->y == _height) {
//         return true;
//     }
//     //Une partie du serpent touche un bord
    return false;
}

extern "C" arc::IGame *instance_ctor()
{
    return (new arc::Pacman());
}
