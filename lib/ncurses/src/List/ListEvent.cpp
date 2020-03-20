/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListEvent
*/

#include "ncurses/List.hpp"

void arc::List::functionKeyDown()
{
    if (_buttonsList.size() <= 6)
        return;
    if (static_cast<long unsigned int>(_begin + 1) == _buttonsList.size() - 6)
        return;
    _begin++;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this](Button &button) {
        button.setPosition(button.getPosX(), button.getPosY() - 3);
    });
}

void arc::List::functionKeyUp()
{
    if (_begin == 0)
        return;
    _begin--;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this](Button &button) {
        button.setPosition(button.getPosX(), button.getPosY() + 3);
    });
}

void arc::List::resetButtonsList()
{
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [](Button &button) {
        if (button.isSelect())
            button.toggleSelect();
    });
}

void arc::List::event(const MEVENT &event)
{
    int i = 0;
    std::for_each(_buttons.begin(), _buttons.end(), [this, &event, &i](Button &button) {
        if (button.isMouseHover(event.x, event.y)) {
            if (i == 0)
                functionKeyDown();
            else if (i == 1)
                functionKeyUp();
        }
        i++;
    });

    i = 0;
    int max = 5;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this, &i, &max, &event](Button &button) {
        if (i > max)
            return;
        if (i >= _begin) {
            if (button.isMouseHover(event.x, event.y)) {
                resetButtonsList();
                button.toggleSelect();
                if (button.isSelect()) {
                    button.click();
                }
            }
        } else
            max++;
        i++;
    });
}