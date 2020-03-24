/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameDisplay
*/

#include "sdl/SceneEndGame.hpp"

void arc::SceneEndGame::display(SDL_Renderer *window)
{
    std::for_each(_buttons.begin(), _buttons.end(), [&window](std::pair<std::unique_ptr<IButton>, void (SceneEndGame::*)()> &button) {
        button.first->display(window);
    });

    SDL_RenderPresent(window);
}