/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Rectangle
*/

#include "sdl/Rectangle.hpp"

arc::Rectangle::Rectangle()
{
}

arc::Rectangle::~Rectangle()
{
}

void arc::Rectangle::setPosition(size_t x, size_t y)
{
    _rect.x = x;
    _rect.y = y;
}

void arc::Rectangle::setSize(size_t w, size_t h)
{
    _rect.w = w;
    _rect.h = h;
}

void arc::Rectangle::setColor(const SDL_Color &color)
{
    _color = color;
}

void arc::Rectangle::display(SDL_Renderer *window)
{
    SDL_SetRenderDrawColor(window, _color.r, _color.g, _color.b, _color.a);
    SDL_RenderFillRect(window, &_rect);
}

const SDL_Rect &arc::Rectangle::getRect() const
{
    return (_rect);
}