/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenu
*/

#include "ncurses/SceneMenu.hpp"
#include "Utils.hpp"

void arc::SceneMenu::event(WINDOW *win, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
{
    if (getch() == 'q') {
        _eventFunctionExit();
        _actualEventType = arc::Event::QUIT;
    }
}