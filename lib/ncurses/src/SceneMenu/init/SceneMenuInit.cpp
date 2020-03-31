/*
** EPITECH PROJECT, 2020
** Arvcade
** File description:
** Init
*/

#include "ncurses/SceneMenu.hpp"

void arc::SceneMenu::init()
{
    initTexts();
    initButtons();
    initInputs();
    setUsername(_username);
}