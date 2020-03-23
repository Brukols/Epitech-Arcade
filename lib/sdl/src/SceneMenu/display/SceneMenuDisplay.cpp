/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuDisplay
*/

#include "sdl/SceneMenu.hpp"

void arc::SceneMenu::display(SDL_Window *window)
{
    SDL_Surface *windowSurface = SDL_GetWindowSurface(window);

    SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0x00, 0x00, 0x00));

    SDL_UpdateWindowSurface(window);
}