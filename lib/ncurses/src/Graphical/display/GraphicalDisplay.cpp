/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Display
*/

#include "ncurses/Graphical.hpp"

void arc::Graphical::display()
{
    static bool resize = false;
    box(stdscr, 0, 0);

    if (LINES < 55 || COLS < 230) {
        _sceneError.clear();
        _sceneError.setErrorMessage("Please resize your window");
        _sceneError.display();
        _sceneError.event(_actualEventType, _actualKeyPress);
        refresh();
        resize = true;
        return;
    }
    if (resize == true) {
        clear();
        resize = false;
    }
    if (_error) {
        _sceneError.display();
        _sceneError.event(_actualEventType, _actualKeyPress);
        refresh();
        return;
    }
    _scenes[_actualScene]->display();
    _scenes[_actualScene]->event(_actualEventType, _actualKeyPress);
    refresh();
}