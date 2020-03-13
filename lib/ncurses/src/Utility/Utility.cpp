/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Utility
*/

#include "Utility.hpp"

void arc::Utility::display(const std::string &text, Color &textColor, Color &bgColor, int x, int y)
{
    init_color(1, textColor.r, textColor.g, textColor.b);
    init_color(2, bgColor.r, bgColor.g, bgColor.b);
    init_pair(1, 1, 2);
    mvprintw(x, y, text.c_str());
}