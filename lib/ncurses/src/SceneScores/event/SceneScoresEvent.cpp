/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneScoresEvent
*/

#include "ncurses/SceneScores.hpp"

void arc::SceneScores::eventButtonBack()
{
    clear();
    setActivate(false);
}

void arc::SceneScores::eventButtons(MEVENT &event)
{
    _listScores.event(event);

    std::for_each(_buttons.begin(), _buttons.end(), [this, &event](std::pair<Button, void (SceneScores::*)()> &button) {
        if (button.first.isMouseHover(event.x, event.y))
            (this->*button.second)();
    });
}

void arc::SceneScores::event(arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
{
    int c = wgetch(stdscr);
    static int tmp = -1;

    _actualEventType = Utility::getEventType(c);
    _actualKeyPress = Utility::getEventKey(c);
    if (c == KEY_MOUSE) {
        if (tmp != -1) {
            tmp = -1;
            return;
        }
        tmp = c;
        MEVENT event;
        getmouse(&event);
        eventButtons(event);
        return;
    }
    if (_actualKeyPress == arc::Event::Key::ESCAPE) {
        _eventFunctionExit();
        _actualEventType = arc::Event::QUIT;
    }
}