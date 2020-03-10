/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Init button
*/

#include "SceneMenu.hpp"

static arc::Button initButtonPlay(std::function<void()> &event)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 500));
    arc::Button button(event, rect);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    button.setActivate(false);
    return (button);
}

static arc::Button initButtonExit(std::function<void()> &event)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 700));
    arc::Button button(event, rect);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    button.setActivate(false);
    return (button);
}

static arc::Button initButtonEnterUsername(std::function<void()> event)
{
    sf::RectangleShape rect(sf::Vector2f(220, 80));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 700));
    arc::Button button(event, rect);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    return (button);
}

void arc::SceneMenu::initButtons()
{
    std::vector<std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>> buttons;

    buttons.push_back(std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>(initButtonPlay, [this](){
        eventButtonPlay();
    }));
    buttons.push_back(std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>>(initButtonExit, _eventExit));

    _buttons.clear();

    std::for_each(buttons.begin(), buttons.end(), [this](std::pair<arc::Button (*)(std::function<void()> &), std::function<void()>> &pair) {
        _buttons.push_back(pair.first(pair.second));
    });

    _buttonEnterUsername.push_back(initButtonEnterUsername([this]() {
        eventValidateUsername();
    }));
}