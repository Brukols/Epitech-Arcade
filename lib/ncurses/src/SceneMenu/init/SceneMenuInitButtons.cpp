/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitButtons
*/

#include "ncurses/SceneMenu.hpp"


arc::Button initPlayButton(std::function<void()> &event)
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_1, arc::BACKGROUND_COLOR);

    rect.setPosition(110, 25);
    rect.setOutlineColors(arc::MAIN_COLOR_1, arc::MAIN_COLOR_1);
    arc::Button button("Play", rect, event);
    button.setColors(arc::MAIN_COLOR_1, arc::BACKGROUND_COLOR);
    return (button);
}

arc::Button initExitButton(std::function<void()> &event)
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);

    rect.setPosition(110, 35);
    rect.setOutlineColors(arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);
    arc::Button button("Exit", rect, event);
    button.setColors(arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);
    return (button);
}

void arc::SceneMenu::initButtons()
{
    std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> buttons = [this]() -> std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> {
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