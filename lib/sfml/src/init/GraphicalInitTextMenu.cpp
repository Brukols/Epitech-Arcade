/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Text
*/

#include "Graphical.hpp"

static arc::Text initTextArcade(const sf::Font &font)
{
    sf::Text text;

    text.setFont(font);
    text.setString("Arcade");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(1);
    text.setOutlineColor(sf::Color(200, 200, 200, 255));
    text.setPosition(sf::Vector2f(750, 100));
    return (arc::Text(font, text));
}

static arc::Text initTextButtonPlay(const sf::Font &font)
{
    sf::Text text;

    text.setFont(font);
    text.setString("Play");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(910, 530));
    return (arc::Text(font, text));
}

static arc::Text initTextButtonExit(const sf::Font &font)
{
    sf::Text text;

    text.setFont(font);
    text.setString("Exit");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(910, 730));
    return (arc::Text(font, text));
}

static arc::Text initTextChooseGame(const sf::Font &font)
{
    sf::Text text;

    text.setFont(font);
    text.setString("Choose a game");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Red);
    text.setPosition(sf::Vector2f(1410, 330));
    return (arc::Text(font, text));
}

static arc::Text initTextChooseLibrary(const sf::Font &font)
{
    sf::Text text;

    text.setFont(font);
    text.setString("Choose a library");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Blue);
    text.setPosition(sf::Vector2f(190, 330));
    return (arc::Text(font, text));
}

void arc::Graphical::initTextMenu()
{
    static std::vector<arc::Text (*)(const sf::Font &)> text = [this]() -> std::vector<arc::Text (*)(const sf::Font &)> {
        std::vector<arc::Text (*)(const sf::Font &)> text;

        text.push_back(initTextArcade);
        text.push_back(initTextButtonPlay);
        text.push_back(initTextButtonExit);
        text.push_back(initTextChooseGame);
        text.push_back(initTextChooseLibrary);
        return (text);
    }();


    std::for_each(text.begin(), text.end(), [this](arc::Text (*fct)(const sf::Font &)) {
        _text.push_back(fct(_font));
    });
}