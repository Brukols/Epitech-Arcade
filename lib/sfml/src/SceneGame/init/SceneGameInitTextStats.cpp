/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameInitTextStats
*/

#include "sfml/SceneGame.hpp"

static arc::Text initText(const sf::Font &font, const std::string &index, const std::string &value, int y)
{
    sf::Text text;

    text.setFont(font);
    text.setString(index + " : " + value);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(1600, y));
    arc::Text _text(font, text);
    _text.setDisplay(true);
    return (_text);
}

void arc::SceneGame::initTextStats(const std::vector<std::pair<std::string, std::string>> &info)
{
    std::vector<arc::Text (*)(const sf::Font &)> text;

    text.clear();

    _stats.clear();

    int y = 300;
    std::for_each(info.begin(), info.end(), [this, &y](const std::pair<std::string, std::string> &pair) {
        _stats.push_back(initText(_font, pair.first, pair.second, y));
        y += 30;
    });
}