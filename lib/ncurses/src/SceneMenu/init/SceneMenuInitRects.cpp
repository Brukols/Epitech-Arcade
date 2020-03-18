/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitRects
*/

#include "ncurses/SceneMenu.hpp"


// static arc::Rectangle initRect()
// {
//     arc::Rectangle rect(1, 1, arc::MAIN_COLOR_1, arc::MAIN_COLOR_1);

//     rect.setPosition(0, 0);
//     return (rect);
// }

// static arc::Rectangle initRect2()
// {
//     arc::Rectangle rect(1, 1, arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);

//     rect.setPosition(0, 1);
//     return (rect);
// }

// static arc::Rectangle initRect3()
// {
//     arc::Rectangle rect(1, 1, arc::MAIN_COLOR_3, arc::MAIN_COLOR_3);

//     rect.setPosition(0, 2);
//     return (rect);
// }

// static arc::Rectangle initRect4()
// {
//     arc::Rectangle rect(1, 1, arc::MAIN_COLOR_4, arc::MAIN_COLOR_4);

//     rect.setPosition(0, 3);
//     return (rect);
// }

// static arc::Rectangle initRect5()
// {
//     arc::Rectangle rect(1, 1, arc::MAIN_COLOR_5, arc::MAIN_COLOR_5);

//     rect.setPosition(0, 4);
//     return (rect);
// }

// static arc::Rectangle initRect6()
// {
//     arc::Rectangle rect(1, 1, arc::MAIN_COLOR_6, arc::MAIN_COLOR_6);

//     rect.setPosition(0, 5);
//     return (rect);
// }

// static arc::Rectangle initRect7()
// {
//     arc::Rectangle rect(1, 1, arc::MAIN_COLOR_7, arc::MAIN_COLOR_7);

//     rect.setPosition(0, 6);
//     return (rect);
// }

// static arc::Rectangle initRect8()
// {
//     arc::Rectangle rect(1, 1, arc::MAIN_COLOR_8, arc::MAIN_COLOR_8);

//     rect.setPosition(0, 7);
//     return (rect);
// }

// static arc::Rectangle initRect9()
// {
//     arc::Rectangle rect(1, 1, arc::MAIN_COLOR_9, arc::MAIN_COLOR_9);

//     rect.setPosition(0, 8);
//     return (rect);
// }

static arc::Rectangle initRectInputUsername()
{
    arc::Rectangle rect(1, 20, arc::MAIN_COLOR_3, arc::MAIN_COLOR_3);

    rect.setPosition(110, 47);
    return (rect);
}

void arc::SceneMenu::initRects()
{
    static std::vector<Rectangle (*)()> rects = [this]() -> std::vector<Rectangle (*)()> {
        std::vector<Rectangle (*)()> rects;

        // rects.push_back(initRect);
        // rects.push_back(initRect2);
        // rects.push_back(initRect3);
        // rects.push_back(initRect4);
        // rects.push_back(initRect5);
        // rects.push_back(initRect6);
        // rects.push_back(initRect7);
        // rects.push_back(initRect8);
        // rects.push_back(initRect9);
        rects.push_back(initRectInputUsername);
        return (rects);
    }();

    _rects.clear();
    std::for_each(rects.begin(), rects.end(), [this](Rectangle (*fct)()) {
        _rects.push_back(fct());
    });
}