/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneErrorInit
*/

#include "ncurses/SceneError.hpp"


void arc::SceneError::initRects()
{
    Rectangle rect(LINES, COLS, arc::MAIN_COLOR_3, arc::MAIN_COLOR_3);

    rect.setPosition(0, 0);
    _rects.clear();
    _rects.push_back(rect);
}

void arc::SceneError::initButtons()
{
    Rectangle rect(5, 25, arc::MAIN_COLOR_1, arc::BACKGROUND_COLOR);

    rect.setPosition(COLS / 2 - 25 / 2, LINES / 2 - 5);
    rect.setOutlineColors(arc::MAIN_COLOR_1, arc::MAIN_COLOR_1);
    Button button("Ok", rect, _eventBack);
    button.setColors(arc::MAIN_COLOR_1, arc::BACKGROUND_COLOR);
    button.setDisplay(false);
    _buttons.clear();
    _buttons.push_back(button);
}

void arc::SceneError::initTexts()
{
    arc::Text text(_errorMsg, arc::MAIN_COLOR_1, arc::MAIN_COLOR_3);

    text.setPosition(COLS / 2 - _errorMsg.size() / 2, 25);
    text.setDisplay(false);
    _texts.clear();
    _texts.push_back(text);
}

void arc::SceneError::init()
{
    initRects();
    initButtons();
    initTexts();
}