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
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(450 + 250 - text.getLocalBounds().width / 2, y + 10));
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color(100, 100, 100, 255));
    arc::Text _text(font, text);
    _text.setDisplay(true);
    return (_text);
}

static arc::Text initScoreText(int y, const sf::Font &font, const std::string &score)
{
    sf::Text text;

    text.setFont(font);
    text.setString(score);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(950 + 250 - text.getLocalBounds().width / 2, y + 10));
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color(100, 100, 100, 255));
    arc::Text _text(font, text);
    _text.setDisplay(true);
    return (_text);
}

void arc::ListScores::initTextsScores()
{
    int y = 200;

    _textScores.clear();
    std::for_each(_scores.begin(), _scores.end(), [this, &y](const std::pair<std::string, std::string> &pair) {
        _textScores.push_back(std::make_pair(initUsernameText(y, _font, pair.first), initScoreText(y, _font, pair.second)));
        y += 50;
    });
}

static sf::RectangleShape initBackgroundRect()
{
    sf::RectangleShape rect(sf::Vector2f(1000, 600));

    rect.setFillColor(sf::Color(40, 40, 40, 255));
    rect.setPosition(sf::Vector2f(450, 100));
    rect.setOutlineThickness(4);
    rect.setOutlineColor(sf::Color::White);
    return (rect);
}

static sf::RectangleShape initLeftRect(int y)
{
    sf::RectangleShape rect(sf::Vector2f(500, 50));

    rect.setFillColor(sf::Color::Black);
    rect.setPosition(sf::Vector2f(450, y));
    rect.setOutlineThickness(0);
    rect.setOutlineColor(sf::Color::White);
    return (rect);
}

static sf::RectangleShape initRightRect(int y)
{
    sf::RectangleShape rect(sf::Vector2f(500, 50));

    rect.setFillColor(sf::Color::Black);
    rect.setPosition(sf::Vector2f(950, y));
    rect.setOutlineThickness(0);
    rect.setOutlineColor(sf::Color::White);
    return (rect);
}

void arc::ListScores::initRects()
{
    std::vector<sf::RectangleShape (*)()> rects;

    rects.push_back(initBackgroundRect);

    _rects.clear();
    std::for_each(rects.begin(), rects.end(), [this](sf::RectangleShape (*fct)()) {
        _rects.push_back(fct());
    });

    // Init all the rect
    for (size_t i = 0; i < 10; i++) {
        _rects.push_back(initLeftRect(50 * i + 200));
        _rects.push_back(initRightRect(50 * i + 200));
        if (i % 2) {
            _rects[_rects.size() - 2].setFillColor(sf::Color(55, 60, 110));
            _rects[_rects.size() - 1].setFillColor(sf::Color(55, 60, 110));
        } else {
            _rects[_rects.size() - 2].setFillColor(sf::Color(40, 45, 80));
            _rects[_rects.size() - 1].setFillColor(sf::Color(40, 45, 80));
        }
    }
}

static arc::Text initTitle(const sf::Font &font)
{
    sf::Text text;

    text.setFont(font);
    text.setString("Scores");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(850, 120));
    text.setOutlineThickness(1);
    text.setOutlineColor(sf::Color::White);
    arc::Text _text(font, text);
    _text.setDisplay(true);
    return (_text);
}

void arc::ListScores::initTexts()
{
    std::vector<arc::Text (*)(const sf::Font &)> text;

    text.clear();
    text.push_back(initTitle);

    _texts.clear();

    std::for_each(text.begin(), text.end(), [this](arc::Text (*fct)(const sf::Font &)) {
        _texts.push_back(fct(_font));
    });
}