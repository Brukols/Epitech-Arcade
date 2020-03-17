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
    _buttons.clear();
    _texts.clear();
}

void arc::SceneError::setFunctionBack(const std::function<void()> &eventBack)
{
    _eventBack = eventBack;
    initButtons();
}

void arc::SceneError::setErrorMessage(const std::string &msg)
{
    _errorMsg = msg;
    initTexts();
}