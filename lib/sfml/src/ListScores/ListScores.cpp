/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScores
*/

#include "sfml/ListScores.hpp"

arc::ListScores::ListScores()
{
    _textScores.clear();
    initRects();
}

arc::ListScores::ListScores(const sf::Font &font, const std::vector<std::pair<std::string, std::string>> &scores, const std::string &username) : _font(font), _username(username), _scores(scores)
{
    initTextsScores();
    initRects();
    initTexts();
}

arc::ListScores::~ListScores()
{
}

void arc::ListScores::init()
{
    initTextsScores();
}

void arc::ListScores::setFont(const sf::Font &font)
{
    _font = font;
    initTexts();
}

void arc::ListScores::setUsername(const std::string &username)
{
    _username = username;
}

void arc::ListScores::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _scores = scores;
}

