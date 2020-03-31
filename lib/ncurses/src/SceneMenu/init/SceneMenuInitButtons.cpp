/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitButtons
*/

#include "ncurses/SceneMenu.hpp"


static arc::Button initPlayButton()
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_1, arc::BACKGROUND_COLOR);

    rect.setPosition(110, 21);
    rect.setOutlineColors(arc::MAIN_COLOR_1, arc::MAIN_COLOR_1);
    arc::Button button("Play", rect, std::function<void()>());
    button.setColors(arc::MAIN_COLOR_1, arc::BACKGROUND_COLOR);
    return (button);
}

static arc::Button initExitButton()
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);

    rect.setPosition(110, 35);
    rect.setOutlineColors(arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);
    arc::Button button("Exit", rect, std::function<void()>());
    button.setColors(arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);
    return (button);
}

static arc::Button initShowScoresButton()
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);

    rect.setPosition(110, 28);
    rect.setOutlineColors(arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);
    arc::Button button("Show scores", rect, std::function<void()>());
    button.setColors(arc::MAIN_COLOR_2, arc::BACKGROUND_COLOR);
    return (button);
}

void arc::SceneMenu::initButtons()
{
    _buttons.clear();
    _buttons.push_back(std::pair<Button, void (SceneMenu::*)()>(initPlayButton(), &SceneMenu::eventPlay));
    _buttons.push_back(std::pair<Button, void (SceneMenu::*)()>(initExitButton(), &SceneMenu::eventExit));
    _buttons.push_back(std::pair<Button, void (SceneMenu::*)()>(initShowScoresButton(), &SceneMenu::eventShowScores));
}