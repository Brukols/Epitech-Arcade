/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameInitButtons
*/

#include "sfml/SceneEndGame.hpp"

using Pair = std::pair<arc::Button (*)(const std::function<void()> &, const sf::Font &), std::function<void()>>;

static arc::Button initButtonRestart(const std::function<void()> &event, const sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 80));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(1230, 800));
    arc::Button button(event, rect, "Restart", font);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    return (button);
}

static arc::Button initButtonMenu(const std::function<void()> &event, const sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 80));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(430, 800));
    arc::Button button(event, rect, "Menu", font);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    return (button);
}

void arc::SceneEndGame::initButtons()
{
    std::vector<Pair> buttons;

    buttons.push_back(Pair(initButtonRestart, [this]() {
        _eventRestart();
    }));

    buttons.push_back(Pair(initButtonMenu, [this]() {
        _eventMenu();
    }));

    _buttons.clear();
    std::for_each(buttons.begin(), buttons.end(), [this](const Pair &pair) {
        _buttons.push_back(pair.first(pair.second, _font));
    });
}