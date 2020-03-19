/*
** EPITECH PROJECT, 2019
** Arcade - Pacman
** File description:
** InitNibbler
*/

#include "Pacman.hpp"

#include <iostream>

void Pacman::initPacmanGame()
{
    _start = std::chrono::system_clock::now();
    _end = std::chrono::system_clock::now();
    _title = "Pacman";
    _height = 51;
    _width = 68;
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

void Pacman::initEntities()
{
    initPacman();
    // initFruits();
    // initGhosts();
}

void Pacman::initPacman()
{
 
    std::shared_ptr<Entity> pacmanEntity(new Entity);
    pacmanEntity->spritePath = "";
    pacmanEntity->backgroundColor = Color{255, 228, 58, 255};
    pacmanEntity->orientation = Orientation::LEFT;
    pacmanEntity->x = _width / 2;
    pacmanEntity->y = _height / 2;
    _entities.push_back(pacmanEntity);
    _pacman.push_back(pacmanEntity);
}

// void Nibbler::initApple()
// {
//     float random_x = rand () % _width;
//     float random_y = rand () % _height;

//     while (isOnSnake(random_x, random_y) == true) {
//         random_x = rand () % _width;
//         random_y = rand () % _height;
//     }
//     std::shared_ptr<Entity> fruitEntity(new Entity);
//     fruitEntity->spritePath = "";
//     fruitEntity->backgroundColor = Color{227, 18, 18, 255};
//     fruitEntity->orientation = Orientation::LEFT;
//     fruitEntity->x = random_x;
//     fruitEntity->y = random_y;
//     _entities.push_back(fruitEntity);
//     _apple.push_back(fruitEntity);
// }

// bool Nibbler::isOnSnake(float x, float y)
// {
//     auto const &ptr = std::find_if(_snake.begin(), _snake.end(), [x, y](std::shared_ptr<Entity> &o){
//         if (o->x == x && o->y == y)
//             return true;
//         return false;
//     });
//     if (ptr == _snake.end())
//         return false;
//     return true;
// }

void Pacman::initVisualAssets()
{
}

void Pacman::initControls()
{
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::LEFT)] = [this]() -> void {
        _pacman.front()->orientation = Orientation::LEFT;
    };
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::RIGHT)] = [this]() -> void {
        _pacman.front()->orientation = Orientation::RIGHT;
    };
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::UP)] = [this]() -> void {
        _pacman.front()->orientation = Orientation::UP;
    };
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::DOWN)] = [this]() -> void {
        _pacman.front()->orientation = Orientation::DOWN;
    };
}

void Pacman::movePacman()
{
     //updateOrientationPacman();
    // if (doYouEat() == true) {
    //     initApple();
    //     std::shared_ptr<Entity> bodySnake(new Entity);
    //     _score += 1;
    //     //agrandir le snake
    //     bodySnake->spritePath = "";
    //     bodySnake->orientation = _snake.back()->orientation;
    //     bodySnake->backgroundColor = _snake.back()->backgroundColor;
    //     if (bodySnake->orientation == Orientation::UP) {
    //         bodySnake->x = _snake.back()->x;
    //         bodySnake->y = _snake.back()->y + 1;
    //     } else if (bodySnake->orientation == Orientation::RIGHT) {
    //         bodySnake->x = _snake.back()->x - 1;
    //         bodySnake->y = _snake.back()->y;
    //     } else if (bodySnake->orientation == Orientation::LEFT) {
    //         bodySnake->x = _snake.back()->x + 1;
    //         bodySnake->y = _snake.back()->y;
    //     } else if (bodySnake->orientation == Orientation::DOWN) {
    //         bodySnake->x = _snake.back()->x;
    //         bodySnake->y = _snake.back()->y - 1;
    //     }
    //     _snake.push_back(bodySnake);
    //     _entities.push_back(bodySnake);
        //initialisation de sound si le serpent mange quelque chose
    // }
}

void Pacman::initGameControls()
{
}

void Pacman::initGameStats()
{
}