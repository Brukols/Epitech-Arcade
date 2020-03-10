/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** display
*/

#include "SceneGame.hpp"

void arc::SceneGame::display(sf::RenderWindow &window)
{
    std::for_each(_rects.begin(), _rects.end(), [this, &window](sf::RectangleShape &rect) {
        window.draw(rect);
    });

    std::for_each(_buttons.begin(), _buttons.end(), [this, &window](Button &button) {
        button.displayButton(window);
    });
}