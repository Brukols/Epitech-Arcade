/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneScores
*/

#include "sfml/SceneScores.hpp"

arc::SceneScores::SceneScores()
{
}

arc::SceneScores::~SceneScores()
{
}

void arc::SceneScores::setFont(const sf::Font &font)
{
    _listScores.setFont(font);
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