/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameEvent
*/

#include "ncurses/SceneEndGame.hpp"

void arc::SceneEndGame::eventButtons(const MEVENT &event)
{
    _listScores.event(event);

    std::for_each(_buttons.begin(), _buttons.end(), [this, &event](std::pair<Button, void (SceneEndGame::*)()> &button) {
        if (button.first.isMouseHover(event.x, event.y))
            (this->*button.second)();
    });

}

void arc::SceneEndGame::eventRestart()
{
    _eventRestart();
}

void arc::SceneEndGame::eventMenu()
{
    _eventMenu();
}

void arc::SceneEndGame::event(arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
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
}