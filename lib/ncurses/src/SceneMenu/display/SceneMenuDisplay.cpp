/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenuDisplay
*/

#include "ncurses/SceneMenu.hpp"

void arc::SceneMenu::display()
{
    if (_sceneScores.isActivate()) {
        _sceneScores.display();
        return;
    }
    std::for_each(_rects.begin(), _rects.end(), [this](Rectangle &rect) {
        rect.display();
    });

    std::for_each(_texts.begin(), _texts.end(), [this](Text &text) {
        text.display();
    });

    std::for_each(_buttons.begin(), _buttons.end(), [this](std::pair<Button, void (SceneMenu::*)()> &button) {
        button.first.display();
    });

    std::for_each(_inputs.begin(), _inputs.end(), [this](Input &input) {
        input.display();
    });

    std::for_each(_lists.begin(), _lists.end(), [](List &list) {
        list.display();
    });

    std::for_each(_howToPlay.begin(), _howToPlay.end(), [](Text &text) {
        text.display();
    });
}