/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitTexts
*/

#include "ncurses/SceneMenu.hpp"
#include "ncurses/Utility.hpp"
#include "ncurses/defines.hpp"

arc::Text initTitle()
{
    arc::Text text(arc::Utility::getText("resources/ncurses/texts/title.txt"), MAIN_COLOR_1, MAIN_COLOR_3);

    text.setPosition(85, 5);
    return (text);
}

arc::Text initTextChooseGame()
{
    arc::Text text("Choose a game", MAIN_COLOR_6, BACKGROUND_COLOR);

    text.setPosition(30, 20);
    return (text);
}

arc::Text initTextChooseGraph()
{
    arc::Text text("Choose a library", MAIN_COLOR_5, BACKGROUND_COLOR);

    text.setPosition(170, 20);
    return (text);
}

void arc::SceneMenu::initTexts()
{
    static std::vector<Text (*)()> texts = [this]() -> std::vector<Text (*)()> {
        std::vector<Text (*)()> texts;

        texts.push_back(initTitle);
        texts.push_back(initTextChooseGame);
        texts.push_back(initTextChooseGraph);
        return (texts);
    }();

    _texts.clear();
    std::for_each(texts.begin(), texts.end(), [this](Text (*fct)()) {
        _texts.push_back(fct());
    });
}