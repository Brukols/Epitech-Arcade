/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLGraphicalButtonsMenu
*/

#include "SFMLGraphical.hpp"

static arc::SFMLButton initButtonPlay(std::function<void()> &event)
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

static arc::SFMLButton initButtonExit(std::function<void()> &event)
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
    static std::vector<std::pair<arc::SFMLButton (*)(std::function<void()> &), std::function<void()>>> buttons = [this]() -> std::vector<std::pair<arc::SFMLButton (*)(std::function<void()> &), std::function<void()>>> {
        std::vector<std::pair<arc::SFMLButton (*)(std::function<void()> &), std::function<void()>>> buttons;

        std::function<void()> tmp = [this]() {
            _actualEventType = arc::Event::Type::QUIT;
            _actualKeyPress = arc::Event::Key::ESCAPE;
        };
        buttons.push_back(std::pair<arc::SFMLButton (*)(std::function<void()> &), std::function<void()>>(initButtonPlay, _eventPlayButton));
        buttons.push_back(std::pair<arc::SFMLButton (*)(std::function<void()> &), std::function<void()>>(initButtonExit, tmp));
        return (buttons);
    }();


    std::for_each(buttons.begin(), buttons.end(), [this](std::pair<arc::SFMLButton (*)(std::function<void()> &), std::function<void()>> &pair) {
        _buttons.push_back(pair.first(pair.second));
    });
}