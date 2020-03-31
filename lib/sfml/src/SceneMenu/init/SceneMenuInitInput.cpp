/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** InitInput
*/

#include "sfml/SceneMenu.hpp"

arc::Input initInputUsername(const sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(400, 100));

    rect.setFillColor(sf::Color(200, 200, 200, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(740, 500));

    sf::Text _text;
    _text.setFont(font);
    _text.setString("");
    _text.setCharacterSize(30);
    _text.setOutlineThickness(4);
    _text.setOutlineColor(sf::Color::Black);
    _text.setPosition(sf::Vector2f(rect.getPosition().x + 20, rect.getPosition().y + 25));
    _text.setFillColor(sf::Color::White);
    return (arc::Input(rect, _text));
}

void arc::SceneMenu::initInput()
{
    _inputs.clear();
    _inputs.push_back(initInputUsername(_font));
    _inputs[0].setFocus(true);
}