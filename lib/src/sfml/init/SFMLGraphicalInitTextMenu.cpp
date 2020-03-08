/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Text
*/

#include "SFMLGraphical.hpp"

static arc::SFMLText initTextArcade(const sf::Font &font)
{
    sf::Text text;

    text.setFont(font);
    text.setString("Arcade");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(1);
    text.setOutlineColor(sf::Color(200, 200, 200, 255));
    text.setPosition(sf::Vector2f(100, 100));
    return (arc::SFMLText(font, text));
}

void arc::SFMLGraphical::initTextMenu()
{
    std::vector<arc::SFMLText (*)(const sf::Font &)> text;

    text.push_back(initTextArcade);

    std::for_each(text.begin(), text.end(), [this](arc::SFMLText (*fct)(const sf::Font &)) {
        _text.push_back(fct(_font));
    });
}