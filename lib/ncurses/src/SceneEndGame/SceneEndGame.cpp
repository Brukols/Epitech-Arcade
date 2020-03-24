/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGame
*/

#include "ncurses/SceneEndGame.hpp"

arc::SceneEndGame::SceneEndGame()
{
}

arc::SceneEndGame::~SceneEndGame()
{
}

void arc::SceneEndGame::setFunctionMenu(const std::function<void()> &function)
{
    _eventMenu = function;
}

void arc::SceneEndGame::setFunctionRestart(const std::function<void()> &function)
{
    _eventRestart = function;
}

void arc::SceneEndGame::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _listScores.setScores(scores);
}

void arc::SceneEndGame::setUsername(const std::string &username)
{
    _listScores.setUsername(username);
}