/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameEventButtons
*/

#include "ncurses/SceneGame.hpp"

void arc::SceneGame::eventButtons(MEVENT event)
{
    std::for_each(_buttons.begin(), _buttons.end(), [this, &event](Button &button) {
        if (button.isMouseHover(event.x, event.y))
            button.click();
    });
}