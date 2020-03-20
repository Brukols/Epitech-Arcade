/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScoresDisplay
*/

#include "sfml/ListScores.hpp"

void arc::ListScores::display(sf::RenderWindow &window)
{
    std::for_each(_textScores.begin(), _textScores.end(), [&window](std::pair<Text, Text> &text) {
        text.first.display(window);
        text.second.display(window);
    });
}