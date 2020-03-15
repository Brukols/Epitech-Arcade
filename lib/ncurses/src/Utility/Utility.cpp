/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Utility
*/

#include "ncurses/Utility.hpp"
#include <streambuf>
#include <fstream>

void arc::Utility::display(const std::string &text, int x, int y, int noPair)
{
    attron(COLOR_PAIR(noPair));
    for (size_t i = 0; i < text.size(); y++, i++) {
        size_t tmp_x = x;
        for (; text[i] != '\n' && i < text.size(); i++, tmp_x++) {
            mvprintw(y, tmp_x, "%c", text[i]);
        }
    }
    attroff(COLOR_PAIR(noPair));
}

std::string arc::Utility::getText(const std::string &path)
{
    std::ifstream file(path);
    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return (str);
}

int arc::Utility::generatePairColor(int textColor, int bgColor)
{
    static int noPair = 0;

    noPair++;
    init_pair(noPair, textColor, bgColor);
    return (noPair);
}