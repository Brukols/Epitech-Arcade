/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLGraphicalDisplay
*/

#include "SFMLGraphical.hpp"
#include <vector>

void arc::SFMLGraphical::display()
{
    std::vector<std::pair<arc::IGraphical::Scene, void (arc::SFMLGraphical::*)(void)>> displays;

    // COMPLETE WHAT SCENE TO DISPLAY
    displays.push_back(std::pair(arc::IGraphical::Scene::MAIN_MENU, &arc::SFMLGraphical::displayMainMenu));

    // CLEAR THE WINDOW
    if (!_window.get()->isOpen())
        return;
    _window.get()->clear();

    // DISPLAY THE SCENE
    std::for_each(displays.begin(), displays.end(), [this](std::pair<arc::IGraphical::Scene, void (arc::SFMLGraphical::*)(void)> display) {
        if (display.first == _actualScene)
            (this->*display.second)();
    });

    _window.get()->display();
}

void arc::SFMLGraphical::displayMainMenu()
{
    float pos_x = 800;
    float pos_y = 300;

    std::for_each(_mainMenuOptions.begin(), _mainMenuOptions.end(), [this, &pos_y, &pos_x](const auto &pair) {
        drawButton(pair.first, sf::Vector2f(300, 150), sf::Vector2f(pos_x, pos_y), sf::Color(70, 70, 70, 255));
        pos_y += 250;
    });
}

void arc::SFMLGraphical::drawButton(const std::string &name, const sf::Vector2f &size, const sf::Vector2f &pos, const sf::Color &color)
{
    sf::RectangleShape rect(size);

    rect.setFillColor(color);
    rect.setOutlineThickness(1);
    rect.setOutlineColor(sf::Color(200, 200, 200, 255));
    rect.setPosition(pos);
    _window.get()->draw(rect);
    drawText(name, 40, sf::Vector2f(pos.x + 35, pos.y + 50), sf::Color::Black);
}

void arc::SFMLGraphical::drawText(const std::string &name, size_t size, const sf::Vector2f &pos, const sf::Color &color)
{
    sf::Text text;

    text.setFont(_font);
    text.setString(name);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setOutlineThickness(1);
    text.setOutlineColor(sf::Color(200, 200, 200, 255));
    text.setPosition(pos);
    _window.get()->draw(text);
}