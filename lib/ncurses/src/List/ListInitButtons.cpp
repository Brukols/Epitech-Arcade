/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListInitButtons
*/

#include "ncurses/List.hpp"
#include "ncurses/ColorsMode.hpp"

static arc::Button initButtonKeyDown(std::function<void()> &event)
{
    arc::Rectangle rect(3, 38, arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);

    rect.setPosition(31, 46);
    rect.setOutlineColors(arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);
    arc::Button button("Down", rect, event);
    button.setColors(arc::MAIN_COLOR_3, arc::MAIN_COLOR_2);
    return (button);
}

static arc::Button initButtonKeyUp(std::function<void()> &event)
{
    arc::Rectangle rect(3, 38, arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);

    rect.setPosition(31, 25);
    rect.setOutlineColors(arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);
    arc::Button button("Up", rect, event);
    button.setColors(arc::MAIN_COLOR_3, arc::MAIN_COLOR_2);
    return (button);
}

void arc::List::initButtons()
{
    std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> buttons = [this]() -> std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> {
        std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> buttons;

        buttons.push_back(std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>(initButtonKeyDown, [this]() {}));
        buttons.push_back(std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>(initButtonKeyUp, [this]() {}));
        return (buttons);
    }();

    _buttons.clear();
    std::for_each(buttons.begin(), buttons.end(), [this](std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>> &pair) {
        _buttons.push_back(pair.first(pair.second));
    });
}

static arc::Button initButton(const std::string &name, const std::function<void()> &fct, int y)
{
    arc::Rectangle rect(3, 38, arc::MAIN_COLOR_6, arc::MAIN_COLOR_3);

    rect.setPosition(31, y);
    rect.setColorsSelect(arc::MAIN_COLOR_5, arc::MAIN_COLOR_6);
    arc::Button button(name, rect, fct);
    button.setColors(COLOR_WHITE, arc::BACKGROUND_COLOR);
    button.setColorsTextSelect(arc::MAIN_COLOR_3, arc::MAIN_COLOR_6);
    return (button);
}

static const std::string getLibName(const std::string &path)
{
    std::string tmp = path.substr(path.find("lib_arcade_"), path.length());

    tmp = tmp.substr(11, tmp.size() - 14);
    return (tmp);
}

void arc::List::initButtonsList(const std::vector<std::string> &list, int chosen, const std::function<void(const std::string &)> &fct)
{
    int y = 28;
    _buttonsList.clear();

    int i = 0;
    std::for_each(list.begin(), list.end(), [this, &y, &i, &chosen, &fct](const std::string &name) {
        if (i == chosen) {
            _buttonsList.push_back(initButton(getLibName(name), []() {}, y));
            _buttonsList[_buttonsList.size() - 1].toggleSelect();
        } else {
            _buttonsList.push_back(initButton(getLibName(name), [this, name, fct]() {
                fct(name);
            }, y));
        }
        y += 3;
        i++;
    });
}