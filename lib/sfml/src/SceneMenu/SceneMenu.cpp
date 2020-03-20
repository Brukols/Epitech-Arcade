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
    if (!_font.loadFromFile("resources/sfml/fonts/Raleway-Bold.ttf")) {
        _exit = true;
        return;
    }
    initButtons();
    initTexts();
    initInput();
    initRects();
    initImages();
    _lists.clear();
}

arc::SceneMenu::~SceneMenu()
{
}

const std::string &arc::SceneMenu::getUsername()
{
    return (_username);
}