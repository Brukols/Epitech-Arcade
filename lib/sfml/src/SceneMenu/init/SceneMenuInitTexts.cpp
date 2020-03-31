/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** INitTexts
*/

#include "sfml/SceneMenu.hpp"

static arc::Text initTextArcade(const sf::Font &font)
{
    sf::Text text;

    text.setFont(font);
    text.setString("Arcade");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(1);
    text.setOutlineColor(sf::Color(200, 200, 200, 255));
    text.setPosition(sf::Vector2f(750, 100));
    return (arc::Text(font, text));
}

static arc::Text initTextEnterUsername(const sf::Font &font)
{
    sf::Text text;

    text.setFont(font);
    text.setString("Enter an username");
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(660, 350));
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Black);
    arc::Text _text(font, text);
    _text.setDisplay(true);
    return (_text);
}

void arc::SceneMenu::initTexts()
{
    _texts.push_back(initTextArcade(_font));

    _textUsername.push_back(initTextEnterUsername(_font));
}