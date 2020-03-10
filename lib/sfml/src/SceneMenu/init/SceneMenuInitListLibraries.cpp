/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ListLibraries
*/

#include "SceneMenu.hpp"

static arc::Button initButton(std::function<void (const std::string &)> fct, int y)
{
    sf::RectangleShape rect(sf::Vector2f(320, 70));

    rect.setFillColor(sf::Color(20, 20, 120, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(6);
    rect.setPosition(sf::Vector2f(150, y));
    arc::Button button(std::function<void()>(), rect);
    button.setHoverColor(sf::Color(50, 50, 150, 255));
    button.setColorSelect(sf::Color(50, 50, 150, 255), sf::Color(20, 150, 20, 255), sf::Color(50, 50, 150, 255));
    (void)fct;
    return (button);
}

void arc::SceneMenu::initButtonsListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct)
{
    int y = 440;
    _buttonsListLibraries.clear();

    std::for_each(libraries.begin(), libraries.end(), [this, &y, fct](const std::string &name) {
        (void)name;
        _buttonsListLibraries.push_back(initButton(fct, y));
        y += 150;
    });
}

static arc::Text initText(const std::string name, sf::Font &font, int y)
{
    sf::Text text;

    text.setFont(font);
    text.setString(name);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(270, y));
    return (arc::Text(font, text));
}

void arc::SceneMenu::initTextsListLibraries(const std::vector<std::string> &libraries)
{
    int y = 450;
    _textsListLibraries.clear();

    std::for_each(libraries.begin(), libraries.end(), [this, &y](const std::string &name) {
        _textsListLibraries.push_back(initText(name, _font, y));
        y += 150;
    });
}