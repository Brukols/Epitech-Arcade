/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuDisplay
*/

#include "sdl/SceneMenu.hpp"
#include <iostream>
void arc::SceneMenu::display(SDL_Renderer *window)
{
    std::for_each(_rects.begin(), _rects.end(), [&window](Rectangle &rect) {
        rect.display(window);
    });

    std::for_each(_texts.begin(), _texts.end(), [&window](Text &text) {
        text.display(window);
    });

    SDL_RenderPresent(window);
}