/*
** EPITECH PROJECT, 2020
** Arvcade
** File description:
** eventValidateuseraneù
*/

#include "SceneMenu.hpp"

void arc::SceneMenu::eventValidateUsername()
{
    _textUsername.clear();
    _inputs.clear();
    _rects.clear();
    _buttonEnterUsername.clear();
    std::for_each(_buttons.begin(), _buttons.end(), [this](Button &button) {
        button.setActivate(true);
    });
    std::for_each(_buttonsListGames.begin(), _buttonsListGames.end(), [this](Button &button) {
        button.setActivate(true);
    });
    std::for_each(_buttonsListLibraries.begin(), _buttonsListLibraries.end(), [this](Button &button) {
        button.setActivate(true);
    });
}