/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneError
*/

#include "ncurses/SceneError.hpp"

arc::SceneError::SceneError()
{
}

arc::SceneError::~SceneError()
{
}

void arc::SceneError::clear()
{
    _buttons[0].setDisplay(false);
    _texts[0].setDisplay(false);
}

void arc::SceneError::setFunctionBack(const std::function<void()> &eventBack)
{
    _eventBack = eventBack;
    _buttons[0].setEvent(eventBack);
    _buttons[0].setDisplay(true);
}

void arc::SceneError::setErrorMessage(const std::string &msg)
{
    _errorMsg = msg;
    _texts[0].setText(_errorMsg);
    _texts[0].setDisplay(true);
    _texts[0].setPosition(COLS / 2 - _errorMsg.size() / 2, 25);
}