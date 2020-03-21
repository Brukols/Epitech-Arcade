/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameDisplay
*/

#include "ncurses/SceneEndGame.hpp"

void arc::SceneEndGame::display()
{
    std::for_each(_buttons.begin(), _buttons.end(), [](Button &button) {
        button.display();
    });
}