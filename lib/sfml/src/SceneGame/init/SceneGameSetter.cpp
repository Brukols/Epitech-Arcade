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