/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLGrahpicalInitButtons
*/

#include "SFMLGraphical.hpp"

void arc::SFMLGraphical::initButtons()
{
    std::vector<std::pair<Scene, void (arc::SFMLGraphical::*)()>> _inits;

    _inits.push_back(std::pair<Scene, void (arc::SFMLGraphical::*)()>(MAIN_MENU, &arc::SFMLGraphical::initButtonsMenu));

    _buttons.clear();

    std::for_each(_inits.begin(), _inits.end(), [this](const std::pair<Scene, void (arc::SFMLGraphical::*)()> &pair) {
        if (getScene() == pair.first)
            (this->*pair.second)();
    });
}
