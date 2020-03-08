/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** text
*/

#include "SFMLGraphical.hpp"

void arc::SFMLGraphical::initText()
{
    std::vector<std::pair<Scene, void (arc::SFMLGraphical::*)()>> _inits;

    _inits.push_back(std::pair<Scene, void (arc::SFMLGraphical::*)()>(MAIN_MENU, &arc::SFMLGraphical::initTextMenu));

    _text.clear();

    std::for_each(_inits.begin(), _inits.end(), [this](const std::pair<Scene, void (arc::SFMLGraphical::*)()> &pair) {
        if (getScene() == pair.first)
            (this->*pair.second)();
    });
}