/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameEvent
*/

#include "sdl/SceneGame.hpp"
#include "sdl/Utility.hpp"

void arc::SceneGame::eventMenu()
{
    _eventMenu();
}

void arc::SceneGame::eventButtons(const arc::Event::Type &type, const arc::Event::Key &key)
{
    (void)key;
    if (type != arc::Event::Type::MOUSE_RELEASED)
        return;
    int x;
    int y;
    SDL_GetMouseState(&x, &y);
    std::for_each(_buttons.begin(), _buttons.end(), [this, &x, &y](std::pair<std::unique_ptr<IButton>, void (SceneGame::*)()> &button) {
        if (button.first->isMouseHover(x, y))
            (this->*button.second)();
    });
}

void arc::SceneGame::event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress)
{
    SDL_Event event;

    actualEventType = arc::Event::Type::NO_EVENT;
    actualKeyPress = arc::Event::Key::NONE;
    while (SDL_PollEvent(&event)) {
        actualEventType = Utility::getEventType(event);
        if (actualEventType == arc::Event::Type::KEY_PRESSED || actualEventType == arc::Event::Type::KEY_RELEASED)
            actualKeyPress = Utility::getEventKey(event);
        else
            actualKeyPress = arc::Event::Key::NONE;
        if (actualKeyPress == arc::Event::Key::ESCAPE)
            actualEventType = arc::Event::Type::QUIT;
        if (_scenePause->isActivate())
            continue;
        eventButtons(actualEventType, actualKeyPress);
        std::pair pair = std::pair<Event::Type, Event::Key>(actualEventType, actualKeyPress);
        if (_controls.count(pair)) {
            _controls[pair]();
            continue;
        }
    }
}