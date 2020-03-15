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

void arc::Rectangle::display()
{
    for (size_t h = 0; h < _height; h++) {
        for (size_t w = 0; w < _width; w++) {
            Utility::display(" ", h, w, _noPair);
        }
    }
}