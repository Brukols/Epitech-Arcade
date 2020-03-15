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
}