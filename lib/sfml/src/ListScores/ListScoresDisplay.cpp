/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScoresDisplay
*/

#include "sfml/ListScores.hpp"

void arc::ListScores::display(sf::RenderWindow &window)
{
    std::for_each(_rects.begin(), _rects.end(), [&window](sf::RectangleShape &rect) {
        window.draw(rect);
    });

    std::for_each(_texts.begin(), _texts.end(), [&window](Text &text) {
        text.display(window);
    });

    int i = 0;
    std::for_each(_textScores.begin(), _textScores.end(), [this, &window, &i](std::pair<Text, Text> &text) {
        if (i >= 10 + _begin)
            return;
        if (i >= _begin) {
            text.first.display(window);
            text.second.display(window);
        }
        i++;
    });
}