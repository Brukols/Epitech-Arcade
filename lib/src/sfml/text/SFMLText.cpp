/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLtext
*/

#include "sfml/SFMLText.hpp"

arc::SFMLText::SFMLText(const sf::Font &font, const sf::Text &text) : _font(font), _text(text)
{

}

arc::SFMLText::~SFMLText()
{
    
}

void arc::SFMLText::display(sf::RenderWindow &window)
{
    window.draw(_text);
}