/*
** EPITECH PROJECT, 2019
** Arcade - Nibbler
** File description:
** Gameplay
*/

#include "Nibbler.hpp"

void Nibbler::restart()
{
    _entities.clear();
    _snake.clear();
    _apple.clear();
    initNibbler();
}

void Nibbler::updateGame()
{

    _end = std::chrono::system_clock::now();
    _endApple = std::chrono::system_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count() > _speed) {
        _start = std::chrono::system_clock::now();
        moveSnake();
    }
    if (std::chrono::duration_cast<std::chrono::milliseconds>(_endApple- _startApple).count() > 8000) {
        _startApple = std::chrono::system_clock::now();
        initApple();
        _speed -= 10;
    }
}

void Nibbler::moveSnake()
{
    std::for_each(_snake.begin(), _snake.end(), [this](std::shared_ptr<Entity> &s) {
        if (s->orientation == Orientation::UP)
            s->y -= 1;
        if (s->orientation == Orientation::RIGHT)
            s->x += 1;
        if (s->orientation == Orientation::DOWN)
            s->y += 1;
        if (s->orientation == Orientation::LEFT)
            s->x -= 1;
    });
    updateOrientationSnake();
    if (doYouEat() == true) {
        _score += 1;
        initApple();
        for (int i = rand()%(3-1) + 3; i > 0; i--)
            addBodySnake();
        _nbApple++;
        initGameStats();
        //initialisation de sound si le serpent mange quelque chose
    }
}

void Nibbler::addBodySnake()
{
    std::shared_ptr<Entity> bodySnake(new Entity);

    bodySnake->spritePath = "";
    bodySnake->type = PLAYER;
    bodySnake->orientation = _snake.back()->orientation;
    bodySnake->backgroundColor = _snake.back()->backgroundColor;
    if (bodySnake->orientation == Orientation::UP) {
        if (isPossibleAdd(_snake.back()->x, _snake.back()->y + 1) == true) {
            bodySnake->x = _snake.back()->x;
            bodySnake->y = _snake.back()->y + 1;
        } else
            addBodySnakeFirstPlace(bodySnake);
    } else if (bodySnake->orientation == Orientation::RIGHT) {
        if (isPossibleAdd(_snake.back()->x - 1, _snake.back()->y) == true) {
            bodySnake->x = _snake.back()->x - 1;
            bodySnake->y = _snake.back()->y;
        } else
            addBodySnakeFirstPlace(bodySnake);
    } else if (bodySnake->orientation == Orientation::LEFT) {
        if (isPossibleAdd(_snake.back()->x + 1, _snake.back()->y) == true) {
            bodySnake->x = _snake.back()->x + 1;
            bodySnake->y = _snake.back()->y;
        } else
            addBodySnakeFirstPlace(bodySnake);
    } else if (bodySnake->orientation == Orientation::DOWN) {
        if (isPossibleAdd(_snake.back()->x, _snake.back()->y - 1) == true) {
            bodySnake->x = _snake.back()->x;
            bodySnake->y = _snake.back()->y - 1;
        } else
            addBodySnakeFirstPlace(bodySnake);
    }
    _snake.push_back(bodySnake);
    _entities.push_back(bodySnake);
}

bool Nibbler::isPossibleAdd(float x, float y)
{
    auto const &ptr = std::find_if(_entities.begin(), _entities.end(), [x, y, this](std::shared_ptr<Entity> &o) {
        if (o->x == x && o->y == y)
            return true;
        return false;
    });
    if (ptr != _entities.end())
        return false;
    if ( x < 0 || x > _width || y < 0 || y > _height)
        return false;
    return true;
}

void Nibbler::addBodySnakeFirstPlace(std::shared_ptr<Entity> &o)
{
    if (isPossibleAdd(_snake.back()->x + 1, _snake.back()->y) == true) {
        o->x = _snake.back()->x + 1;
        o->y = _snake.back()->y;
    } else if (isPossibleAdd(_snake.back()->x, _snake.back()->y + 1) == true) {
        o->x = _snake.back()->x;
        o->y = _snake.back()->y + 1;
    } else if (isPossibleAdd(_snake.back()->x, _snake.back()->y - 1) == true) {
        o->x = _snake.back()->x;
        o->y = _snake.back()->y - 1;
    } else if (isPossibleAdd(_snake.back()->x - 1, _snake.back()->y) == true) {
        o->x = _snake.back()->x - 1;
        o->y = _snake.back()->y;
    } else {
        //GameOver
    }
}

bool Nibbler::doYouEat()
{
    auto const &ptr = std::find_if(_entities.begin(), _entities.end(), [this] (std::shared_ptr<Entity> &p) {
        for (size_t i = 0; i < _apple.size(); i++) {
            if (p == _apple[i]) {
                if ((p->x == _snake.front()->x) && (p->y == _snake.front()->y)) {
                    _apple[i]->x = -1;
                    _apple[i]->y = -1;
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

void Nibbler::updateOrientationSnake()
{
    int i = 0;

    for (i = _snake.size() - 1; i > 0; i--) {
        _snake[i]->orientation = _snake[i - 1]->orientation;
    }
}

bool Nibbler::isGameOver() const
{
    if (_snake.front()->x == -1 || _snake.front()->x == _width || _snake.front()->y == -1 || _snake.front()->y == _height) {
        return true;
    }
    if (isCollision() == true)
        return true;
    if (nbApple() > 6)
        return true;
    return false;
}

int Nibbler::nbApple() const
{
    int i = 0;
    std::for_each(_entities.begin(), _entities.end(), [&i] (std::shared_ptr<Entity> const &o) {
        if (o->type == CONSUMABLE)
            i++;
    });
    return i;
}

bool Nibbler::isCollision() const
{
    auto const &ptr = std::find_if(_snake.begin(), _snake.end(), [this] (std::shared_ptr<Entity> const &o) {
        if (_snake.front()->x == o->x && _snake.front()->y == o->y && _snake.front() != o)
            return true;
        return false;
    });
    if (ptr == _snake.end())
        return false;
    return true;
}

bool Nibbler::isOnSnake(float x, float y)
{
    auto const &ptr = std::find_if(_snake.begin(), _snake.end(), [x, y](std::shared_ptr<Entity> &o){
        if (o->x == x && o->y == y)
            return true;
        return false;
    });
    if (ptr == _snake.end())
        return false;
    return true;
}