/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameInitRects
*/

#include "ncurses/SceneGame.hpp"


arc::Rectangle initGameRect()
{
    arc::Rectangle rect(51, 136, arc::BACKGROUND_COLOR, arc::BACKGROUND_COLOR);

    rect.setPosition(5, 2);
    rect.setOutlineColors(arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);
    return (rect);
}

void arc::SceneGame::initRects()
{
    static std::vector<Rectangle (*)()> rects = [this]() -> std::vector<Rectangle (*)()> {
        std::vector<Rectangle (*)()> rects;

        // rects.push_back(initGameRect);
        return (rects);
    }();

    _rects.clear();
    std::for_each(rects.begin(), rects.end(), [this](Rectangle (*fct)()) {
        _rects.push_back(fct());
    });
}