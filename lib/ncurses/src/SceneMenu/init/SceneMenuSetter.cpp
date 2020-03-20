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
    List list(games, chosen, "Games", fct);
    list.setPosition(30, 20);
    _lists.push_back(list);
}

void arc::SceneMenu::setListLibraries(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    List list(games, chosen, "Libraries", fct);
    list.setPosition(170, 20);
    list.setColors(MAIN_COLOR_5, MAIN_COLOR_8, MAIN_COLOR_2, MAIN_COLOR_5, MAIN_COLOR_9);
    _lists.push_back(list);
}

void arc::SceneMenu::setUsername(const std::string &name)
{
    _inputs[0].setText(name);
    _username = name;
}