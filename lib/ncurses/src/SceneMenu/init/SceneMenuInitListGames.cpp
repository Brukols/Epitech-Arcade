/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitListGames
*/

#include "ncurses/SceneMenu.hpp"

static arc::Button initButton(const std::string &name, const std::function<void()> &fct, int y)
{
    arc::Rectangle rect(5, 20, COLOR_RED, COLOR_BLACK);

    rect.setPosition(28, y);
    rect.setOutlineColors(COLOR_WHITE, COLOR_RED);
    rect.setColorsSelect(COLOR_RED, COLOR_RED);
    arc::Button button(name, rect, fct);
    button.setColors(COLOR_WHITE, COLOR_BLACK);
    button.setColorsTextSelect(COLOR_WHITE, COLOR_RED);
    return (button);
}

static const std::string getLibName(const std::string &path)
{
    std::string tmp = path.substr(path.find("lib_arcade_"), path.length());

    tmp = tmp.substr(11, tmp.size() - 14);
    return (tmp);
}

void arc::SceneMenu::initButtonsListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct)
{
    int y = 27;
    _buttonsListGames.clear();

    std::for_each(games.begin(), games.end(), [this, &y, fct](const std::string &name) {
        _buttonsListGames.push_back(initButton(getLibName(name), [this]() {}, y));
        y += 10;
    });
}