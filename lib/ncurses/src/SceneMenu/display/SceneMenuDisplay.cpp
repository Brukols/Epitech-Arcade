/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenuDisplay
*/

#include "ncurses/SceneMenu.hpp"

void arc::SceneMenu::display()
{
    std::for_each(_rects.begin(), _rects.end(), [this](Rectangle &rect) {
        rect.display();
    });

    std::for_each(_texts.begin(), _texts.end(), [this](Text &text) {
        text.display();
    });

    std::for_each(_buttons.begin(), _buttons.end(), [this](Button &button) {
        button.display();
    });

    std::for_each(_inputs.begin(), _inputs.end(), [this](Input &input) {
        input.display();
    });

    std::for_each(_lists.begin(), _lists.end(), [](List &list) {
        list.display();
    });
}