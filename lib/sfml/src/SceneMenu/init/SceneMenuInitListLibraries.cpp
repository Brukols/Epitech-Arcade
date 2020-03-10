/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ListLibraries
*/

#include "SceneMenu.hpp"

static arc::Button initButton(const std::string &name, std::function<void (const std::string &)> fct, int y, sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(320, 70));

    rect.setFillColor(sf::Color(20, 20, 120, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(6);
    rect.setPosition(sf::Vector2f(150, y));
    arc::Button button(std::function<void()>(), rect, name, font);
    button.setHoverColor(sf::Color(50, 50, 150, 255));
    button.setColorSelect(sf::Color(50, 50, 150, 255), sf::Color(20, 150, 20, 255), sf::Color(50, 50, 150, 255));
    (void)fct;
    button.setActivate(false);
    return (button);
}

void arc::SceneMenu::initButtonsListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct)
{
    int y = 440;
    _buttonsListLibraries.clear();

    std::for_each(libraries.begin(), libraries.end(), [this, &y, fct](const std::string &name) {
        (void)name;
        _buttonsListLibraries.push_back(initButton(name, fct, y, _font));
        y += 150;
    });
}