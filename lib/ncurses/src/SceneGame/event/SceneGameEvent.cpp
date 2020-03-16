/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameEvent
*/

#include "ncurses/SceneGame.hpp"

void arc::SceneGame::event(arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
{
    int c = wgetch(stdscr);
    if (c == 'q') {
        _actualEventType = arc::Event::QUIT;
    }
    if (c == KEY_MOUSE) {
        MEVENT event;
        getmouse(&event);
        eventButtons(event);
    }
    (void)_actualKeyPress;
}