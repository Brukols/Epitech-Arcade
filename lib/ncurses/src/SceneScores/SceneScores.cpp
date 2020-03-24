/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneScores
*/

#include "ncurses/SceneScores.hpp"

arc::SceneScores::SceneScores()
{
}

arc::SceneScores::~SceneScores()
{
}

void arc::SceneScores::setUsername(const std::string &username)
{
    _listScores.setUsername(username);
}

void arc::SceneScores::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _listScores.setScores(scores);
}

bool arc::SceneScores::isActivate() const
{
    return (_activate);
}

void arc::SceneScores::setActivate(bool activate)
{
    _activate = activate;
}

void arc::SceneScores::setEventFunctionExit(const std::function<void()> &event)
{
    _eventFunctionExit = event;
}