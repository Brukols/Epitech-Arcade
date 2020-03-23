/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitTexts
*/

#include "sdl/SceneMenu.hpp"

static arc::Text initTextTitle()
{
    arc::Text text;

    text.setPosition(800, 50);
    text.setColor({255, 255, 255, 255});
    text.setFont(FONT, 100);
    text.setText("Arcade");
    return (text);
}

void arc::SceneMenu::initTexts()
{
    _texts.clear();
    _texts.push_back(initTextTitle());
}