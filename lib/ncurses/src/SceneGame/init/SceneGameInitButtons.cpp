/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameInitButtons
*/

#include "ncurses/SceneGame.hpp"


arc::Button initBackToMenuButton(std::function<void()> &event)
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_5, arc::BACKGROUND_COLOR);

    rect.setPosition(180, 45);
    rect.setOutlineColors(arc::MAIN_COLOR_5, arc::MAIN_COLOR_5);
    arc::Button button("Back to menu", rect, event);
    button.setColors(arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);
    return (button);
}

void arc::SceneGame::initButtons()
{
    std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> buttons = [this]() -> std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> {
        std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> buttons;

        buttons.push_back(std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>(initBackToMenuButton, [this]() {
            _eventBackToMenu();
        }));
        return (buttons);
    }();

    _buttons.clear();
    std::for_each(buttons.begin(), buttons.end(), [this](std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>> &pair) {
        _buttons.push_back(pair.first(pair.second));
    });
}