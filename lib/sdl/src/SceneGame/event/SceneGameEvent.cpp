/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameEvent
*/

#include "sdl/SceneGame.hpp"
#include "sdl/Utility.hpp"

void arc::SceneGame::event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        actualEventType = Utility::getEventType(event);
        if (actualEventType == arc::Event::Type::KEY_PRESSED || actualEventType == arc::Event::Type::KEY_RELEASED)
            actualKeyPress = Utility::getEventKey(event);
        else
            actualKeyPress = arc::Event::Key::NONE;
        if (actualKeyPress == arc::Event::Key::ESCAPE)
            actualEventType = arc::Event::Type::QUIT;
    }
}