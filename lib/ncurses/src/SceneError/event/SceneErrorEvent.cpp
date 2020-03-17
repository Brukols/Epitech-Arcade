/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneErrorEvent
*/

#include "ncurses/SceneError.hpp"

void arc::SceneError::eventButtons(MEVENT event)
{
    std::for_each(_buttons.begin(), _buttons.end(), [this, &event](Button &button) {
        if (button.isMouseHover(event.x, event.y))
            button.click();
    });
}

void arc::SceneError::event(arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
{
    int c = wgetch(stdscr);

    _actualEventType = Utility::getEventType(c);
    _actualKeyPress = Utility::getEventKey(c);
    if (_actualKeyPress == arc::Event::Key::Q) {
        _actualEventType = arc::Event::QUIT;
    }
    if (c == KEY_MOUSE) {
        MEVENT event;
        getmouse(&event);
        eventButtons(event);
    }
}