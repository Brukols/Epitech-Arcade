/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#include "ncurses/Text.hpp"

arc::Text::Text(const std::string &name, int textColor, int bgColor) : _text(name)
{
    _noPair = Utility::generatePairColor(textColor, bgColor);
}

arc::Text::~Text()
{
}

void arc::Text::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void arc::Text::display()
{
    Utility::display(_text, _x, _y, _noPair);
}