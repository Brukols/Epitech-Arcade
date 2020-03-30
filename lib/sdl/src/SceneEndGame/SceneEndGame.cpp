/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGame
*/

#include "sdl/SceneEndGame.hpp"

arc::SceneEndGame::SceneEndGame()
{
    _listScores = std::unique_ptr<ListScores>(new ListScores());
}

arc::SceneEndGame::~SceneEndGame()
{
}

void arc::SceneEndGame::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _listScores->setScores(scores);
}

void arc::SceneEndGame::setFunctionRestart(const std::function<void()> &function)
{
    _eventRestart = function;
}

void arc::SceneEndGame::setFunctionMenu(const std::function<void()> &function)
{
    _eventMenu = function;
}

void arc::SceneEndGame::setUsername(const std::string &name)
{
    _listScores->setUsername(name);
}