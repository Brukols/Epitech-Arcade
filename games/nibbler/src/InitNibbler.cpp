/*
** EPITECH PROJECT, 2019
** Arcade - Nibbler
** File description:
** InitNibbler
*/

#include "Nibbler.hpp"

void Nibbler::initNibbler()
{
    _height = 75;
    _width = 100;
    _font = "./resources/fonts/Raleway-Light.ttf";
    _music = "";
    _sound = "";
    _score = 0;
    initEntities();
    initVisualAssets();
    initControls();
    initGameControls();
    initGameStats();
}

void Nibbler::initEntities()
{
    initSnake();
    initApple();
}

void Nibbler::initSnake()
{
    for (int i = 0; i < 4; i++) {
        std::shared_ptr<Entity> snakeEntity(new Entity);
        snakeEntity->spritePath = "";
        snakeEntity->backgroundColor = Color{85, 107, 47, 255};
        snakeEntity->orientation = Orientation::LEFT;
        float x = ((80/2) - 4 ) + i;
        float y = (80/2) + i;
        _entities.push_back(snakeEntity);
        _snake.push_back(snakeEntity);
    }
}

void Nibbler::initApple()
{
    float random_x = rand () % _width;
    float random_y = rand () % _height;

    while (isOnSnake(random_x, random_y) == true) {
        random_x = rand () % _width;
        random_y = rand () % _height;
    }
    std::shared_ptr<Entity> fruitEntity(new Entity);
    fruitEntity->spritePath = "";
    fruitEntity->backgroundColor = Color{227, 18, 18, 255};
    fruitEntity->orientation = Orientation::LEFT;
    fruitEntity->x = random_x;
    fruitEntity->y = random_y;
    _entities.push_back(fruitEntity);
    _apple.push_back(fruitEntity);
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

void Nibbler::initVisualAssets()
{
}

void Nibbler::initControls()
{
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::LEFT)] = [this]() -> void {
        if (_snake.front()->orientation == Orientation::UP)
            _snake.front()->orientation = Orientation::LEFT;
        if (_snake.front()->orientation == Orientation::RIGHT)
            _snake.front()->orientation = Orientation::UP;
        if (_snake.front()->orientation == Orientation::DOWN)
            _snake.front()->orientation = Orientation::RIGHT;
        if (_snake.front()->orientation == Orientation::LEFT)
            _snake.front()->orientation = Orientation::DOWN;
        moveSnake();
    };
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::RIGHT)] = [this]() -> void {
        if (_snake.front()->orientation == Orientation::UP)
            _snake.front()->orientation = Orientation::RIGHT;
        if (_snake.front()->orientation == Orientation::RIGHT)
            _snake.front()->orientation = Orientation::DOWN;
        if (_snake.front()->orientation == Orientation::DOWN)
            _snake.front()->orientation = Orientation::LEFT;
        if (_snake.front()->orientation == Orientation::LEFT)
            _snake.front()->orientation = Orientation::UP;
        moveSnake();
    };
}

void Nibbler::moveSnake()
{
    std::for_each(_snake.begin(), _snake.end(), [](std::shared_ptr<Entity> &s) {
        if (s->orientation == Orientation::UP)
            s->y -= 1;
        if (s->orientation == Orientation::RIGHT)
            s->x += 1;
        if (s->orientation == Orientation::DOWN)
            s->y += 1;
        if (s->orientation == Orientation::LEFT)
            s->x -= 1;
    });
}

void Nibbler::initGameControls()
{
}

void Nibbler::initGameStats()
{
}