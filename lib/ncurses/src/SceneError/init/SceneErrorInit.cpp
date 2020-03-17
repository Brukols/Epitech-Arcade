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
    Rectangle rect(100, 100, MAIN_COLOR_1, MAIN_COLOR_1);

    rect.setPosition(0, 0);
    _rects.clear();
    _rects.push_back(rect);
}

void arc::SceneError::initButtons()
{
    Rectangle rect(5, 20, MAIN_COLOR_1, BACKGROUND_COLOR);

    rect.setPosition(110, 25);
    rect.setOutlineColors(MAIN_COLOR_1, MAIN_COLOR_1);
    Button button("Ok", rect, _eventBack);
    button.setColors(MAIN_COLOR_1, BACKGROUND_COLOR);
    _buttons.clear();
    _buttons.push_back(button);
}

void arc::SceneError::initTexts()
{
    arc::Text text(_errorMsg, MAIN_COLOR_1, MAIN_COLOR_3);

    text.setPosition(85, 5);
    _texts.clear();
    _texts.push_back(text);
}

void arc::SceneError::init()
{
    initRects();
    _texts.clear();
    _buttons.clear();
}