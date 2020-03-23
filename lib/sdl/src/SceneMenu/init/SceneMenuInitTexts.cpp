/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitTexts
*/

#include "sdl/SceneMenu.hpp"

static arc::Text initTextExample()
{
    arc::Text text;

    text.setPosition(10, 10);
    text.setColor({255, 255, 255, 255});
    text.setFont(FONT, 22);
    return (text);
}

void arc::SceneMenu::initTexts()
{
    _texts.clear();
    _texts.push_back(initTextExample());
}