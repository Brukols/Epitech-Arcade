/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneGame
*/

#include "sfml/SceneGame.hpp"

void arc::SceneGame::init()
{
    _errorMessages.clear();
    _textureMap.clear();
    if (!_font.loadFromFile("resources/fonts/Raleway-Bold.ttf")) {
        _exit = true;
        return;
    }
    initButtons();
    // initTexts();
    initRects();
}