/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitInputs
*/

#include "ncurses/SceneMenu.hpp"

arc::Input initInputUsername()
{
    arc::Rectangle rect(3, 20, arc::MAIN_COLOR_3, arc::MAIN_COLOR_3);

    rect.setPosition(180, 7);

    arc::Text text("Enter your username", arc::MAIN_COLOR_5, arc::BACKGROUND_COLOR);

    text.setPosition(180, 5);

    arc::Input input(rect, text);
    input.setColorsSelect(arc::MAIN_COLOR_8, arc::MAIN_COLOR_8);
    return (input);
}

void arc::SceneMenu::initInputs()
{
    _inputs.clear();
    _inputs.push_back(initInputUsername());
}