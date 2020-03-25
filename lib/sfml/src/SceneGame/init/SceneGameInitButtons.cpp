/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ScenGameinitbuttons
*/

#include "sfml/SceneGame.hpp"

static arc::Button *initButtonBackToMenu(const sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(250, 100));

    rect.setFillColor(sf::Color(82, 91, 86, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(1600, 900));
    arc::Button *button = new arc::Button(std::function<void()>(), rect, "Menu", font);
    button->setHoverColor(sf::Color(72, 81, 76, 255));
    button->setActivate(true);
    return (button);
}

void arc::SceneGame::initButtons()
{
    _buttons.clear();
    _buttons.push_back(std::pair<std::unique_ptr<Button>, void (SceneGame::*)()>(initButtonBackToMenu(_font), &SceneGame::eventFunctionBackToMenu));
}