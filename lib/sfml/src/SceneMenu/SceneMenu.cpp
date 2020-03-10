/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenu
*/

#include "SceneMenu.hpp"
#include <SFML/Graphics.hpp>

arc::SceneMenu::SceneMenu()
{
    initButtons();
    _font.loadFromFile("resources/fonts/Raleway-Bold.ttf");
    initTexts();
}

arc::SceneMenu::~SceneMenu()
{
}