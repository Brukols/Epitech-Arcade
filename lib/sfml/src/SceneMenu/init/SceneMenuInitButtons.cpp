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

    rect.setFillColor(sf::Color(89, 87, 117, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 320));
    arc::Button button(event, rect, "Play", font);
    button.setHoverColor(sf::Color(109, 107, 137, 255));
    button.setActivate(false);
    return (button);
}

static arc::Button initButtonExit(std::function<void()> &event, sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(89, 87, 117, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 820));
    arc::Button button(event, rect, "Exit", font);
    button.setHoverColor(sf::Color(109, 107, 137, 255));
    button.setActivate(false);
    button.setColorUnable(sf::Color(150, 150, 150, 255));
    return (button);
}

static arc::Button initButtonEnterUsername(std::function<void()> event, sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 80));

    rect.setFillColor(sf::Color(89, 87, 117, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 700));
    arc::Button button(event, rect, "Validate", font);
    button.setHoverColor(sf::Color(109, 107, 137, 255));
    return (button);
}

static arc::Button initButtonWatchScores(std::function<void()> &event, sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(89, 87, 117, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 490));
    arc::Button button(event, rect, "Watch scores", font);
    button.setHoverColor(sf::Color(109, 107, 137, 255));
    return (button);
}

static arc::Button initButtonHowToPlay(std::function<void()> &event, sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(89, 87, 117, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 660));
    arc::Button button(event, rect, "How to play", font);
    button.setHoverColor(sf::Color(109, 107, 137, 255));
    button.setActivate(false);
    button.setColorUnable(sf::Color(150, 150, 150, 255));
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

    buttons.push_back(std::pair<arc::Button (*)(std::function<void()> &, sf::Font &), std::function<void()>>(initButtonHowToPlay, [this]() {
        eventHowToPlay();
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