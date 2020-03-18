/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ErrorMessage
*/

#include "sfml/ErrorMessage.hpp"

arc::ErrorMessage::ErrorMessage(const std::string &message, const std::function<void()> &event, const sf::Font &font) : _event(event)
{
    // Init button ok
    sf::RectangleShape rect(sf::Vector2f(220, 80));
    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 700));
    arc::Button button(event, rect, "Ok", font);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    _button.push_back(button);

    // Init text error message
    sf::Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Red);
    text.setPosition(sf::Vector2f(1920 / 2 - text.getLocalBounds().width / 2, 400));
    _text.push_back(arc::Text(font, text));

    // Init background
    sf::RectangleShape rect2(sf::Vector2f(1920, 1080));
    rect2.setFillColor(sf::Color(0, 0, 0, 210));
    rect2.setPosition(sf::Vector2f(0, 0));
    _rect = rect2;
}

arc::ErrorMessage::~ErrorMessage()
{
}

void arc::ErrorMessage::display(sf::RenderWindow &window)
{
    window.draw(_rect);

    _button[0].displayButton(window);
    _text[0].display(window);
}

bool arc::ErrorMessage::isHoverButton(const sf::Vector2i &pos) const
{
    return (_button[0].isMouseHover(pos));
}

void arc::ErrorMessage::clickButton()
{
    _event();
}