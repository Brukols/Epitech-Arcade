/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ScneeMneu
*/

#include "ncurses/SceneMenu.hpp"

arc::SceneMenu::SceneMenu()
{
    _lists.clear();
}

arc::SceneMenu::~SceneMenu()
{
}

const std::string &arc::SceneMenu::getUsername()
{
    return (_username);
}

void arc::SceneMenu::setHowToPlay(const std::vector<std::pair<std::string, std::string>> &info)
{
    _howToPlay.clear();
    int i = 0;
    std::for_each(info.begin(), info.end(), [this, &i](const std::pair<std::string, std::string> &pair) {
        arc::Text text(pair.first + " : " + pair.second, arc::MAIN_COLOR_1, arc::BACKGROUND_COLOR);

        text.setPosition(103, i + 44);
        _howToPlay.push_back(text);
        i++;
    });
}