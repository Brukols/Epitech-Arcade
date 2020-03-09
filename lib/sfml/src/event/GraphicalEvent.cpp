/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GraphicalEvent
*/

#include "Graphical.hpp"
#include "Utils.hpp"
#include <iostream>

arc::Event::Type arc::Graphical::getEventType()
{
    _scenes[_actualScene].get()->event(_window, _actualEventType, _actualKeyPress);
    if (_exit == true)
        return (arc::Event::Type::QUIT);
    return (_actualEventType);
}

arc::Event::Key arc::Graphical::getKeyPressed() const
{
    return (_actualKeyPress);
}