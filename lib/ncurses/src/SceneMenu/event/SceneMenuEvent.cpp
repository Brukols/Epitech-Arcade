/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenu
*/

#include "ncurses/SceneMenu.hpp"
#include "Utils.hpp"

void arc::SceneMenu::event(arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
{
    int c = wgetch(stdscr);
    if (c == 'q') {
        _eventFunctionExit();
        _actualEventType = arc::Event::QUIT;
    }
    if (c == KEY_MOUSE) {
        MEVENT event;
        getmouse(&event);
        eventButtons(event);
    }
    (void)_actualKeyPress;
}