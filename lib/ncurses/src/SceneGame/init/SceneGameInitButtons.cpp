/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameInitButtons
*/

#include "ncurses/SceneGame.hpp"


static arc::Button initBackToMenuButton()
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_5, arc::BACKGROUND_COLOR);

    rect.setPosition(180, 45);
    rect.setOutlineColors(arc::MAIN_COLOR_5, arc::MAIN_COLOR_5);
    arc::Button button("Back to menu", rect, std::function<void()>());
    button.setColors(arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);
    return (button);
}

void arc::SceneGame::initButtons()
{
    _buttons.clear();
    _buttons.push_back(std::pair<Button, void (SceneGame::*)()>(initBackToMenuButton(), &SceneGame::eventMenu));
}