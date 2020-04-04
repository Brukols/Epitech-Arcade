/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGame
*/

#include "sfml/SceneEndGame.hpp"
#include "sfml/SFMLErrors.hpp"

arc::SceneEndGame::SceneEndGame()
{
    if (!_font.loadFromFile("assets/sfml/fonts/Raleway-Bold.ttf")) {
        throw FontError("Unable to load the font", "SceneEndGame");
    }
    _listScores.setFont(_font);
}

arc::SceneEndGame::~SceneEndGame()
{
}