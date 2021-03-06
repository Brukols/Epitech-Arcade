/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ButtonRect
*/

#include "sdl/ButtonRect.hpp"
#include <memory>
#include "sdl/Utility.hpp"

arc::ButtonRect::ButtonRect()
{
}

arc::ButtonRect::~ButtonRect()
{
}

void arc::ButtonRect::setRect(const Rectangle &rect)
{
    _rect = rect;
    _color = rect.getColor();
}

void arc::ButtonRect::setText(Text *text)
{
    _text = std::shared_ptr<Text>(text);
}

void arc::ButtonRect::setPosition(size_t x, size_t y)
{
    _rect.setPosition(x, y);
    _text->setPosition(x + _rect.getRect().w / 2 - _text->getWidth() / 2, y + _rect.getRect().h / 2 - _text->getHeight() / 2);
}

void arc::ButtonRect::setColorHover(const SDL_Color &color)
{
    _colorHover = color;
}

bool arc::ButtonRect::isMouseHover(int x, int y) const
{
    if (x > _rect.getRect().x && x < _rect.getRect().x + _rect.getRect().w && y > _rect.getRect().y && y < _rect.getRect().y + _rect.getRect().h)
        return (true);
    return (false);
}

void arc::ButtonRect::display(SDL_Renderer *window)
{
    int x;
    int y;

    SDL_GetMouseState(&x, &y);
    if (!_activate) {
        _rect.setColor(_colorDisable);
        if (isMouseHover(x, y))
            Utility::changeCursor(SDL_SYSTEM_CURSOR_NO);
    } else if (_select) {
        _rect.setColor(_colorSelect);
        if (isMouseHover(x, y))
            Utility::changeCursor(SDL_SYSTEM_CURSOR_NO);
    } else if (isMouseHover(x, y)) {
        _rect.setColor(_colorHover);
        Utility::changeCursor(SDL_SYSTEM_CURSOR_HAND);
    } else {
        _rect.setColor(_color);
    }
    _rect.display(window);
    _text->display(window);
}

int arc::ButtonRect::getPosX() const
{
    return (_rect.getRect().x);
}

int arc::ButtonRect::getPosY() const
{
    return (_rect.getRect().y);
}

void arc::ButtonRect::setColor(const SDL_Color &color)
{
    _color = color;
}

void arc::ButtonRect::setColorSelect(const SDL_Color &color)
{
    _colorSelect = color;
}

void arc::ButtonRect::setSelect(bool select)
{
    _select = select;
}

bool arc::ButtonRect::isSelect() const
{
    return (_select);
}

const std::string &arc::ButtonRect::getText() const
{
    return (_text->getString());
}

bool arc::ButtonRect::isActivate() const
{
    return (_activate);
}

void arc::ButtonRect::setActivate(bool activate)
{
    _activate = activate;
}