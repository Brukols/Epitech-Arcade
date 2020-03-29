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
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > 300) {
        _start = std::chrono::system_clock::now();
            movePacman();
            if (isGameOver() == true)
                restart();
            if (isGameWon() == true)
                restart();
            moveBlinky();
            movePinky();
            moveInky();
            moveClyde();
            if (isGameOver() == true)
                restart();
    }
}

bool Pacman::isPacpacEaten() const
{
    //croisement!
    if ((_blinky[0]->x == _pacman[0]->x && _blinky[0]->y == _pacman[0]->y) ||
        (_pinky[0]->x == _pacman[0]->x && _pinky[0]->y == _pacman[0]->y) ||
        (_inky[0]->x == _pacman[0]->x && _inky[0]->y == _pacman[0]->y) ||
        (_clyde[0]->x == _pacman[0]->x && _clyde[0]->y == _pacman[0]->y)) {
        return true;
    }
    return false;
}

bool Pacman::goUp(std::vector<std::shared_ptr<Entity>> _entity){
    // _entity[0]->orientation = Orientation::UP;
    _entity[0]->y -= 1;
    if (isCollision(_entity)) {
        _entity[0]->y += 1;
        return false;
    }
    return true;
}
bool Pacman::goRight(std::vector<std::shared_ptr<Entity>> _entity){
    // _entity[0]->direction = Direction::RIGHT;
    // int a = X::direction::left;
    _entity[0]->x += 1;
    if (isCollision(_entity)) {
        _entity[0]->x -= 1;
        return false;
    }
    return true;
    
}
bool Pacman::goDown(std::vector<std::shared_ptr<Entity>> _entity){
    // _entity[0]->orientation = Orientation::DOWN;
    // _entity[0]->orientation = Orientation::UP;
    _entity[0]->y += 1;
    if (isCollision(_entity)) {
        _entity[0]->y -= 1;
        return false;
    }
    return true;
}
bool Pacman::goLeft(std::vector<std::shared_ptr<Entity>> _entity){
    // _entity[0]->orientation = Orientation::LEFT;
    // _entity[0]->orientation = Orientation::UP;
    _entity[0]->x -= 1;
    if (isCollision(_entity)) {
        _entity[0]->x += 1;
        return false;
    }
    return true;
}

void Pacman::moveBlinky()
{
    int i;
    bool isMoving;

    // switch (_blinky[0]->orientation)
    // {
    // case Orientation::UP:
    //     isMoving = goUp(_blinky);
    //     break;
    // case Orientation::RIGHT:
    //     isMoving = goRight(_blinky);
    //     break;
    // case Orientation::DOWN:
    //     isMoving = goDown(_blinky);
    //     break;
    // case Orientation::LEFT:
    //     isMoving = goLeft(_blinky);
    //     break;
    // default:
    //     break;
    // }

        i = std::rand() % 4;
        switch (i)
        {
        case 0:
            isMoving = goUp(_blinky);
            break;
        case 1:
            isMoving = goRight(_blinky);
            break;
        case 2:
            isMoving = goDown(_blinky);
            break;
        case 3:
            isMoving = goLeft(_blinky);
            break;

        default:
            break;
        }

    while (!isMoving) {
        i = std::rand() % 4;
        switch (i)
        {
        case 0:
            isMoving = goUp(_blinky);
            break;
        case 1:
            isMoving = goRight(_blinky);
            break;
        case 2:
            isMoving = goDown(_blinky);
            break;
        case 3:
            isMoving = goLeft(_blinky);
            break;

        default:
            break;
        }
    }
}

void Pacman::movePinky()
{
    int i;
    bool isMoving;

    // switch (_pinky[0]->orientation)
    // {
    // case Orientation::UP:
    //     isMoving = goUp(_pinky);
    //     break;
    // case Orientation::RIGHT:
    //     isMoving = goRight(_pinky);
    //     break;
    // case Orientation::DOWN:
    //     isMoving = goDown(_pinky);
    //     break;
    // case Orientation::LEFT:
    //     isMoving = goLeft(_pinky);
    //     break;
    // default:
    //     break;
    // }

    while (!isMoving) {
        i = std::rand() % 4;
        switch (i)
        {
        case 0:
            isMoving = goUp(_pinky);
            break;
        case 1:
            isMoving = goRight(_pinky);
            break;
        case 2:
            isMoving = goDown(_pinky);
            break;
        case 3:
            isMoving = goLeft(_pinky);
            break;

        default:
            break;
        }
    }
}

void Pacman::moveInky()
{
    int i;
    bool isMoving;

    // switch (_inky[0]->orientation)
    // {
    // case Orientation::UP:
    //     isMoving = goUp(_inky);
    //     break;
    // case Orientation::RIGHT:
    //     isMoving = goRight(_inky);
    //     break;
    // case Orientation::DOWN:
    //     isMoving = goDown(_inky);
    //     break;
    // case Orientation::LEFT:
    //     isMoving = goLeft(_inky);
    //     break;
    // default:
    //     break;
    // }

    while (!isMoving) {
        i = std::rand() % 4;
        switch (i)
        {
        case 0:
            isMoving = goUp(_inky);
            break;
        case 1:
            isMoving = goRight(_inky);
            break;
        case 2:
            isMoving = goDown(_inky);
            break;
        case 3:
            isMoving = goLeft(_inky);
            break;

        default:
            break;
        }
    }}

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

    if (doYouEatCherry() == true) {
        _score += 100;
        initCherry();
        _nbCherry++;
        initGameStats();
    }
    if (doYouEatPacGum() == true) {
        _score += 1;
        _nbPacGum++;
        initGameStats();
    }
    ////
    // if (doYouEatSpecialPacGum() == true) {
    // _score += 1;
    // _nbPacGum++;
    // initGameStats();
    // }
    ////
}

// bool Pacman::doYouEatSpecialPacGum()
// {
//     auto const &ptr = std::find_if(_entities.begin(), _entities.end(), [this] (std::shared_ptr<Entity> &p) {
//         for (size_t i = 0; i < _SpecialPacGum.size(); i++) {
//             if (p == _SpecialPacGum[i]) {
//                 if ((p->x == _pacman.front()->x) && (p->y == _pacman.front()->y)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     });
//     if (ptr == _entities.end())
//         return false;
//     _entities.erase(ptr);
//     return true;
// }

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

bool Pacman::doYouEatCherry()
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

bool Pacman::isGameWon()
{
    // std::cout << _pacGum.size() << "-" << _nbPacGum << std::endl;
    if (_pacGum.size() == _nbPacGum)
        return true;
    return false;
}

bool Pacman::isGameOver() const
{
     return this->isPacpacEaten();
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