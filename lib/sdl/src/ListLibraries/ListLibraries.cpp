/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListLibraries
*/

#include "sdl/ListLibraries.hpp"

arc::ListLibraries::ListLibraries()
{
}

arc::ListLibraries::~ListLibraries()
{
}

void arc::ListLibraries::setFont(const std::string &path)
{
    _font = path;
}

void arc::ListLibraries::setEventList(const std::function<void (const std::string &)> &fct)
{
    _eventList = fct;
}

void arc::ListLibraries::setNameList(const std::string &nameList)
{
    arc::Text text;

    text.setFont(_font, 20);
    text.setText(nameList);
    text.setPosition(200 - text.getWidth() / 2, 10);
    text.setColor({255, 255, 255, 255});
    _texts.push_back(text);
}

void arc::ListLibraries::setNameLibraries(const std::vector<std::string> &list, int chosen)
{

}

void arc::ListLibraries::display(SDL_Renderer *window)
{
    std::for_each(_texts.begin(), _texts.end(), [&window](Text &text) {
        text.display(window);
    });
}