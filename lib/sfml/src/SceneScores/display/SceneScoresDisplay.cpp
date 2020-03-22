/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneScoresDisplay
*/

#include "sfml/SceneScores.hpp"

void arc::SceneScores::display(sf::RenderWindow &window)
{
    std::for_each(_rects.begin(), _rects.end(), [&window](sf::RectangleShape &rect) {
        window.draw(rect);
    });

    _listScores.display(window);

    std::for_each(_images.begin(), _images.end(), [&window](std::pair<Image, void (SceneScores::*)()> &pair) {
        pair.first.display(window);
    });
}