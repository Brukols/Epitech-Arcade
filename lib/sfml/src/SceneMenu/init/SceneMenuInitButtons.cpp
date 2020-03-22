/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Init button
*/

#include "sfml/SceneMenu.hpp"

static arc::Button initButtonPlay(std::function<void()> &event, sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 300));
    arc::Button button(event, rect, "Play", font);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    button.setActivate(false);
    return (button);
}

static arc::Button initButtonExit(std::function<void()> &event, sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 700));
    arc::Button button(event, rect, "Exit", font);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    button.setActivate(false);
    return (button);
}

static arc::Button initButtonEnterUsername(std::function<void()> event, sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 80));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 700));
    arc::Button button(event, rect, "Validate", font);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    return (button);
}

static arc::Button initButtonWatchScores(std::function<void()> &event, sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 500));
    arc::Button button(event, rect, "Watch scores", font);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    return (button);
}

void arc::SceneMenu::initButtons()
{
    std::vector<std::pair<arc::Button (*)(std::function<void()> &, sf::Font &), std::function<void()>>> buttons;

    buttons.push_back(std::pair<arc::Button (*)(std::function<void()> &, sf::Font &), std::function<void()>>(initButtonPlay, [this](){
        eventButtonPlay();
    }));
    buttons.push_back(std::pair<arc::Button (*)(std::function<void()> &, sf::Font &), std::function<void()>>(initButtonExit, _eventExit));
    buttons.push_back(std::pair<arc::Button (*)(std::function<void()> &, sf::Font &), std::function<void()>>(initButtonWatchScores, [this]() {
        eventWatchScores();
    }));

    _buttons.clear();

    std::for_each(buttons.begin(), buttons.end(), [this](std::pair<arc::Button (*)(std::function<void()> &, sf::Font &), std::function<void()>> &pair) {
        _buttons.push_back(pair.first(pair.second, _font));
    });

    _buttonEnterUsername.clear();
    _buttonEnterUsername.push_back(initButtonEnterUsername([this]() {
        eventValidateUsername();
    }, _font));
}