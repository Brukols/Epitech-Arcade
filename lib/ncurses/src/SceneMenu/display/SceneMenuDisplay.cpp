/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenuDisplay
*/

#include "ncurses/SceneMenu.hpp"

void arc::SceneMenu::display(WINDOW *win)
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
}