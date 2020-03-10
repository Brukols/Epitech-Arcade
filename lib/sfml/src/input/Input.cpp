/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Input
*/

#include "Input.hpp"

arc::Input::Input(const sf::RectangleShape &rect, const sf::Text &text) : _rect(rect), _text(text)
{
}

arc::Input::~Input()
{
}

void arc::Input::addLetter(const sf::Event &event)
{
    if (_str.getSize() > 15)
        return;
    removeLetter();
    _str += event.text.unicode;
    _str += '|';
    _text.setString(_str);
}

void arc::Input::setFocus(bool focus)
{
    _focus = focus;
    if (_focus)
        removeLetter();
    else {
        _str += '|';
        _text.setString(_str);
    }
}

void arc::Input::removeLetter()
{
    if (_str.getSize() == 0)
        return;
    _str.erase(_str.getSize() - 1, 1);
}

void arc::Input::display(sf::RenderWindow &window)
{
    if (!_display)
        return;
    window.draw(_rect);
    window.draw(_text);
}

bool arc::Input::isFocus() const
{
    return (_focus);
}