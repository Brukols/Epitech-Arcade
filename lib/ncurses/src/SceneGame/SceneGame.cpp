/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGame
*/

#include "ncurses/SceneGame.hpp"

arc::SceneGame::SceneGame()
{
    _scenePause = std::unique_ptr<ScenePause>(new ScenePause());
}

arc::SceneGame::~SceneGame()
{
}

void arc::SceneGame::setGamePause(bool pause)
{
    clear();
    _scenePause->setActivate(pause);
}

void arc::SceneGame::setFunctionTogglePause(const std::function<void()> &function)
{
    _scenePause->setFunctionTogglePause(function);
}