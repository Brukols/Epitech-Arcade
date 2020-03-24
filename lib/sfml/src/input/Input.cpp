/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Input
*/

#include "sfml/Input.hpp"

arc::Input::Input(const sf::RectangleShape &rect, const sf::Text &text) : _rect(rect), _text(text)
{
    _cursor.setSize(sf::Vector2f(3, 40));
    _cursor.setFillColor(sf::Color::Black);
    _cursor.setPosition(sf::Vector2f(755, 525));
}

arc::Input::~Input()
{
}

void arc::Input::addLetter(const sf::Event &event)
{
    if (event.text.unicode == '\b') {
        removeLetter();
        _text.setString(_str);
        _cursor.setPosition(sf::Vector2f(755 + _text.getGlobalBounds().width, 525));
        return;
    }
    _str += event.text.unicode;
    _text.setString(_str);
    if (_text.getLocalBounds().width + 30 > _rect.getLocalBounds().width) {
        removeLetter();
        _text.setString(_str);
    }
    _cursor.setPosition(sf::Vector2f(755 + _text.getGlobalBounds().width, 525));
}

void arc::Input::setFocus(bool focus)
{
    _focus = focus;
    if (_focus)
        removeLetter();
    else {
        _text.setString(_str);
    }
}

const std::string arc::Input::getInput()
{
    return (_str.toAnsiString());
}

void arc::Input::removeLetter()
{
    if (_str.getSize() == 0)
        return;
    _str.erase(_str.getSize() - 1, 1);
    _cursor.setPosition(sf::Vector2f(755 + _text.getGlobalBounds().width, 525));
    _position--;
}

void arc::Input::display(sf::RenderWindow &window)
{
    if (!_display)
        return;
    window.draw(_rect);
    window.draw(_text);
    window.draw(_cursor);
}

bool arc::Input::isFocus() const
{
    return (_focus);
}