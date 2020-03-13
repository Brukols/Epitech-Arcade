/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Display
*/

#include "Graphical.hpp"

void arc::Graphical::display()
{
    _scenes[_actualScene]->display(_win.get());
    _scenes[_actualScene]->event(_win.get(), _actualEventType, _actualKeyPress);
}