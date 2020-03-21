/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScores
*/

#include "ncurses/ListScores.hpp"

arc::ListScores::ListScores()
{
    _rects.clear();
    _texts.clear();
}

arc::ListScores::~ListScores()
{
}

void arc::ListScores::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _scores = scores;
}

void arc::ListScores::setUsername(const std::string &username)
{
    _username = username;
}

void arc::ListScores::display()
{
    std::for_each(_rects.begin(), _rects.end(), [](Rectangle &rect) {
        rect.display();
    });

    std::for_each(_buttons.begin(), _buttons.end(), [](Button &button) {
        button.display();
    });

    std::for_each(_texts.begin(), _texts.end(), [](Text &text) {
        text.display();
    });

    int i = 0;
    std::for_each(_textScores.begin(), _textScores.end(), [this, &i](std::pair<Button, Button> &button) {
        if (i >= 8 + _begin)
            return;
        if (i < _begin) {
            i++;
            return;
        }
        button.first.display();
        button.second.display();
        i++;
    });
}