/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ButtonRect
*/

#include "sdl/ButtonRect.hpp"

arc::ButtonRect::ButtonRect()
{
}

arc::ButtonRect::~ButtonRect()
{
}

void arc::ButtonRect::setRect(const Rectangle &rect)
{
    _rect = rect;
}

void arc::ButtonRect::setText(const Text &text)
{
    _text = text;
}

void arc::ButtonRect::setPosition(size_t x, size_t y)
{
    _rect.setPosition(x, y);
    _text.setPosition(x + _rect.getRect().w / 2 - _text.getWidth(), y + _rect.getRect().h / 2 - _text.getHeight() / 2);
}

bool arc::ButtonRect::isMouseHover(size_t x, size_t y) const
{
    if (x > _rect.getRect().x && x < _rect.getRect().x + _rect.getRect().w && y > _rect.getRect().y && y < _rect.getRect().y + _rect.getRect().h)
        return (true);
    return (false);
}

void arc::ButtonRect::display(SDL_Renderer *window)
{
    _rect.display(window);
    _text.display(window);
}