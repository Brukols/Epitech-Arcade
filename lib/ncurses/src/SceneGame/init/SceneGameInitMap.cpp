/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameInitMap
*/

#include "ncurses/SceneGame.hpp"

void arc::SceneGame::initMap()
{
    arc::Rectangle rect(_height + 2, _width * 2 + 2, BACKGROUND_COLOR, BACKGROUND_COLOR);

    rect.setPosition(5, 2);
    rect.setOutlineColors(MAIN_COLOR_2, MAIN_COLOR_2);
    _rects.clear();
    _rects.push_back(rect);
}