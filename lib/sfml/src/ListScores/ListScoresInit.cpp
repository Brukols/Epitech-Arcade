/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScoresInit
*/

#include "sfml/ListScores.hpp"

static arc::Text initUsernameText(int y, const sf::Font &font, const std::string &username)
{
    sf::Text text;

    text.setFont(font);
    text.setString(username);
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(600, y));
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Black);
    arc::Text _text(font, text);
    _text.setDisplay(true);
    return (_text);
}

static arc::Text initScoreText(int y, const sf::Font &font, const std::string &score)
{
    sf::Text text;

    text.setFont(font);
    text.setString(score);
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(1000, y));
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Black);
    arc::Text _text(font, text);
    _text.setDisplay(true);
    return (_text);
}

void arc::ListScores::initTextsScores()
{
    int y = 0;

    _textScores.clear();
    std::for_each(_scores.begin(), _scores.end(), [this, &y](const std::pair<std::string, std::string> &pair) {
        _textScores.push_back(std::make_pair(initUsernameText(y, _font, pair.first), initScoreText(y, _font, pair.second)));
        y += 50;
    });
}
