/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneErrorInit
*/

#include "ncurses/SceneError.hpp"
#include "ncurses/defines.hpp"

void arc::SceneError::initRects()
{
    Rectangle rect(LINES, COLS, MAIN_COLOR_3, MAIN_COLOR_3);

    rect.setPosition(0, 0);
    _rects.clear();
    _rects.push_back(rect);
}

void arc::SceneError::initButtons()
{
    Rectangle rect(5, 25, MAIN_COLOR_1, BACKGROUND_COLOR);

    rect.setPosition(105, 30);
    rect.setOutlineColors(MAIN_COLOR_1, MAIN_COLOR_1);
    Button button("Ok", rect, _eventBack);
    button.setColors(MAIN_COLOR_1, BACKGROUND_COLOR);
    _buttons.clear();
    _buttons.push_back(button);
}

void arc::SceneError::initTexts()
{
    arc::Text text(_errorMsg, MAIN_COLOR_1, MAIN_COLOR_3);

    text.setPosition(COLS / 2 - _errorMsg.size() / 2, 25);
    _texts.clear();
    _texts.push_back(text);
}

void arc::SceneError::init()
{
    initRects();
    _texts.clear();
    _buttons.clear();
}