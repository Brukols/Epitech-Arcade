/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameInitTexts
*/

#include "ncurses/SceneGame.hpp"
#include "ncurses/Utility.hpp"

static arc::Text initTitle(const std::string &name)
{
    arc::Text text(name, arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);

    text.setPosition(182, 3);
    return (text);
}

static arc::Text initStatsRect()
{
    arc::Text text(arc::Utility::getText("assets/ncurses/texts/stats.txt"), arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);

    text.setPosition(170, 10);
    return (text);
}

static arc::Text initHowToPlayRect()
{
    arc::Text text(arc::Utility::getText("assets/ncurses/texts/howtoplay.txt"), arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);

    text.setPosition(170, 28);
    return (text);
}

void arc::SceneGame::initTexts()
{
    _texts.clear();
    _texts.push_back(initTitle(_title));
    _texts.push_back(initStatsRect());
    _texts.push_back(initHowToPlayRect());
}