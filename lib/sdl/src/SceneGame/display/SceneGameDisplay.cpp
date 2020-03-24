/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameDisplay
*/

#include "sdl/SceneGame.hpp"

void arc::SceneGame::display(SDL_Renderer *window)
{
    std::for_each(_rects.begin(), _rects.end(), [&window](std::unique_ptr<Rectangle> &rect) {
        rect.get()->display(window);
    });

    SDL_RenderPresent(window);
}