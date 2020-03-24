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
    list.setColor(sf::Color(133, 30, 62, 255), sf::Color(153, 50, 82, 255), sf::Color(103, 0, 81, 255));
    _lists.push_back(list);
}

void arc::SceneMenu::setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen)
{
    List list(libraries, chosen, "Libraries", fct, _font);

    list.setPosition(sf::Vector2f(1400, 300));
    list.desactivate();
    list.setColor(sf::Color(107, 130, 171, 255), sf::Color(67, 90, 131, 255), sf::Color(47, 70, 111, 255));
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

void arc::SceneMenu::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _sceneScores.setScores(scores);
}