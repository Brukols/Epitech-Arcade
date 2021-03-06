/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameEvent
*/

#include "sdl/SceneEndGame.hpp"
#include "sdl/Utility.hpp"

void arc::SceneEndGame::eventRestart()
{
    _eventRestart();
}

void arc::SceneEndGame::eventMenu()
{
    _eventMenu();
}

void arc::SceneEndGame::eventButtons(const arc::Event::Type &type, const arc::Event::Key &key)
{
    (void)key;
    if (type != arc::Event::Type::MOUSE_RELEASED)
        return;
    int x;
    int y;
    SDL_GetMouseState(&x, &y);
    std::for_each(_buttons.begin(), _buttons.end(), [this, &x, &y](std::pair<std::unique_ptr<IButton>, void (SceneEndGame::*)()> &button) {
        if (button.first->isMouseHover(x, y))
            (this->*button.second)();
    });
}

void arc::SceneEndGame::event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress)
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
        eventButtons(actualEventType, actualKeyPress);
        _listScores->event(actualEventType, actualKeyPress, event);
    }
}