/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitListLibraries
*/

#include "ncurses/SceneMenu.hpp"


static arc::Button initButton(const std::string &name, const std::function<void()> &fct, int y)
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_5, arc::BACKGROUND_COLOR);

    rect.setPosition(178, y);
    rect.setOutlineColors(arc::MAIN_COLOR_5, arc::MAIN_COLOR_5);
    rect.setColorsSelect(arc::MAIN_COLOR_5, arc::MAIN_COLOR_5);
    arc::Button button(name, rect, fct);
    button.setColors(COLOR_WHITE, arc::BACKGROUND_COLOR);
    button.setColorsTextSelect(arc::MAIN_COLOR_3, arc::MAIN_COLOR_5);
    return (button);
}

static const std::string getLibName(const std::string &path)
{
    std::string tmp = path.substr(path.find("lib_arcade_"), path.length());

    tmp = tmp.substr(11, tmp.size() - 14);
    return (tmp);
}

void arc::SceneMenu::initButtonsListLibraries(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    int y = 27;
    _buttonsListLibraries.clear();

    int i = 0;
    std::for_each(games.begin(), games.end(), [this, &y, fct, &i, &chosen](const std::string &name) {
        if (i == chosen) {
            _buttonsListLibraries.push_back(initButton(getLibName(name), [this, &fct, name]() {}, y));
        } else {
            _buttonsListLibraries.push_back(initButton(getLibName(name), [this, &fct, name]() {
                _eventListLibs(name);
            }, y));
        }
        y += 6;
        i++;
    });

    i = 0;
    std::for_each(_buttonsListLibraries.begin(), _buttonsListLibraries.end(), [this, &i, &chosen](Button &button) {
        if (i == chosen) {
            button.toggleSelect();
        }
        i++;
    });
}