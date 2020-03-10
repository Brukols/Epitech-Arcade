/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ListGames
*/

#include "SceneMenu.hpp"

static arc::Button initButton(const std::function<void (const std::string &)> &fct, int y)
{
    sf::RectangleShape rect(sf::Vector2f(320, 70));

    rect.setFillColor(sf::Color(120, 20, 20, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(6);
    rect.setPosition(sf::Vector2f(1360, y));
    arc::Button button(std::function<void()>(), rect);
    button.setHoverColor(sf::Color(150, 50, 50, 255));
    button.setColorSelect(sf::Color(150, 50, 50, 255), sf::Color(20, 150, 20, 255), sf::Color(150, 50, 50, 255));
    (void)fct;
    return (button);
}

void arc::SceneMenu::initButtonsListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct)
{
    int y = 440;
    _buttonsListGames.clear();

    std::for_each(games.begin(), games.end(), [this, &y, fct](const std::string &name) {
        (void)name;
        _buttonsListGames.push_back(initButton(fct, y));
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
    text.setPosition(sf::Vector2f(1480, y));
    return (arc::Text(font, text));
}

void arc::SceneMenu::initTextsListGames(const std::vector<std::string> &games)
{
    int y = 450;
    _textsListGames.clear();

    std::for_each(games.begin(), games.end(), [this, &y](const std::string &name) {
        _textsListGames.push_back(initText(name, _font, y));
        y += 150;
    });
}