/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** EventButtonPlay
*/

#include "sfml/SceneMenu.hpp"

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

void arc::SceneMenu::eventButtonPlay()
{
    if (!oneButtonIsSelect(_buttonsListGames)) {
        _texts[3].setText("Veuillez selectioner un jeu");
        _texts[3].setDisplay(true);
        return;
    }
    if (!oneButtonIsSelect(_buttonsListLibraries)) {
        _texts[3].setText("Veuillez selectioner une librairie");
        _texts[3].setDisplay(true);
        return;
    }
    _texts[3].setDisplay(false);
    _eventPlay();
}