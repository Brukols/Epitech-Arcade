/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListLibrariesInit
*/

#include "sdl/ListLibraries.hpp"

static arc::Rectangle initBackgroundRect()
{
    arc::Rectangle rect;

    rect.setPosition(0, 0);
    rect.setColor({4, 6, 15, 255});
    rect.setSize(500, 650);
    rect.setOutline(true);
    return (rect);
}

void arc::ListLibraries::initRects()
{
    _rects.clear();
    _rects.push_back(initBackgroundRect());
}