/*
** EPITECH PROJECT, 2020
** ListLibrary
** File description:
** arcade
*/

#include "ListLibrary.hpp"

arc::ListLibrary::ListLibrary()
{
}

arc::ListLibrary::~ListLibrary()
{
}

void arc::ListLibrary::setListGames(const std::vector<std::string> &name, const std::function<void(const std::string &)> &event,
    const sf::Font &font)
{
    _eventChooseGame = event;
    _font = font;
    initButtonsGames(name);
    initTextsGames(name);
}

void arc::ListLibrary::setListLibraries(const std::vector<std::string> &name, const std::function<void(const std::string &)> &event,
    const sf::Font &font)
{
    _eventChooseLibrary = event;
    _font = font;
    initButtonsLibraries(name);
    initTextsLibraries(name);
}

void arc::ListLibrary::initButtonsGames(const std::vector<std::string> &name)
{
    int y = 440;

    std::for_each(name.begin(), name.end(), [this, &y](const std::string &name) {
        sf::RectangleShape rect(sf::Vector2f(320, 70));

        rect.setFillColor(sf::Color(120, 20, 20, 255));
        rect.setOutlineColor(sf::Color::White);
        rect.setOutlineThickness(6);
        rect.setPosition(sf::Vector2f(1360, y));
        arc::Button button(std::function<void()>(), rect);
        button.setHoverColor(sf::Color(150, 50, 50, 255));
        _buttonGames.push_back(button);
        y += 150;
        (void)name;
    });
}

void arc::ListLibrary::initButtonsLibraries(const std::vector<std::string> &name)
{
    int y = 440;

    std::for_each(name.begin(), name.end(), [this, &y](const std::string &name) {
        sf::RectangleShape rect(sf::Vector2f(320, 70));

        rect.setFillColor(sf::Color(20, 20, 120, 255));
        rect.setOutlineColor(sf::Color::White);
        rect.setOutlineThickness(6);
        rect.setPosition(sf::Vector2f(150, y));
        arc::Button button(std::function<void()>(), rect);
        button.setHoverColor(sf::Color(50, 50, 150, 255));
        _buttonLibs.push_back(button);
        y += 150;
        (void)name;
    });
}

void arc::ListLibrary::initTextsGames(const std::vector<std::string> &name)
{
    int y = 440;

    std::for_each(name.begin(), name.end(), [this, &y](const std::string &name) {
        sf::Text text;

        text.setFont(_font);
        text.setString(name);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::White);
        text.setOutlineThickness(1);
        text.setOutlineColor(sf::Color(200, 200, 200, 255));
        text.setPosition(sf::Vector2f(120, y));
        y += 150;
        _textGames.push_back(arc::Text(_font, text));
    });
}

void arc::ListLibrary::initTextsLibraries(const std::vector<std::string> &name)
{
    int y = 440;

    std::for_each(name.begin(), name.end(), [this, &y](const std::string &name) {
        sf::Text text;

        text.setFont(_font);
        text.setString(name);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::White);
        text.setOutlineThickness(1);
        text.setOutlineColor(sf::Color(200, 200, 200, 255));
        text.setPosition(sf::Vector2f(1360, y));
        y += 150;
        _textLibs.push_back(arc::Text(_font, text));
    });
}

void arc::ListLibrary::display(sf::RenderWindow &window)
{
    // Displays list games
    std::for_each(_buttonGames.begin(), _buttonGames.end(), [this, &window](arc::Button &button) {
        button.displayButton(window);
    });
    std::for_each(_buttonLibs.begin(), _buttonLibs.end(), [this, &window](arc::Button &button) {
        button.displayButton(window);
    });

    std::for_each(_textGames.begin(), _textGames.end(), [this, &window](arc::Text &text) {
        text.display(window);
    });
    std::for_each(_textLibs.begin(), _textLibs.end(), [this, &window](arc::Text &text) {
        text.display(window);
    });
}