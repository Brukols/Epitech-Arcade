/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneGame
*/

#include "SceneGame.hpp"

void arc::SceneGame::eventFunctionBackToMenu(std::function<void()> event)
{
    _eventFunctionBackToMenu = event;
}

void arc::SceneGame::setMapSize(size_t height, size_t width)
{
    _mapHeight = height;
    _mapWidth = width;
}