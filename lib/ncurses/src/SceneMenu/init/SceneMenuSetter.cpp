/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenuSetter
*/

#include "ncurses/SceneMenu.hpp"

void arc::SceneMenu::setFunctionExit(std::function<void()> fct)
{
    _eventFunctionExit = fct;
}

void arc::SceneMenu::setFunctionPlay(const std::function<void()> &fct)
{
    _eventFunctionPlay = fct;
}

void arc::SceneMenu::setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    _eventListGames = fct;
    initButtonsListGames(games, fct, chosen);
}

void arc::SceneMenu::setListLibraries(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    _eventListLibs = fct;
    initButtonsListLibraries(games, fct, chosen);
}

void arc::SceneMenu::setUsername(const std::string &name)
{
    _inputs[0].setText(name);
    _username = name;
}