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
    Utility::display(_text, _x, _y, (_select == true && _noPairTextSelect != -1 ? _noPairTextSelect : _noPair));
}

void arc::Text::setSelect(bool select)
{
    _select = select;
}

void arc::Text::setColorsTextSelect(int textColor, int bgColor)
{
    _noPairTextSelect = Utility::generatePairColor(textColor, bgColor);
}