/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitRects
*/

#include "sdl/SceneMenu.hpp"

static arc::Rectangle initRectExample()
{
    arc::Rectangle rect;

    rect.setPosition(10, 10);
    rect.setColor({255, 0, 0, 255});
    rect.setSize(100, 100);
    return (rect);
}

void arc::SceneMenu::initRects()
{
    _rects.clear();
    _rects.push_back(initRectExample());
}