/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScores
*/

#include "sfml/ListScores.hpp"

arc::ListScores::ListScores(const sf::Font &font, const std::vector<std::pair<std::string, std::string>> &scores, const std::string &username) : _font(font), _username(username)
{
    initTextsUsernames(scores);
    initTextsScores(scores);
}

arc::ListScores::~ListScores()
{
}
