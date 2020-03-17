/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Display
*/

#include "ncurses/Graphical.hpp"

void arc::Graphical::display()
{
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