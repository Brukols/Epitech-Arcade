/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameInitButtons
*/

#include "ncurses/SceneGame.hpp"
#include "ncurses/defines.hpp"

arc::Button initBackToMenuButton(std::function<void()> &event)
{
    arc::Rectangle rect(5, 20, MAIN_COLOR_5, BACKGROUND_COLOR);

    rect.setPosition(180, 45);
    rect.setOutlineColors(MAIN_COLOR_5, MAIN_COLOR_5);
    arc::Button button("Back to menu", rect, event);
    button.setColors(MAIN_COLOR_2, BACKGROUND_COLOR);
    return (button);
}

void arc::SceneGame::initButtons()
{
    static std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> buttons = [this]() -> std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> {
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