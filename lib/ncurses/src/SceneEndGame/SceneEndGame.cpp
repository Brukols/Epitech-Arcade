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

void setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    (void)scores;
}

void setUsername(const std::string &username)
{
    (void)username;
}