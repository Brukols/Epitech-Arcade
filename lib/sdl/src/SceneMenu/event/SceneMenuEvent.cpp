/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuEvent
*/

#include "sdl/SceneMenu.hpp"
#include "sdl/Utility.hpp"

void arc::SceneMenu::event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        actualEventType = Utility::getEventType(event);
        actualKeyPress = Utility::getEventKey(event);

        if (actualKeyPress == arc::Event::Key::ESCAPE)
            actualEventType = arc::Event::Type::QUIT;
    }
}