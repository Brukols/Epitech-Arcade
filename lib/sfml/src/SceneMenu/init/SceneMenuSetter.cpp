/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** MenuSetter
*/

#include "sfml/SceneMenu.hpp"

void arc::SceneMenu::setFunctionExit(const std::function<void()> &eventExit)
{
    _eventExit = eventExit;
    initButtons();
}

void arc::SceneMenu::setFunctionPlay(const std::function<void()> &eventPlay)
{
    _eventPlay = eventPlay;
    initButtons();
}

void arc::SceneMenu::setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    _eventListGames = fct;
    initButtonsListGames(games, fct, chosen);
}

void arc::SceneMenu::setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen)
{
    _eventListLibs = fct;
    initButtonsListLibraries(libraries, fct, chosen);
}

void arc::SceneMenu::setUsername(const std::string &name)
{
    if (name.size() == 0)
        return;
    eventValidateUsername();
    _username = name;
    _texts[_texts.size() - 1].setText("Username : " + _username);
}