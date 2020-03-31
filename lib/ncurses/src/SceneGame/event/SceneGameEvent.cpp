/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameEvent
*/

#include "ncurses/SceneGame.hpp"

void arc::SceneGame::eventMenu()
{
    _eventBackToMenu();
}

void arc::SceneGame::eventButtons(MEVENT event)
{
    std::for_each(_buttons.begin(), _buttons.end(), [this, &event](std::pair<Button, void (SceneGame::*)()> &button) {
        if (button.first.isMouseHover(event.x, event.y)) {
            (this->*button.second)();
        }
    });
}

void arc::SceneGame::event(arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
{
    int c = wgetch(stdscr);

    _actualEventType = Utility::getEventType(c);
    _actualKeyPress = Utility::getEventKey(c);
    if (_actualKeyPress == arc::Event::Key::ESCAPE)
        _actualEventType = arc::Event::QUIT;
    if (_scenePause->isActivate()) {
        _scenePause->event(_actualEventType, _actualKeyPress);
        return;
    }
    if (c == KEY_MOUSE) {
        MEVENT event;
        getmouse(&event);
        eventButtons(event);
    }
    if (_controls[std::pair<Event::Type, Event::Key>(_actualEventType, _actualKeyPress)]) {
        _controls[std::pair<Event::Type, Event::Key>(_actualEventType, _actualKeyPress)]();
    }
}