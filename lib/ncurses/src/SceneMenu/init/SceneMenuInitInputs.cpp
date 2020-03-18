/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitInputs
*/

#include "ncurses/SceneMenu.hpp"

arc::Input initInputUsername()
{
    arc::Rectangle rect(3, 20, arc::MAIN_COLOR_3, arc::MAIN_COLOR_3);

    rect.setPosition(110, 47);

    arc::Text text("Enter your username", arc::MAIN_COLOR_5, arc::BACKGROUND_COLOR);

    text.setPosition(110, 45);

    arc::Input input(rect, text);
    input.setColorsSelect(arc::MAIN_COLOR_8, arc::MAIN_COLOR_8);
    return (input);
}

void arc::SceneMenu::initInputs()
{
    static std::vector<Input (*)()> inputs = [this]() -> std::vector<Input (*)()> {
        std::vector<Input (*)()> inputs;

        inputs.push_back(initInputUsername);
        return (inputs);
    }();

    _inputs.clear();
    std::for_each(inputs.begin(), inputs.end(), [this](Input (*fct)()) {
        _inputs.push_back(fct());
    });
}