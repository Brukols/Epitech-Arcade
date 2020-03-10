/*
** EPITECH PROJECT, 2020
** Arecade
** File description:
** EventButton
*/

#include "SceneGame.hpp"

void arc::SceneGame::eventButtons(sf::RenderWindow &window, sf::Event &event)
{
    if (event.type != sf::Event::MouseButtonReleased)
        return;
    std::for_each(_buttons.begin(), _buttons.end(), [this](Button &button) {
        if (button.isMouseHover(sf::Mouse::getPosition()))
            button.clickButton();
    });
    (void)window;
}