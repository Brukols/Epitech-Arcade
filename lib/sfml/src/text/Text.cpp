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