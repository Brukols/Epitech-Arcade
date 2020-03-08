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
    std::for_each(_buttons.begin(), _buttons.end(), [this](arc::SFMLButton &button) {
        button.displayButton(_window);
    });
}