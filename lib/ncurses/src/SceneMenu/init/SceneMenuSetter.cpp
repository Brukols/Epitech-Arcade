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

void arc::SceneMenu::initButtonsListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct)
{
    (void)games;
    (void)fct;
}

void arc::SceneMenu::initButtonsListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct)
{
    (void)libraries;
    (void)fct;
}