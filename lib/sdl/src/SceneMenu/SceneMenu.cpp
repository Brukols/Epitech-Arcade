/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenu
*/

#include "sdl/SceneMenu.hpp"

arc::SceneMenu::SceneMenu()
{
    _listGames.setFont(FONT);
    _listGraphical.setFont(FONT);
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