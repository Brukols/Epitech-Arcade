/*
** EPITECH PROJECT, 2019
** Arcade - Nibbler
** File description:
** InitNibbler
*/

#include "Nibbler.hpp"

#include <iostream>

void Nibbler::initNibbler()
{
    _start = std::chrono::system_clock::now();
    _end = std::chrono::system_clock::now();
    _title = "Nibbler";
    _height = 51;
    _width = 68;
    _font = "./resources/fonts/Raleway-Light.ttf";
    _music = "";
    _sound = "";
    _score = 0;
    _nbApple = 0;
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
        snakeEntity->type = PLAYER;
        snakeEntity->spritePath = "";
        snakeEntity->backgroundColor = Color{85, 107, 47, 255};
        snakeEntity->orientation = Orientation::LEFT;
        snakeEntity->x = ((_width/2) - 4 ) + i;
        snakeEntity->y = (_height/2);
        _entities.push_back(snakeEntity);
        _snake.push_back(snakeEntity);
    }
    _snake.front()->backgroundColor = Color {127, 191, 63, 255};
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
    fruitEntity->type = CONSUMABLE;
    fruitEntity->spritePath = "";
    fruitEntity->backgroundColor = Color{227, 18, 18, 255};
    fruitEntity->orientation = Orientation::LEFT;
    fruitEntity->x = random_x;
    fruitEntity->y = random_y;
    _entities.push_back(fruitEntity);
    _apple.push_back(fruitEntity);
}

void Nibbler::initVisualAssets()
{
    _visualAssets['a'] = std::pair<std::string, Color> ("", Color{227, 18, 18, 255});
}

void Nibbler::initControls()
{
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::LEFT)] = [this]() -> void {
        if (_snake.front()->orientation == Orientation::RIGHT || _snake.front()->orientation == Orientation::LEFT) {
        } else {
            _snake.front()->orientation = Orientation::LEFT;
            moveSnake();
        }
    };
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::RIGHT)] = [this]() -> void {
        if (_snake.front()->orientation == Orientation::LEFT || _snake.front()->orientation == Orientation::RIGHT) {
        } else {
            _snake.front()->orientation = Orientation::RIGHT;
            moveSnake();
        }
    };
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::UP)] = [this]() -> void {
        if (_snake.front()->orientation == Orientation::DOWN || _snake.front()->orientation == Orientation::UP) {
        } else {
            _snake.front()->orientation = Orientation::UP;
            moveSnake();
        }
    };
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::DOWN)] = [this]() -> void {
        if (_snake.front()->orientation == Orientation::UP || _snake.front()->orientation == Orientation::DOWN) {
        } else {
            _snake.front()->orientation = Orientation::DOWN;
            moveSnake();
        }
    };
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::BACKSPACE)] = [this]() -> void {
        moveSnake();
    };
}

void Nibbler::initGameControls()
{
}

void Nibbler::initGameStats()
{
    _gameStats.push_back("%a " + std::to_string(_nbApple));
}