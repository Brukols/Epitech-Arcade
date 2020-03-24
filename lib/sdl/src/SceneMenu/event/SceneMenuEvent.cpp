/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuEvent
*/

#include "sdl/SceneMenu.hpp"
#include "sdl/Utility.hpp"

void arc::SceneMenu::eventExit()
{
    _exit = true;
}

void arc::SceneMenu::eventPlay()
{
    _eventPlay();
}

void arc::SceneMenu::eventShowScores()
{
    _sceneScores->setActivate(true);
    _sceneScores->init();
}

void arc::SceneMenu::eventButtons(const arc::Event::Type &type, const arc::Event::Key &key)
{
    (void)key;
    if (type != arc::Event::Type::MOUSE_RELEASED)
        return;
    int x;
    int y;
    SDL_GetMouseState(&x, &y);
    std::for_each(_buttons.begin(), _buttons.end(), [this, &x, &y](std::pair<std::shared_ptr<IButton>, void (SceneMenu::*)()> &button) {
        if (button.first->isMouseHover(x, y))
            (this->*button.second)();
    });
}

void arc::SceneMenu::event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress)
{
    SDL_Event event;

    if (_exit == true) {
        actualEventType = arc::Event::Type::QUIT;
        return;
    }
    while (SDL_PollEvent(&event)) {
        actualEventType = Utility::getEventType(event);
        if (actualEventType == arc::Event::Type::KEY_PRESSED || actualEventType == arc::Event::Type::KEY_RELEASED)
            actualKeyPress = Utility::getEventKey(event);
        else
            actualKeyPress = arc::Event::Key::NONE;
        if (actualKeyPress == arc::Event::Key::ESCAPE)
            actualEventType = arc::Event::Type::QUIT;
        if (_sceneScores->isActivate()) {
            _sceneScores->event(actualEventType, actualKeyPress, event);
            return;
        }
        eventButtons(actualEventType, actualKeyPress);
        _listGames.event(actualEventType, actualKeyPress, event);
        _listGraphical.event(actualEventType, actualKeyPress, event);
        _inputUsername->event(actualEventType, actualKeyPress, event);
        if (_inputUsername->isSelect()) {
            actualEventType = arc::Event::Type::NO_EVENT;
            actualKeyPress = arc::Event::Key::NONE;
        }
    }
}