/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GraphiclaDislayMEnu
*/

#include "Graphical.hpp"
#include <iostream>

void arc::Graphical::displayMenu()
{
    // Display buttons

    std::for_each(_buttons.begin(), _buttons.end(), [this](arc::Button &button) {
        button.displayButton(_window);
    });

    // Displays text
    std::for_each(_text.begin(), _text.end(), [this](arc::Text &text) {
        text.display(_window);
    });
}