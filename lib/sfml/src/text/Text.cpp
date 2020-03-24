/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** text
*/

#include "sfml/Text.hpp"

arc::Text::Text(const sf::Font &font, const sf::Text &text) : _font(font), _text(text)
{

}

arc::Text::~Text()
{

}

void arc::Text::display(sf::RenderWindow &window)
{
    if (_display)
        window.draw(_text);
}

void arc::Text::setText(const std::string &text)
{
    _text.setString(text);
}

void arc::Text::setDisplay(bool display)
{
    _display = display;
}

void arc::Text::setPosition(const sf::Vector2f &pos)
{
    _text.setPosition(pos);
}

const sf::Vector2f &arc::Text::getPosition() const
{
    return (_text.getPosition());
}

const sf::Text &arc::Text::getText() const
{
    return (_text);
}