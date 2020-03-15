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

void arc::Button::display()
{
    _rect.display();
    _text.display();
}