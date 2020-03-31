/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameDisplay
*/

#include "sfml/SceneEndGame.hpp"

void arc::SceneEndGame::display(sf::RenderWindow &window)
{
    std::for_each(_buttons.begin(), _buttons.end(), [&window](std::pair<Button, void (SceneEndGame::*)()> &button) {
        button.first.displayButton(window);
    });

    _listScores.display(window);
}