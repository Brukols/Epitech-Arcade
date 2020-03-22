/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameInitTextStats
*/

#include "ncurses/SceneGame.hpp"

static arc::Text initText(const std::string &index, const std::string &value, int y)
{
    arc::Text text(index + " : " + value, arc::MAIN_COLOR_5, arc::BACKGROUND_COLOR);

    text.setPosition(172, y);
    return (text);
}

void arc::SceneGame::initTextStats(const std::vector<std::pair<std::string, std::string>> &info)
{
    _stats.clear();

    int y = 11;
    std::for_each(info.begin(), info.end(), [this, &y](const std::pair<std::string, std::string> &pair) {
        _stats.push_back(initText(pair.first, pair.second, y));
        y += 1;
    });
}