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

void arc::Rectangle::display()
{
    for (size_t h = 0; h < _height; h++) {
        for (size_t w = 0; w < _width; w++) {
            Utility::display(" ", w + _x, h + _y, _noPair);
        }
    }
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