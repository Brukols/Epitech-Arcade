/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneGame
*/

#include "sfml/SceneGame.hpp"
#include "sfml/SFMLErrors.hpp"

void arc::SceneGame::init()
{
    _errorMessages.clear();
    _textureMap.clear();
    if (!_font.loadFromFile("resources/sfml/fonts/Raleway-Bold.ttf")) {
        throw FontError("Unable to load the font", "SceneGame");
    }
    _scenePause->setFont(_font);
    initButtons();
    initTexts();
    initRects();
}