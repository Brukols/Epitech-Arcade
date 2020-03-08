/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLGraphicalButtonsMenu
*/

#include "SFMLGraphical.hpp"

static arc::SFMLButton initButtonPlay(const std::function<void()> &event)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 500));
    arc::SFMLButton button(event, rect);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    return (button);
}

static arc::SFMLButton initButtonExit(const std::function<void()> &event)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 700));
    arc::SFMLButton button(event, rect);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    return (button);
}

void arc::SFMLGraphical::initButtonsMenu()
{
    // Variable static in order to not call every time -> optimisation
    static std::vector<std::pair<arc::SFMLButton (*)(const std::function<void()> &), const std::function<void()> &>> buttons = [this]() -> const std::vector<std::pair<arc::SFMLButton (*)(const std::function<void()> &), const std::function<void()> &>> {
        std::vector<std::pair<arc::SFMLButton (*)(const std::function<void()> &), const std::function<void()> &>> buttons;

        buttons.push_back(std::pair<arc::SFMLButton (*)(const std::function<void()> &), const std::function<void()> &>(initButtonPlay, _eventPlayButton));
        buttons.push_back(std::pair<arc::SFMLButton (*)(const std::function<void()> &), const std::function<void()> &>(initButtonExit, _eventPlayButton));
        return (buttons);
    }();


    std::for_each(buttons.begin(), buttons.end(), [this](const std::pair<arc::SFMLButton (*)(const std::function<void()> &), const std::function<void()>> &pair) {
        _buttons.push_back(pair.first(pair.second));
    });
}