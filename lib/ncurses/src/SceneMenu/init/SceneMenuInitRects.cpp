/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitRects
*/

#include "ncurses/SceneMenu.hpp"

void arc::SceneMenu::initRects()
{
    static std::vector<Rectangle (*)()> rects = [this]() -> std::vector<Rectangle (*)()> {
        std::vector<Rectangle (*)()> rects;

        return (rects);
    }();

    _rects.clear();
    std::for_each(rects.begin(), rects.end(), [this](Rectangle (*fct)()) {
        _rects.push_back(fct());
    });
}