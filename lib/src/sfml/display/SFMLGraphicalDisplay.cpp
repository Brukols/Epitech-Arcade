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
    displays.push_back(std::pair(arc::IGraphical::Scene::MAIN_MENU, &arc::SFMLGraphical::displayMenu));

    // CLEAR THE WINDOW
    if (!_window.isOpen())
        return;
    _window.clear();

    // DISPLAY THE SCENE
    std::for_each(displays.begin(), displays.end(), [this](std::pair<arc::IGraphical::Scene, void (arc::SFMLGraphical::*)(void)> display) {
        if (display.first == _actualScene)
            (this->*display.second)();
    });

    _window.display();
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
    _window.draw(text);
}