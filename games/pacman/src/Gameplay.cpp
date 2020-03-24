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
    _cherry.clear();
    _blinky.clear();
    _pinky.clear();
    _inky.clear();
    _clyde.clear();
    _pacGum.clear();
    initPacman();
}

void Pacman::updateGame()
{

    _end = std::chrono::system_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 500) {
        _start = std::chrono::system_clock::now();
            movePacman();
            moveBlinky();
            movePinky();
            moveInky();
            moveClyde();
    }
    if (isPacpacEaten(_blinky) || isPacpacEaten(_pinky) || isPacpacEaten(_inky) || isPacpacEaten(_clyde))
        restart();
    // if (isPacpacEaten(_blinky))
    //     restart();
    // if (isGameOver() == true)
    //     restart();
}

bool Pacman::isPacpacEaten(std::vector<std::shared_ptr<Entity>> _entity)
{
    if (_entity[0]->x == _pacman[0]->x && _entity[0]->y == _pacman[0]->y) {
        return true;
    }
    return false;
}

void Pacman::moveBlinky()
{
    int i = std::rand() % 4;

    if (i == 0) {
        _blinky[0]->y -= 1;
        if (isCollision(_blinky)) {
            _blinky[0]->y += 1;
            i = std::rand() % 4;
        }
    }

    if (i == 1) {
        _blinky[0]->x += 1;
        if (isCollision(_blinky)) {
            _blinky[0]->x -= 1;
            i = std::rand() % 4;
        }
    }

    if (i == 2) {
        _blinky[0]->y += 1;
        if (isCollision(_blinky)) {
            _blinky[0]->y -= 1;
            i = std::rand() % 4;
        }
    }

    if (i == 3) {
        _blinky[0]->x -= 1;
        if (isCollision(_blinky)) {
            _blinky[0]->x += 1;
            i = std::rand() % 4;
        }
    }
}

void Pacman::movePinky()
{
    int i = std::rand() % 4;

    if (i == 0) {
        _pinky[0]->y -= 1;
        if (isCollision(_pinky)) {
            _pinky[0]->y += 1;
            i = std::rand() % 4;
        }
    }

    if (i == 1) {
        _pinky[0]->x += 1;
        if (isCollision(_pinky)) {
            _pinky[0]->x -= 1;
            i = std::rand() % 4;
        }
    }

    if (i == 2) {
        _pinky[0]->y += 1;
        if (isCollision(_pinky)) {
            _pinky[0]->y -= 1;
            i = std::rand() % 4;
        }
    }

    if (i == 3) {
        _pinky[0]->x -= 1;
        if (isCollision(_pinky)) {
            _pinky[0]->x += 1;
            i = std::rand() % 4;
        }
    }
}

void Pacman::moveInky()
{
    int i = std::rand() % 4;

    if (i == 0) {
        _inky[0]->y -= 1;
        if (isCollision(_inky)) {
            _inky[0]->y += 1;
            i = std::rand() % 4;
        }
    }

    if (i == 1) {
        _inky[0]->x += 1;
        if (isCollision(_inky)) {
            _inky[0]->x -= 1;
            i = std::rand() % 4;
        }
    }

    if (i == 2) {
        _inky[0]->y += 1;
        if (isCollision(_inky)) {
            _inky[0]->y -= 1;
            i = std::rand() % 4;
        }
    }

    if (i == 3) {
        _inky[0]->x -= 1;
        if (isCollision(_inky)) {
            _inky[0]->x += 1;
            i = std::rand() % 4;
        }
    }
}

void Pacman::moveClyde()
{
    int i = std::rand() % 4;

    if (i == 0) {
        _clyde[0]->y -= 1;
        if (isCollision(_clyde)) {
            _clyde[0]->y += 1;
            i = std::rand() % 4;
        }
    }

    if (i == 1) {
        _clyde[0]->x += 1;
        if (isCollision(_clyde)) {
            _clyde[0]->x -= 1;
            i = std::rand() % 4;
        }
    }

    if (i == 2) {
        _clyde[0]->y += 1;
        if (isCollision(_clyde)) {
            _clyde[0]->y -= 1;
            i = std::rand() % 4;
        }
    }

    if (i == 3) {
        _clyde[0]->x -= 1;
        if (isCollision(_clyde)) {
            _clyde[0]->x += 1;
            i = std::rand() % 4;
        }
    }
}

void Pacman::movePacman()
{
    if (_pacman[0]->orientation == Orientation::UP) {
        _pacman[0]->y -= 1;
        if (isCollision(_pacman))
            _pacman[0]->y += 1;
    }

    if (_pacman[0]->orientation == Orientation::RIGHT) {
        _pacman[0]->x += 1;
        if (isCollision(_pacman))
            _pacman[0]->x -= 1;
    }

    if (_pacman[0]->orientation == Orientation::DOWN) {
        _pacman[0]->y += 1;
        if (isCollision(_pacman))
            _pacman[0]->y -= 1;
    }

    if (_pacman[0]->orientation == Orientation::LEFT) {
        _pacman[0]->x -= 1;
        if (isCollision(_pacman))
            _pacman[0]->x += 1;
    }

    updateOrientationPacman();
    if (doYouEat() == true) {
        _score += 1;
        initCherry();
        _nbCherry++;
        initGameStats();
        //initialisation de sound
    }
    if (doYouEatPacGum() == true) {
        _score += 1;
        _nbPacGum++;
        initGameStats();
    }
}

bool Pacman::doYouEatPacGum()
{
    auto const &ptr = std::find_if(_entities.begin(), _entities.end(), [this] (std::shared_ptr<Entity> &p) {
        for (size_t i = 0; i < _pacGum.size(); i++) {
            if (p == _pacGum[i]) {
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
    return true;
}

bool Pacman::doYouEat()
{
    auto const &ptr = std::find_if(_entities.begin(), _entities.end(), [this] (std::shared_ptr<Entity> &p) {
        for (size_t i = 0; i < _cherry.size(); i++) {
            if (p == _cherry[i]) {
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
    _cherry.clear();
    return true;
}

void Pacman::updateOrientationPacman()
{
    if (_pacman[0]->orientation == Orientation::LEFT)
        _pacman[0]->spritePath = "./assets/pacman/pacpacLeft.png";
    
    if (_pacman[0]->orientation == Orientation::DOWN)
        _pacman[0]->spritePath = "./assets/pacman/pacpacDown.png";

    if (_pacman[0]->orientation == Orientation::RIGHT)
        _pacman[0]->spritePath = "./assets/pacman/pacpacRight.png";

    if (_pacman[0]->orientation == Orientation::UP)
        _pacman[0]->spritePath = "./assets/pacman/pacpacUp.png";
}

bool Pacman::isGameOver() const
{
    // if (_pacman.front()->x == -1 || _pacman.front()->x == _width || _pacman.front()->y == -1 || _pacman.front()->y == _height) {
    //     return true;
    // }
    // if (isCollision(_clyde))
    //     return true;
    return false;
}

bool Pacman::isCollision(std::vector<std::shared_ptr<Entity>> _entity)
{
    for (auto it = _myMap.begin(); it != _myMap.end(); it++) {
        if (_entity[0]->x == (*it)->x && _entity[0]->y == (*it)->y)
            return true;
    }
    return false;
}

bool Pacman::isCollision(std::shared_ptr<Entity> _entity)
{
    for (auto it = _myMap.begin(); it != _myMap.end(); it++) {
        if (_entity->x == (*it)->x && _entity->y == (*it)->y)
            return true;
    }
    return false;
}