/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Rectangle
*/

#include "ncurses/Rectangle.hpp"

arc::Rectangle::Rectangle(int height, int width, int textColor, int bgColor) : _height(height), _width(width)
{
    _noPair = arc::Utility::generatePairColor(textColor, bgColor);
}

arc::Rectangle::~Rectangle()
{
}

void arc::Rectangle::setPosition(size_t x, size_t y)
{
    _x = x;
    _y = y;
}

void arc::Rectangle::setOutlineColors(int textColor, int bgColor)
{
    _noPairOutline = Utility::generatePairColor(textColor, bgColor);
}

void arc::Rectangle::display()
{
    for (size_t h = 0; h < _height; h++) {
        for (size_t w = 0; w < _width; w++) {
            if ((w == 0 || h == 0 || w + 1 == _width || h + 1 == _height) && _noPairOutline != -1)
                Utility::display(" ", w + _x, h + _y, _noPairOutline);
            else
                Utility::display(" ", w + _x, h + _y, (_select == true && _noPairSelect != -1 ? _noPairSelect : _noPair));
        }
    }
}

void arc::Rectangle::setColorsSelect(int textColor, int bgColor)
{
    _noPairSelect = Utility::generatePairColor(textColor, bgColor);
}

void arc::Rectangle::setSelect(bool select)
{
    _select = select;
}

const size_t &arc::Rectangle::getHeight() const
{
    return (_height);
}

const size_t &arc::Rectangle::getWidth() const
{
    return (_width);
}

const size_t &arc::Rectangle::getPosX() const
{
    return (_x);
}

const size_t &arc::Rectangle::getPosY() const
{
    return (_y);
}