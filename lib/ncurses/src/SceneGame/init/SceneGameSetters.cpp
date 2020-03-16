/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameSetters
*/

#include "ncurses/SceneGame.hpp"

void arc::SceneGame::setFunctionBackToMenu(const std::function<void()> &fct)
{
    _eventBackToMenu = fct;
}

void arc::SceneGame::setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls)
{
    _controls = controls;
}