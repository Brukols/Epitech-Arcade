/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** EventButtonPlay
*/

#include "sfml/SceneMenu.hpp"

void arc::SceneMenu::eventButtonPlay()
{
    bool good = false;
    std::for_each(_lists.begin(), _lists.end(), [this, &good](const List &list) {
        if (!list.hasASelectButton()) {
            _texts[1].setText("Please choose a game");
            _texts[1].setDisplay(true);
            good = false;
        } else {
            good = true;
        }
    });
    if (!good)
        return;
    _texts[1].setDisplay(false);
    _eventPlay();
}