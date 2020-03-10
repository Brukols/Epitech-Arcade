/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** InitRects
*/

#include "SceneMenu.hpp"

sf::RectangleShape initBackgroundGetInput()
{
    sf::RectangleShape rect(sf::Vector2f(1920, 1080));

    rect.setFillColor(sf::Color(0, 0, 0, 210));
    rect.setPosition(sf::Vector2f(0, 0));
    return (rect);
}

void arc::SceneMenu::initRects()
{
    std::vector<sf::RectangleShape (*)()> rects;

    rects.push_back(initBackgroundGetInput);

    _rects.clear();

    std::for_each(rects.begin(), rects.end(), [this](sf::RectangleShape (*fct)()) {
        _rects.push_back(fct());
    });
}