/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** InitRects
*/

#include "sfml/SceneMenu.hpp"

sf::RectangleShape initBackgroundGetInput()
{
    sf::RectangleShape rect(sf::Vector2f(1920, 1080));

    rect.setFillColor(sf::Color(0, 0, 0, 210));
    rect.setPosition(sf::Vector2f(0, 0));
    return (rect);
}

void arc::SceneMenu::initRects()
{
    _rects.clear();
    _rects.push_back(initBackgroundGetInput());
}