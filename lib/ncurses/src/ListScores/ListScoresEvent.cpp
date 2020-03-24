/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScoresEvent
*/

#include "ncurses/ListScores.hpp"

void arc::ListScores::scrollDown()
{
    if (_textScores.size() <= 8)
        return;
    if (static_cast<long unsigned int>(_begin + 1) > _textScores.size() - 8)
        return;
    _begin++;
    std::for_each(_textScores.begin(), _textScores.end(), [this](std::pair<Button, Button> &button) {
        button.first.setPosition(button.first.getPosX(), button.first.getPosY() - 3);
        button.second.setPosition(button.second.getPosX(), button.second.getPosY() - 3);
    });
}

void arc::ListScores::scrollUp()
{
    if (_begin == 0)
        return;
    _begin--;
    std::for_each(_textScores.begin(), _textScores.end(), [this](std::pair<Button, Button> &button) {
        button.first.setPosition(button.first.getPosX(), button.first.getPosY() + 3);
        button.second.setPosition(button.second.getPosX(), button.second.getPosY() + 3);
    });
}

void arc::ListScores::event(const MEVENT &event)
{
    int i = 0;
    std::for_each(_buttons.begin(), _buttons.end(), [this, &event, &i](const Button &button) {
        if (button.isMouseHover(event.x, event.y)) {
            if (i == 0) {
                scrollUp();
            } else if (i == 1) {
                scrollDown();
            }
        }
        i++;
    });
}