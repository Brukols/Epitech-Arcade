/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** text
*/

#include "SFMLGraphical.hpp"

void arc::SFMLGraphical::initText()
{
    static std::vector<std::pair<Scene, void (arc::SFMLGraphical::*)()>> _inits = [this]() -> std::vector<std::pair<Scene, void (arc::SFMLGraphical::*)()>> {
        std::vector<std::pair<Scene, void (arc::SFMLGraphical::*)()>> _inits;

        _inits.push_back(std::pair<Scene, void (arc::SFMLGraphical::*)()>(MAIN_MENU, &arc::SFMLGraphical::initTextMenu));
        return (_inits);
    }();

    _text.clear();

    std::for_each(_inits.begin(), _inits.end(), [this](const std::pair<Scene, void (arc::SFMLGraphical::*)()> &pair) {
        if (getScene() == pair.first)
            (this->*pair.second)();
    });
}