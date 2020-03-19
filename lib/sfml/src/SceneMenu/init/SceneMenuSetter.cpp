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
    List list(games, chosen, "Games", fct, _font);

    list.setPosition(sf::Vector2f(100, 300));
    list.desactivate();
    _lists.push_back(list);
}

void arc::SceneMenu::setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen)
{
    List list(libraries, chosen, "Libraries", fct, _font);

    list.setPosition(sf::Vector2f(1400, 300));
    list.desactivate();
    _lists.push_back(list);
}

void arc::SceneMenu::setUsername(const std::string &name)
{
    if (name.size() == 0)
        return;
    eventValidateUsername();
    _username = name;
    _texts[_texts.size() - 1].setText("Username : " + _username);
}