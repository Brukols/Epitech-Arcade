/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GraphicalEvent
*/

#include "Graphical.hpp"
#include "Utils.hpp"
#include <iostream>

arc::Event::Type arc::Graphical::getEventType() const
{
    return (_actualEventType);
}

arc::Event::Key arc::Graphical::getKeyPressed() const
{
    return (_actualKeyPress);
}