/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameDisplay
*/

#include "ncurses/SceneGame.hpp"

void arc::SceneGame::display()
{
    std::for_each(_rects.begin(), _rects.end(), [this](Rectangle &rect) {
        rect.display();
    });

    std::for_each(_buttons.begin(), _buttons.end(), [this](Button &button) {
        button.display();
    });
}