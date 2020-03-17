/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneGame
*/

#include "sfml/SceneGame.hpp"

void arc::SceneGame::init()
{
    _font.loadFromFile("resources/fonts/Raleway-Bold.ttf");
    initButtons();
    // initTexts();
    initRects();
}