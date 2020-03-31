/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameInitButtons
*/

#include "ncurses/SceneEndGame.hpp"
#include "ncurses/ColorsMode.hpp"

static arc::Button initRestartButton()
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);

    rect.setPosition(150, 45);
    rect.setOutlineColors(arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);
    arc::Button button("Restart", rect, std::function<void()>());
    button.setColors(arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);
    return (button);
}

static arc::Button initMenuButton()
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);

    rect.setPosition(70, 45);
    rect.setOutlineColors(arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);
    arc::Button button("Menu", rect, std::function<void()>());
    button.setColors(arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);
    return (button);
}

void arc::SceneEndGame::initButtons()
{
    _buttons.clear();
    _buttons.push_back(std::pair<Button, void (SceneEndGame::*)()>(initRestartButton(), &SceneEndGame::eventRestart));
    _buttons.push_back(std::pair<Button, void (SceneEndGame::*)()>(initMenuButton(), &SceneEndGame::eventMenu));
}