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
    if (!_display)
        return;
    Utility::display(_text, _x, _y, (_select == true && _noPairTextSelect != -1 ? _noPairTextSelect : _noPair));
}

void arc::Text::setSelect(bool select)
{
    if (!_display)
        return;
    _select = select;
}

void arc::Text::setColorsTextSelect(int textColor, int bgColor)
{
    _noPairTextSelect = Utility::generatePairColor(textColor, bgColor);
}

void arc::Text::setText(const std::string &newText)
{
    _text = newText;
}

void arc::Text::setDisplay(bool display)
{
    _display = display;
}