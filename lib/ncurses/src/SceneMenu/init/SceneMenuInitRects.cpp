/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitRects
*/

#include "ncurses/SceneMenu.hpp"

static arc::Rectangle initRect()
{
    arc::Rectangle rect(10, 10);

    rect.setBackgroundColor(255, 0, 0);
    return (rect);
}

void arc::SceneMenu::initRects()
{
    static std::vector<Rectangle (*)()> rects = [this]() -> std::vector<Rectangle (*)()> {
        std::vector<Rectangle (*)()> rects;

        rects.push_back(initRect);
        return (rects);
    }();

    _rects.clear();
    std::for_each(rects.begin(), rects.end(), [this](Rectangle (*fct)()) {
        _rects.push_back(fct());
    });
}