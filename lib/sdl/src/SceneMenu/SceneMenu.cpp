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
}

void arc::SceneMenu::setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    _listGames.setNameList("Games");
}

void arc::SceneMenu::setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen)
{
    _listGraphical.setNameList("Libraries");
}