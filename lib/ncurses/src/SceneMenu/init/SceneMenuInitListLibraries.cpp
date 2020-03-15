/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitListLibraries
*/

#include "ncurses/SceneMenu.hpp"

static arc::Button initButton(const std::string &name, const std::function<void()> &fct, int y)
{
    arc::Rectangle rect(5, 20, COLOR_BLUE, COLOR_BLACK);

    rect.setPosition(168, y);
    rect.setOutlineColors(COLOR_WHITE, COLOR_BLUE);
    rect.setColorsSelect(COLOR_BLUE, COLOR_BLUE);
    arc::Button button(name, rect, fct);
    button.setColors(COLOR_WHITE, COLOR_BLACK);
    button.setColorsTextSelect(COLOR_WHITE, COLOR_BLUE);
    return (button);
}

void arc::SceneMenu::initButtonsListLibraries(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct)
{
    int y = 27;
    _buttonsListLibraries.clear();

    std::for_each(games.begin(), games.end(), [this, &y, fct](const std::string &name) {
        _buttonsListLibraries.push_back(initButton(name, [this]() {}, y));
        y += 10;
    });
}