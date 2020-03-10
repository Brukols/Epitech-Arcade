/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** EventButtonPlay
*/

#include "SceneMenu.hpp"

static bool oneButtonIsSelect(std::vector<arc::Button> _games)
{
    bool select = false;

    // Change with other algorithm because when is found that lust to start
    std::for_each(_games.begin(), _games.end(), [&select](const arc::Button &button) {
        if (button.isSelect()) {
            select = true;
        }
    });
    return (select);
}
#include <iostream>
void arc::SceneMenu::eventButtonPlay()
{
    if (!oneButtonIsSelect(_buttonsListGames)) {
        _texts[5].setText("Veuillez selectioner un jeu");
        _texts[5].setDisplay(true);
        return;
    }
    if (!oneButtonIsSelect(_buttonsListLibraries)) {
        _texts[5].setText("Veuillez selectioner une librairie");
        _texts[5].setDisplay(true);
        return;
    }
    _texts[5].setDisplay(false);
    _eventPlay();
}