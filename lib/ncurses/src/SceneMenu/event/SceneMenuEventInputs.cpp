/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuEventInputs
*/

#include "ncurses/SceneMenu.hpp"

void arc::SceneMenu::eventInputs(MEVENT event)
{
    std::for_each(_inputs.begin(), _inputs.end(), [this, &event](Input &input) {
        if (input.isMouseHover(event.x, event.y)) {
            input.setActivate(true);
            return;
        }
        if (input.isActivate()) {
            _username = input.getText();
        }
        input.setActivate(false);
    });
}