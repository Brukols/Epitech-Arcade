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
    _clock = std::clock();
}

arc::Input::~Input()
{
}

void arc::Input::addLetter(const sf::Event &event)
{
    std::string text = _text.getString();
    std::string newText = "";
    int i = 0;

    if (event.text.unicode == '\b') {
        removeLetter();
        return;
    }
    if (!isprint(event.text.unicode))
        return;
    for (; text[i]; i++) {
        if (i == _position) {
            newText += event.text.unicode;
        }
        newText += text[i];
    }
    if (i == _position)
        newText += event.text.unicode;
    _text.setString(newText);
    _position++;
    if (_text.getLocalBounds().width + 30 > _rect.getLocalBounds().width) {
        removeLetter();
        return;
    }
    _cursor.setPosition(sf::Vector2f(_text.findCharacterPos(_position).x, 525));
}

void arc::Input::setFocus(bool focus)
{
    _focus = focus;
}

const std::string arc::Input::getInput()
{
    return (_text.getString());
}

void arc::Input::removeLetter()
{
    std::string text = _text.getString();
    std::string newText = "";

    if (_position == 0)
        return;
    _position--;
    for (int i = 0; text[i]; i++) {
        if (i == _position)
            continue;
        newText += text[i];
    }
    _text.setString(newText);
    _cursor.setPosition(sf::Vector2f(_text.findCharacterPos(_position).x, 525));
}

void arc::Input::display(sf::RenderWindow &window)
{
    if (!_display)
        return;
    window.draw(_rect);
    window.draw(_text);
    if (std::clock() - _clock > 80000) {
        _displayCursor = !_displayCursor;
        _clock = std::clock();
    }
    if (_displayCursor)
        window.draw(_cursor);
}

bool arc::Input::isFocus() const
{
    return (_focus);
}

void arc::Input::resetClock()
{
    _clock = std::clock();
    _displayCursor = true;
}

void arc::Input::deleteCharacterForSuppr()
{
    std::string text = _text.getString();
    std::string newText = "";

    for (int i = 0; text[i]; i++) {
        if (i == _position)
            continue;
        newText += text[i];
    }
    _text.setString(newText);
    _cursor.setPosition(sf::Vector2f(_text.findCharacterPos(_position).x, 525));
}

void arc::Input::event(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left) {
            resetClock();
            if (_position == 0)
                return;
            _position--;
            _cursor.setPosition(sf::Vector2f(_text.findCharacterPos(_position).x, 525));
        } else if (event.key.code == sf::Keyboard::Right) {
            resetClock();
            if (!(static_cast<size_t>(_position) < _text.getString().getSize()))
                return;
            _position++;
            _cursor.setPosition(sf::Vector2f(_text.findCharacterPos(_position).x, 525));
        } else if (event.key.code == sf::Keyboard::Delete) {
            deleteCharacterForSuppr();
            resetClock();
        }
    } else if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == 13) {
            setFocus(false);
            return;
        }
        addLetter(event);
        resetClock();
    }
}