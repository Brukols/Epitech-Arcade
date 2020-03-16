/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitButtons
*/

#include "ncurses/SceneMenu.hpp"

arc::Button initPlayButton(std::function<void()> &event)
{
    arc::Rectangle rect(5, 20, COLOR_BLUE, COLOR_BLACK);

    rect.setPosition(100, 25);
    rect.setOutlineColors(COLOR_WHITE, COLOR_WHITE);
    arc::Button button("Play", rect, event);
    button.setColors(COLOR_WHITE, COLOR_BLACK);
    return (button);
}

arc::Button initExitButton(std::function<void()> &event)
{
    arc::Rectangle rect(5, 20, COLOR_BLUE, COLOR_BLACK);

    rect.setPosition(100, 35);
    rect.setOutlineColors(COLOR_WHITE, COLOR_WHITE);
    arc::Button button("Exit", rect, event);
    button.setColors(COLOR_WHITE, COLOR_BLACK);
    return (button);
}

void arc::SceneMenu::initButtons()
{
    static std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> buttons = [this]() -> std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> {
        std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> buttons;

        buttons.push_back(std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>(initPlayButton, [this]() {
            _eventFunctionPlay();
        }));
        buttons.push_back(std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>(initExitButton, _eventFunctionExit));
        return (buttons);
    }();

    _buttons.clear();
    std::for_each(buttons.begin(), buttons.end(), [this](std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>> &pair) {
        _buttons.push_back(pair.first(pair.second));
    });
}