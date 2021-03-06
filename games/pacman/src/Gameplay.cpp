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
        if (_blueMode > 0) {
            _blueCpt = 0;
             if (_blueMode == 30)
                initBlueMode();
            GhostsEaten();
            _blueMode--;
            if (_blueMode == 0)
                initColorMode();
        }
        movePacman();
        moveBlinky();
        movePinky();
        moveInky();
        moveClyde();
    }
}

void Pacman::initBlueMode()
{
    _blinky[0]->spritePath = "./assets/pacman/blueMode.png";
    _pinky[0]->spritePath = "./assets/pacman/blueMode.png";
    _inky[0]->spritePath = "./assets/pacman/blueMode.png";
    _clyde[0]->spritePath = "./assets/pacman/blueMode.png";

    _blinky[0]->backgroundColor = Color{42, 82, 190, 255}; //BlueMode
    _pinky[0]->backgroundColor = Color{42, 82, 190, 255}; //BlueMode
    _inky[0]->backgroundColor = Color{42, 82, 190, 255}; //BlueMode
    _clyde[0]->backgroundColor = Color{42, 82, 190, 255}; //BlueMode
}

void Pacman::initColorMode()
{
    _blinky[0]->spritePath = "./assets/pacman/blinky.png";
    _pinky[0]->spritePath = "./assets/pacman/pinky.png";
    _inky[0]->spritePath = "./assets/pacman/inky.png";
    _clyde[0]->spritePath = "./assets/pacman/clyde.png";

    _blinky[0]->backgroundColor = Color{255, 4, 5, 255}; //Red
    _pinky[0]->backgroundColor = Color{244, 158, 250, 255}; //Pink
    _inky[0]->backgroundColor = Color{11, 12, 231, 255}; //Blue
    _clyde[0]->backgroundColor = Color{243, 130, 2, 255}; //Orange

    _blinky[0]->type = ENEMY;
    _pinky[0]->type = ENEMY;
    _inky[0]->type = ENEMY;
    _clyde[0]->type = ENEMY;
}

void Pacman::GhostsEaten()
{
    if (_blueMode != 0) {

        if (_blinky[0]->x == _pacman[0]->x && _blinky[0]->y == _pacman[0]->y)
            reinitGhostBlinky();

        if (_pinky[0]->x == _pacman[0]->x && _pinky[0]->y == _pacman[0]->y)
            reinitGhostPinky();

        if (_inky[0]->x == _pacman[0]->x && _inky[0]->y == _pacman[0]->y)
            reinitGhostInky();
        
        if (_clyde[0]->x == _pacman[0]->x && _clyde[0]->y == _pacman[0]->y)
            reinitGhostClyde();
    }
}

bool Pacman::isPacpacEaten() const
{
    if (_blueMode == 0) {
        if ((_blinky[0]->x == _pacman[0]->x && _blinky[0]->y == _pacman[0]->y) ||
            (_pinky[0]->x == _pacman[0]->x && _pinky[0]->y == _pacman[0]->y) ||
            (_inky[0]->x == _pacman[0]->x && _inky[0]->y == _pacman[0]->y) ||
            (_clyde[0]->x == _pacman[0]->x && _clyde[0]->y == _pacman[0]->y)) {
            return true;
        }
    }
    return false;
}

bool Pacman::goUp(std::vector<std::shared_ptr<Entity>> _entity){
    _entity[0]->y -= 1;
    if (isCollision(_entity)) {
        _entity[0]->y += 1;
        return false;
    }
    return true;
}
bool Pacman::goRight(std::vector<std::shared_ptr<Entity>> _entity){
    _entity[0]->x += 1;
    if (isCollision(_entity)) {
        _entity[0]->x -= 1;
        return false;
    }
    return true;
    
}
bool Pacman::goDown(std::vector<std::shared_ptr<Entity>> _entity){
    _entity[0]->y += 1;
    if (isCollision(_entity)) {
        _entity[0]->y -= 1;
        return false;
    }
    return true;
}
bool Pacman::goLeft(std::vector<std::shared_ptr<Entity>> _entity){
    _entity[0]->x -= 1;
    if (isCollision(_entity)) {
        _entity[0]->x += 1;
        return false;
    }
    return true;
}

Orientation Pacman::moveGhosts(std::vector<std::shared_ptr<Entity>> _ghost, Orientation direction)
{
        int i;
        int cpt = 0;
    bool isMoving = false;

    switch (direction)
    {
    case Orientation::UP:
        while (!isMoving) {
            i = std::rand() % 3;
            if (cpt < 10) {
                switch (i)
                {
                case 0:
                    isMoving = goUp(_ghost);
                    direction = Orientation::UP;
                    break;
                case 1:
                    isMoving = goRight(_ghost);
                    direction = Orientation::RIGHT;
                    break;
                case 2:
                    isMoving = goLeft(_ghost);
                    direction = Orientation::LEFT;
                    break;
                default:
                    break;
                }
                cpt++;
            } else {
                isMoving = goDown(_ghost);
                direction = Orientation::DOWN;
            }
        }
        break;
    case Orientation::RIGHT:
        while (!isMoving) {
            i = std::rand() % 3;
            if (cpt < 10) {
                switch (i)
                {
                case 0:
                    isMoving = goUp(_ghost);
                    direction = Orientation::UP;
                    break;
                case 1:
                    isMoving = goRight(_ghost);
                    direction = Orientation::RIGHT;
                    break;
                case 2:
                    isMoving = goDown(_ghost);
                    direction = Orientation::DOWN;
                    break;
                default:
                    break;
                }
            cpt++;
            } else {
                isMoving = goLeft(_ghost);
                direction = Orientation::LEFT;
            }
        }
        break;
    case Orientation::DOWN:
        while (!isMoving) {
            i = std::rand() % 3;
            if (cpt < 10) {
                switch (i)
                {
                case 0:
                    isMoving = goDown(_ghost);
                    direction = Orientation::DOWN;
                    break;
                case 1:
                    isMoving = goRight(_ghost);
                    direction = Orientation::RIGHT;
                    break;
                case 2:
                    isMoving = goLeft(_ghost);
                    direction = Orientation::LEFT;
                    break;
                default:
                    break;
                }
                cpt++;
            } else {
                isMoving = goUp(_ghost);
                direction = Orientation::UP;
            }
        }
        break;
    case Orientation::LEFT:
        while (!isMoving) {
            i = std::rand() % 3;
            if (cpt < 10) {
                switch (i)
                {
                case 0:
                    isMoving = goUp(_ghost);
                    direction = Orientation::UP;
                    break;
                case 1:
                    isMoving = goDown(_ghost);
                    direction = Orientation::DOWN;
                    break;
                case 2:
                    isMoving = goLeft(_ghost);
                    direction = Orientation::LEFT;
                    break;
                default:
                    break;
                }
                cpt++;
            } else {
                isMoving = goRight(_ghost);
                direction = Orientation::RIGHT;
            }
        }
        break;
    default:
        break;
    }

    while (!isMoving) {
        i = std::rand() % 4;
        switch (i)
        {
        case 0:
            isMoving = goUp(_ghost);
            direction = Orientation::UP;
            break;
        case 1:
            isMoving = goRight(_ghost);
            direction = Orientation::RIGHT;
            break;
        case 2:
            isMoving = goDown(_ghost);
            direction = Orientation::DOWN;
            break;
        case 3:
            isMoving = goLeft(_ghost);
            direction = Orientation::LEFT;
            break;

        default:
            break;
        }
    }
    return direction;
}

void Pacman::moveBlinky()
{
    _blinkyDirection = moveGhosts(_blinky, _blinkyDirection);
}

void Pacman::movePinky()
{
    _pinkyDirection = moveGhosts(_pinky, _pinkyDirection);
}

void Pacman::moveInky()
{
    _inkyDirection = moveGhosts(_inky, _inkyDirection);
}

void Pacman::moveClyde()
{
    _clydeDirection = moveGhosts(_clyde, _clydeDirection);
}

void Pacman::movePacman()
{
    switch (_pacman[0]->orientation)
    {
    case Orientation::UP:
        goUp(_pacman);
        break;
    case Orientation::RIGHT:
        goRight(_pacman);
        break;
    case Orientation::DOWN:
        goDown(_pacman);
        break;
    case Orientation::LEFT:
        goLeft(_pacman);
        break;
    default:
        break;
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
    if (doYouEatSpecialPacGum() == true) {
    _score += 1;
    _nbPacGum++;
    initGameStats();
    _blueMode = 30;
    }
    if (_blueMode > 0) {
        if (doyouEatBlueGhosts() == true) {
            _blueCpt++;
            _score += pow(2, _blueCpt) * 100;
            _nbPacGum++;
            initGameStats();
                //200
                //400
                //800
                //1600
        }
    }
}

bool Pacman::doyouEatBlueGhosts()
{
    if ((_blinky[0]->x == _pacman[0]->x && _blinky[0]->y == _pacman[0]->y) ||
        (_pinky[0]->x == _pacman[0]->x && _pinky[0]->y == _pacman[0]->y) ||
        (_inky[0]->x == _pacman[0]->x && _inky[0]->y == _pacman[0]->y) ||
        (_clyde[0]->x == _pacman[0]->x && _clyde[0]->y == _pacman[0]->y)) {
        return true;
    }
    return false;
}

bool Pacman::doYouEatSpecialPacGum()
{
    auto const &ptr = std::find_if(_entities.begin(), _entities.end(), [this] (std::shared_ptr<Entity> &p) {
        for (size_t i = 0; i < _SpecialPacGum.size(); i++) {
            if (p == _SpecialPacGum[i]) {
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

bool Pacman::isGameOver() const
{
    if (_pacGum.size() == _nbPacGum || isPacpacEaten() == true)
        return true;
    return false;

    // return this->isPacpacEaten();
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