/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Buton
*/

#include "ncurses/Button.hpp"

arc::Button::Button(const std::string &name, const Rectangle &rect, const std::function<void()> &event) : _name(name), _rect(rect), _event(event)
{
}

arc::Button::~Button()
{
}

void arc::Button::setColors(int textColor, int bgColor)
{
    _noPair = Utility::generatePairColor(textColor, bgColor);
    _text = Text(_name, textColor, bgColor);
    _text.setPosition(_rect.getPosX() + _rect.getWidth() / 2 - _name.size() / 2, _rect.getPosY() + _rect.getHeight() / 2);
}

void arc::Button::setColorsSelect(int textColor, int bgColor)
{
    _rect.setColorsSelect(textColor, bgColor);
}

void arc::Button::setColorsTextSelect(int textColor, int bgColor)
{
    _text.setColorsTextSelect(textColor, bgColor);
}

void arc::Button::display()
{
    if (!_display)
        return;
    _rect.display();
    _text.display();
}

void arc::Button::toggleSelect()
{
    _select = !_select;
    _rect.setSelect(_select);
    _text.setSelect(_select);
}

void arc::Button::resetSelect()
{
    _select = false;
    _rect.setSelect(_select);
    _text.setSelect(_select);
}

bool arc::Button::isSelect() const
{
    return (_select);
}

void arc::Button::click()
{
    if (!_display)
        return;
    _event();
}

bool arc::Button::isMouseHover(size_t x, size_t y) const
{
    if (x > _rect.getPosX() && x < _rect.getPosX() + _rect.getWidth() && y > _rect.getPosY() && y < _rect.getPosY() + _rect.getHeight())
        return (true);
    return (false);
}

void arc::Button::setDisplay(bool display)
{
    _display = display;
}

void arc::Button::setEvent(const std::function<void()> &event)
{
    _event = event;
}