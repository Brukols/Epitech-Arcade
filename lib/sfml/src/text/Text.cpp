/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** text
*/

#include "Text.hpp"

arc::Text::Text(const sf::Font &font, const sf::Text &text) : _font(font), _text(text)
{

}

arc::Text::~Text()
{
    
}

void arc::Text::display(sf::RenderWindow &window)
{
    window.draw(_text);
}