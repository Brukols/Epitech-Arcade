/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameInitTexts
*/

#include "sfml/SceneGame.hpp"

static arc::Text initTitle(const sf::Font &font, const std::string &name)
{
    sf::Text text;

    text.setFont(font);
    text.setString(name);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(1600, 100));
    arc::Text _text(font, text);
    _text.setDisplay(true);
    return (_text);
}

static arc::Text initTextTitleStats(const sf::Font &font)
{
    sf::Text text;

    text.setFont(font);
    text.setString("Stats");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(1600, 250));
    arc::Text _text(font, text);
    _text.setDisplay(true);
    return (_text);
}

static arc::Text initTextTitleHowToPlay(const sf::Font &font)
{
    sf::Text text;

    text.setFont(font);
    text.setString("How to play");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(1600, 450));
    arc::Text _text(font, text);
    _text.setDisplay(true);
    return (_text);
}

void arc::SceneGame::initTexts()
{
    _texts.clear();
    _texts.push_back(initTitle(_font, _title));
    _texts.push_back(initTextTitleStats(_font));
    _texts.push_back(initTextTitleHowToPlay(_font));
}