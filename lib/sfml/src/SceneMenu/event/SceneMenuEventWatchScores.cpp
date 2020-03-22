/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuWatchScores
*/

#include "sfml/SceneMenu.hpp"

void arc::SceneMenu::eventWatchScores()
{
    _sceneScores.init();

    bool good = true;
    std::for_each(_lists.begin(), _lists.end(), [this, &good](const List &list) {
        if (good == false)
            return;
        if (!list.hasASelectButton()) {
            _texts[1].setText("Please choose a game");
            _texts[1].setDisplay(true);
            good = false;
        } else {
            good = true;
        }
    });
    if (good == true)
        _sceneScores.setActivate(true);
}