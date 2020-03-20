/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGame
*/

#include "sfml/SceneEndGame.hpp"

arc::SceneEndGame::SceneEndGame()
{
    if (!_font.loadFromFile("resources/sfml/fonts/Raleway-Bold.ttf")) {
        _exit = true;
        return;
    }
}

arc::SceneEndGame::~SceneEndGame()
{
}