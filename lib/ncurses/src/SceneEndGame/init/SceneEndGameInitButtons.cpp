/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameInitButtons
*/

#include "ncurses/SceneEndGame.hpp"
#include "ncurses/ColorsMode.hpp"

using Pair = std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>;

static arc::Button initRestartButton(std::function<void()> &event)
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);

    rect.setPosition(150, 45);
    rect.setOutlineColors(arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);
    arc::Button button("Restart", rect, event);
    button.setColors(arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);
    return (button);
}

static arc::Button initMenuButton(std::function<void()> &event)
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);

    rect.setPosition(70, 45);
    rect.setOutlineColors(arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);
    arc::Button button("Menu", rect, event);
    button.setColors(arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);
    return (button);
}

void arc::SceneEndGame::initButtons()
{
    std::vector<Pair> buttons;

    buttons.push_back(Pair(initRestartButton, [this]() {
        _eventRestart();
    }));
    buttons.push_back(Pair(initMenuButton, [this]() {
        _eventMenu();
    }));

    _buttons.clear();

    std::for_each(buttons.begin(), buttons.end(), [this](Pair &pair) {
        _buttons.push_back(pair.first(pair.second));
    });
}