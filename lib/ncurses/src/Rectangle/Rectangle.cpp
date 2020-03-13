/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

arc::Rectangle::Rectangle(int height, int width) : _height(height), _width(width)
{
}

arc::Rectangle::~Rectangle()
{
}

void arc::Rectangle::setBackgroundColor(int r, int g, int b)
{
    _color.r = r;
    _color.g = g;
    _color.b = b;
}

void arc::Rectangle::setOutlineColor(int r, int g, int b)
{
    _outlineColor.r = r;
    _outlineColor.g = g;
    _outlineColor.b = b;
}



void arc::Rectangle::display()
{
    for (size_t h = 0; h < _height; h++) {
        for (size_t w = 0; w < _width; w++) {
            Utility::display(" ", _color, _color, h, w);
        }
    }
}