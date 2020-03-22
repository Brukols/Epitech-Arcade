/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneScoresInit
*/

#include "ncurses/SceneScores.hpp"
#include "ncurses/ColorsMode.hpp"

static arc::Button initButtonBack()
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);

    rect.setPosition(110, 45);
    rect.setOutlineColors(arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);
    arc::Button button("Back", rect, std::function<void()>());
    button.setColors(arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);
    return (button);
}

void arc::SceneScores::initButtons()
{
    std::vector<std::pair<arc::Button (*)(), void (SceneScores::*)()>> buttons;

    buttons.clear();
    buttons.push_back(std::pair<arc::Button (*)(), void (SceneScores::*)()>(initButtonBack, &SceneScores::eventButtonBack));

    _buttons.clear();
    std::for_each(buttons.begin(), buttons.end(), [this](std::pair<arc::Button (*)(), void (SceneScores::*)()> &pair) {
        _buttons.push_back(std::pair<Button, void (SceneScores::*)()>(pair.first(), pair.second));
    });
}

void arc::SceneScores::init()
{
    initButtons();
    _listScores.init();
}