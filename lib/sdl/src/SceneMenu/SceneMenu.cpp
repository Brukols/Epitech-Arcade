/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenu
*/

#include "sdl/SceneMenu.hpp"

arc::SceneMenu::SceneMenu()
{
    _sceneScores = std::unique_ptr<SceneScores>(new SceneScores());
    _listGames.setFont(FONT);
    _listGraphical.setFont(FONT);
    initInputUsername();
}

arc::SceneMenu::~SceneMenu()
{
    _texts.clear();
}

void arc::SceneMenu::setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    _listGames.setEventList(fct);
    _listGames.setNameList("Games");
    _listGames.setNameLibraries(games, chosen);
    _listGames.setPosition(600, 300);
}

void arc::SceneMenu::setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen)
{
    _listGraphical.setEventList(fct);
    _listGraphical.setNameList("Libraries");
    _listGraphical.setNameLibraries(libraries, chosen);
    _listGraphical.setPosition(1300, 300);
}

void arc::SceneMenu::setFunctionPlay(const std::function<void()> &function)
{
    _eventPlay = function;
}

void arc::SceneMenu::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _sceneScores->setScores(scores);
}

const std::string &arc::SceneMenu::getUsername()
{
    return (_inputUsername->getText());
}

void arc::SceneMenu::setUsername(const std::string &username)
{
    _inputUsername->setText(username);
}