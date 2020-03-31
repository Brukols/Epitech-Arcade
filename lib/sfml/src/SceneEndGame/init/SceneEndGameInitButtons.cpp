/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameInitButtons
*/

#include "sfml/SceneEndGame.hpp"

static arc::Button initButtonRestart(const sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 80));

    rect.setFillColor(sf::Color(89, 87, 117, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(1230, 800));
    arc::Button button(std::function<void()>(), rect, "Restart", font);
    button.setHoverColor(sf::Color(109, 107, 137, 255));
    return (button);
}

static arc::Button initButtonMenu(const sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 80));

    rect.setFillColor(sf::Color(89, 87, 117, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(450, 800));
    arc::Button button(std::function<void()>(), rect, "Menu", font);
    button.setHoverColor(sf::Color(109, 107, 137, 255));
    return (button);
}

void arc::SceneEndGame::initButtons()
{
    _buttons.clear();
    _buttons.push_back(std::pair<Button, void (SceneEndGame::*)()>(initButtonRestart(_font), &SceneEndGame::eventRestart));
    _buttons.push_back(std::pair<Button, void (SceneEndGame::*)()>(initButtonMenu(_font), &SceneEndGame::eventMenu));
}