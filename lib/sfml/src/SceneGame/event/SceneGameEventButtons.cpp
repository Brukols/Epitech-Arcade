/*
** EPITECH PROJECT, 2020
** Arecade
** File description:
** EventButton
*/

#include "sfml/SceneGame.hpp"

void arc::SceneGame::eventButtons(sf::RenderWindow &window, sf::Event &event)
{
    if (event.type != sf::Event::MouseButtonReleased)
        return;
    std::for_each(_buttons.begin(), _buttons.end(), [this, &window](std::pair<std::unique_ptr<Button>, void (SceneGame::*)()> &button) {
        if (button.first->isMouseHover(sf::Mouse::getPosition(window)))
            (this->*button.second)();
    });
}