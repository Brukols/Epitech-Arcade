/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneGame
*/

#include "SceneGame.hpp"

void arc::SceneGame::init()
{
    _font.loadFromFile("resources/fonts/Raleway-Bold.ttf");
    initButtons();
    // initTexts();
    initRects();
}