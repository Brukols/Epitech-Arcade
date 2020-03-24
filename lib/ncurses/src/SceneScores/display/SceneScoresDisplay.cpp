/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneScoresDisplay
*/

#include "ncurses/SceneScores.hpp"

void arc::SceneScores::display()
{
    std::for_each(_buttons.begin(), _buttons.end(), [this](std::pair<Button, void (SceneScores::*)()> &button) {
        button.first.display();
    });

    _listScores.display();
}