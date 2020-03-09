/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMEnudisplay
*/

#include "SceneMenu.hpp"

void arc::SceneMenu::display(sf::RenderWindow &window)
{
    // Display buttons
    std::for_each(_buttons.begin(), _buttons.end(), [this, &window](arc::Button &button) {
        button.displayButton(window);
    });

    // Displays text
    std::for_each(_texts.begin(), _texts.end(), [this, &window](arc::Text &text) {
        text.display(window);
    });
}