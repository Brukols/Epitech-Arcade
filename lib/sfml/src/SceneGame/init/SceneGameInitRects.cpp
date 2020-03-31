/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** rect
*/

#include "sfml/SceneGame.hpp"

sf::RectangleShape initMenuSideRect()
{
    sf::RectangleShape rect(sf::Vector2f(400, 1080));

    rect.setFillColor(sf::Color(40, 40, 40, 255));
    rect.setPosition(sf::Vector2f(1520, 0));
    return (rect);
}

sf::RectangleShape initMapGame()
{
    sf::RectangleShape rect(sf::Vector2f(1200, 900));

    rect.setFillColor(sf::Color(40, 40, 40, 255));
    rect.setPosition(sf::Vector2f(100, 100));
    return (rect);
}


void arc::SceneGame::initRects()
{
    _rects.clear();
    _rects.push_back(initMenuSideRect());
    _rects.push_back(initMapGame());
}