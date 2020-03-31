/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameDisplay
*/

#include "ncurses/SceneEndGame.hpp"

void arc::SceneEndGame::display()
{
    std::for_each(_buttons.begin(), _buttons.end(), [](std::pair<Button, void (SceneEndGame::*)()> &button) {
        button.first.display();
    });

    _listScores.display();
}