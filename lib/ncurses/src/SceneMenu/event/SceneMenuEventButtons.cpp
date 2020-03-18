/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuEventButtons
*/

#include "ncurses/SceneMenu.hpp"

void arc::SceneMenu::resetListGames()
{
    std::for_each(_buttonsListGames.begin(), _buttonsListGames.end(), [this](Button &button) {
        button.resetSelect();
    });
}

void arc::SceneMenu::resetListLibraries()
{
    std::for_each(_buttonsListLibraries.begin(), _buttonsListLibraries.end(), [this](Button &button) {
        button.resetSelect();
    });
}

void arc::SceneMenu::eventButtons(MEVENT event)
{
    std::for_each(_buttons.begin(), _buttons.end(), [this, &event](Button &button) {
        if (button.isMouseHover(event.x, event.y))
            button.click();
    });

    std::for_each(_buttonsListGames.begin(), _buttonsListGames.end(), [this, &event](Button &button) {
        if (button.isMouseHover(event.x, event.y)) {
            if (!button.isSelect()) {
                resetListGames();
                button.click();
            }
            button.toggleSelect();
        }
    });

    std::for_each(_buttonsListLibraries.begin(), _buttonsListLibraries.end(), [this, &event](Button &button) {
        if (button.isMouseHover(event.x, event.y)) {
            if (!button.isSelect()) {
                resetListGames();
                button.click();
            }
            button.toggleSelect();
        }
    });
}