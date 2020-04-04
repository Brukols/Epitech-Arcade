/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitTexts
*/

#include "ncurses/SceneMenu.hpp"
#include "ncurses/Utility.hpp"

arc::Text initTitle()
{
    arc::Text text(arc::Utility::getText("assets/ncurses/texts/title.txt"), arc::MAIN_COLOR_1, arc::MAIN_COLOR_3);

    text.setPosition(85, 5);
    return (text);
}

arc::Text initTextChooseGame()
{
    arc::Text text("Choose a game", arc::MAIN_COLOR_6, arc::BACKGROUND_COLOR);

    text.setPosition(40, 20);
    return (text);
}

arc::Text initTextChooseGraph()
{
    arc::Text text("Choose a library", arc::MAIN_COLOR_5, arc::BACKGROUND_COLOR);

    text.setPosition(180, 20);
    return (text);
}

arc::Text initTextInputUsername()
{
    arc::Text text("Enter your username", arc::MAIN_COLOR_5, arc::BACKGROUND_COLOR);

    text.setPosition(110, 45);
    return (text);
}

arc::Text initTextHowToPlay()
{
    arc::Text text(arc::Utility::getText("assets/ncurses/texts/howtoplay.txt"), arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);

    text.setPosition(101, 42);
    return (text);
}

void arc::SceneMenu::initTexts()
{
    _texts.clear();
    _texts.push_back(initTitle());
    _texts.push_back(initTextChooseGame());
    _texts.push_back(initTextChooseGraph());
    _texts.push_back(initTextHowToPlay());
}