/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameDisplay
*/

#include "sdl/SceneGame.hpp"
#include <iostream>

void arc::SceneGame::display(SDL_Renderer *window)
{
    std::for_each(_rects.begin(), _rects.end(), [&window](std::unique_ptr<Rectangle> &rect) {
        rect.get()->display(window);
    });

    std::for_each(_gameMap.begin(), _gameMap.end(), [&window, this](std::shared_ptr<Entity> &entity) {
        _cell.get()->setPosition(entity->x * _cell.get()->getWidth() + 500, entity->y * _cell.get()->getHeight() + 100);
        _cell.get()->setColor({entity->backgroundColor.r, entity->backgroundColor.g, entity->backgroundColor.b, entity->backgroundColor.a});
        _cell.get()->display(window);
    });

    SDL_RenderPresent(window);
}