/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScoresInit
*/

#include "ncurses/ListScores.hpp"
#include "ncurses/ColorsMode.hpp"

static arc::Rectangle initBackgroundRect()
{
    arc::Rectangle rect(30, 120, arc::MAIN_COLOR_8, arc::MAIN_COLOR_8);

    rect.setPosition(60, 5);
    return (rect);
}

void arc::ListScores::initRects()
{
    std::vector<Rectangle (*)()> rects;

    rects.push_back(initBackgroundRect);

    _rects.clear();
    std::for_each(rects.begin(), rects.end(), [this](Rectangle (*fct)()) {
        _rects.push_back(fct());
    });
}

void arc::ListScores::initTexts()
{
    _texts.clear();
}

void arc::ListScores::initButtons()
{
    _buttons.clear();
}

void arc::ListScores::initTextsScores()
{
    _textScores.clear();
}

void arc::ListScores::init()
{
    initRects();
    initButtons();
    initTexts();
    initTextsScores();
}