/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ListGames
*/

#include "SceneMenu.hpp"

static arc::Button initButton(const std::string &name, const std::function<void (const std::string &)> &fct, int y, sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(320, 70));

    rect.setFillColor(sf::Color(120, 20, 20, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(6);
    rect.setPosition(sf::Vector2f(1360, y));
    arc::Button button(std::function<void()>(), rect, name, font);
    button.setHoverColor(sf::Color(150, 50, 50, 255));
    button.setColorSelect(sf::Color(150, 50, 50, 255), sf::Color(20, 150, 20, 255), sf::Color(150, 50, 50, 255));
    (void)fct;
    button.setActivate(false);
    return (button);
}

void arc::SceneMenu::initButtonsListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct)
{
    int y = 440;
    _buttonsListGames.clear();

    std::for_each(games.begin(), games.end(), [this, &y, fct](const std::string &name) {
        (void)name;
        _buttonsListGames.push_back(initButton(name, fct, y, _font));
        y += 150;
    });
}