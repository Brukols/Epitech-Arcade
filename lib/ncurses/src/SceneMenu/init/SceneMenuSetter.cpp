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

void arc::SceneMenu::setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    (void)chosen;
    initButtonsListGames(games, fct);
}

void arc::SceneMenu::setListLibraries(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    (void)chosen;
    initButtonsListLibraries(games, fct);
}