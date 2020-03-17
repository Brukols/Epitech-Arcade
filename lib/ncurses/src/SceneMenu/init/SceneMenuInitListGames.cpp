/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitListGames
*/

#include "ncurses/SceneMenu.hpp"
#include "ncurses/defines.hpp"

static arc::Button initButton(const std::string &name, const std::function<void()> &fct, int y)
{
    arc::Rectangle rect(5, 20, MAIN_COLOR_6, BACKGROUND_COLOR);

    rect.setPosition(28, y);
    rect.setOutlineColors(MAIN_COLOR_6, MAIN_COLOR_6);
    rect.setColorsSelect(MAIN_COLOR_6, MAIN_COLOR_6);
    arc::Button button(name, rect, fct);
    button.setColors(MAIN_COLOR_2, BACKGROUND_COLOR);
    button.setColorsTextSelect(MAIN_COLOR_2, MAIN_COLOR_6);
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
        _buttonsListGames.push_back(initButton(getLibName(name), [this, &fct, name]() {
            _eventListGames(name);
        }, y));
        y += 7;
    });
}