/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ScneeMneu
*/

#include "ncurses/SceneMenu.hpp"

arc::SceneMenu::SceneMenu()
{
    _lists.clear();
}

arc::SceneMenu::~SceneMenu()
{
}

const std::string &arc::SceneMenu::getUsername()
{
    return (_username);
}