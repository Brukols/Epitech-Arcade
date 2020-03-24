/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameInitRects
*/

#include "sdl/SceneGame.hpp"

static arc::Rectangle *initSideRectangle()
{
    arc::Rectangle *rect = new arc::Rectangle();

    rect->setPosition(0, 0);
    rect->setColor({0, 48, 65, 255});
    rect->setSize(350, 1080);
    return (rect);
}

static arc::Rectangle *initBackgroundMap()
{
    arc::Rectangle *rect = new arc::Rectangle();

    rect->setPosition(500, 100);
    rect->setColor({0, 0, 0, 255});
    rect->setSize(1200, 900);
    rect->setOutline(true);
    return (rect);
}

void arc::SceneGame::initRects()
{
    _rects.clear();
    _rects.push_back(std::unique_ptr<Rectangle>(initSideRectangle()));
    _rects.push_back(std::unique_ptr<Rectangle>(initBackgroundMap()));
}