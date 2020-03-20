/*
** EPITECH PROJECT, 2019
** Arcade - Pacman
** File description:
** Gameplay
*/

#include "Pacman.hpp"

void Pacman::restart()
{
    _entities.clear();
    _pacman.clear();
    _apple.clear();
    initPacman();
}

void Pacman::updateGame()
{

    _end = std::chrono::system_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 500) {
        _start = std::chrono::system_clock::now();
            movePacman();
    }
    if (isGameOver() == true)
        restart();
}

void Pacman::movePacman()
{
    std::for_each(_pacman.begin(), _pacman.end(), [this](std::shared_ptr<Entity> &s) {
        if (s->orientation == Orientation::UP)
            s->y -= 1;
        if (s->orientation == Orientation::RIGHT)
            s->x += 1;
        if (s->orientation == Orientation::DOWN)
            s->y += 1;
        if (s->orientation == Orientation::LEFT)
            s->x -= 1;
    });
    //updateOrientationSnake();
    if (doYouEat() == true) {
        _score += 1;
        initApple();
        _nbApple++;
        initGameStats();
        //initialisation de sound si le serpent mange quelque chose
    }
    if (isCollision() == true) {
        //tant que key not pressed
        //on garde la meme position
    }
}

bool Pacman::doYouEat()
{
    auto const &ptr = std::find_if(_entities.begin(), _entities.end(), [this] (std::shared_ptr<Entity> &p) {
        for (size_t i = 0; i < _apple.size(); i++) {
            if (p == _apple[i]) {
                if ((p->x == _pacman.front()->x) && (p->y == _pacman.front()->y)) {
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

// void Pacman::updateOrientationPacman()
// {
//     int i = 0;

//     for (i = _pacman.size() - 1; i > 0; i--) {
//         _pacman[i]->orientation = _pacman[i - 1]->orientation;
//     }
// }

bool Pacman::isGameOver() const
{
    // if (_pacman.front()->x == -1 || _pacman.front()->x == _width || _pacman.front()->y == -1 || _pacman.front()->y == _height) {
    //     return true;
    // }
    // if (isCollision() == true)
    //     return true;
    return false;
}

bool Pacman::isCollision() const
{
    auto const &ptr = std::find_if(_pacman.begin(), _pacman.end(), [this] (std::shared_ptr<Entity> const &o) {
        if (_pacman.front()->x == o->x && _pacman.front()->y == o->y && _pacman.front() != o)
            return true;
        return false;
    });
    if (ptr == _pacman.end())
        return false;
    return true;
}

bool Pacman::isOnSnake(float x, float y)
{
    auto const &ptr = std::find_if(_pacman.begin(), _pacman.end(), [x, y](std::shared_ptr<Entity> &o){
        if (o->x == x && o->y == y)
            return true;
        return false;
    });
    if (ptr == _pacman.end())
        return false;
    return true;
}