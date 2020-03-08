/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLGraphiclaDislayMEnu
*/

#include "SFMLGraphical.hpp"
#include <iostream>

void arc::SFMLGraphical::displayMenu()
{
    // Display buttons

    std::for_each(_buttons.begin(), _buttons.end(), [this](arc::SFMLButton &button) {
        button.displayButton(_window);
    });

    // Displays text
    std::for_each(_text.begin(), _text.end(), [this](arc::SFMLText &text) {
        text.display(_window);
    });
}