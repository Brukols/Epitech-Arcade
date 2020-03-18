/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenu
*/

#include "sfml/SceneMenu.hpp"
#include <SFML/Graphics.hpp>

arc::SceneMenu::SceneMenu()
{
    _font.loadFromFile("resources/fonts/Raleway-Bold.ttf");
    initButtons();
    initTexts();
    initInput();
    initRects();
    initImages();
}

arc::SceneMenu::~SceneMenu()
{
}