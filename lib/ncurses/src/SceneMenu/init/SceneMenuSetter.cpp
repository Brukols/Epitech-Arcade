/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenuSetter
*/

#include "SceneMenu.hpp"

void arc::SceneMenu::setFunctionExit(std::function<void()> fct)
{
    _eventFunctionExit = fct;
}