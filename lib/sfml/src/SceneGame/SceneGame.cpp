/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneGame
*/

#include "sfml/SceneGame.hpp"

arc::SceneGame::SceneGame()
{
    _scenePause = std::unique_ptr<ScenePause>(new ScenePause());
}

arc::SceneGame::~SceneGame()
{
}


void arc::SceneGame::setFunctionTogglePause(const std::function<void()> &function)
{
    _scenePause->setFunctionTogglePause(function);
}

void arc::SceneGame::setFunctionMenu(const std::function<void()> &function)
{
    _eventFunctionBackToMenu = function;
}

void arc::SceneGame::eventFunctionBackToMenu()
{
    _eventFunctionBackToMenu();
}

void arc::SceneGame::setGamePause(bool pause)
{
    _scenePause->setActivate(pause);
}