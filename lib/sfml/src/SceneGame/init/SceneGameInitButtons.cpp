/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ScenGameinitbuttons
*/

#include "sfml/SceneGame.hpp"

static arc::Button initButtonBackToMenu(const sf::Font &font, std::function<void()> &event)
{
    sf::RectangleShape rect(sf::Vector2f(250, 100));

    rect.setFillColor(sf::Color(82, 91, 86, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(1600, 900));
    arc::Button button(event, rect, "Back to menu", font);
    button.setHoverColor(sf::Color(72, 81, 76, 255));
    button.setActivate(true);
    return (button);
}

static arc::Button initButtonRestart(const sf::Font &font, std::function<void()> &event)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 500));
    arc::Button button(event, rect, "Restart", font);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    button.setActivate(false);
    button.setDisplay(false);
    return (button);
}

static arc::Button initButtonPause(const sf::Font &font, std::function<void()> &event)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(82, 91, 86, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(1500, 800));
    arc::Button button(event, rect, "Menu", font);
    button.setHoverColor(sf::Color(72, 81, 76, 255));
    button.setActivate(false);
    button.setDisplay(false);
    return (button);
}

void arc::SceneGame::initButtons()
{
    static std::vector<std::pair<arc::Button (*)(const sf::Font &font, std::function<void()> &event), std::function<void()>>> buttons = [this]() -> std::vector<std::pair<arc::Button (*)(const sf::Font &font, std::function<void()> &event), std::function<void()>>> {
        std::vector<std::pair<arc::Button (*)(const sf::Font &font, std::function<void()> &event), std::function<void()>>> buttons;

        buttons.push_back(std::pair<arc::Button (*)(const sf::Font &font, std::function<void()> &event), std::function<void()>>(initButtonBackToMenu, [this]() {
            _eventFunctionBackToMenu();
        }));
        buttons.push_back(std::pair<arc::Button (*)(const sf::Font &font, std::function<void()> &event), std::function<void()>>(initButtonPause, [this]() {

        }));
        buttons.push_back(std::pair<arc::Button (*)(const sf::Font &font, std::function<void()> &event), std::function<void()>>(initButtonRestart, [this]() {

        }));
        return (buttons);
    }();

    _buttons.clear();

    std::for_each(buttons.begin(), buttons.end(), [this](std::pair<arc::Button (*)(const sf::Font &font, std::function<void()> &event), std::function<void()>> &button) {
        _buttons.push_back(button.first(_font, button.second));
    });
}