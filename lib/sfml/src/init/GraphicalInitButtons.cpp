/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GrahpicalInitButtons
*/

#include "Graphical.hpp"

void arc::Graphical::initButtons()
{
    static std::vector<std::pair<Scene, void (arc::Graphical::*)()>> _inits = [this]() -> std::vector<std::pair<Scene, void (arc::Graphical::*)()>> {
        std::vector<std::pair<Scene, void (arc::Graphical::*)()>> _inits;

        _inits.push_back(std::pair<Scene, void (arc::Graphical::*)()>(MAIN_MENU, &arc::Graphical::initButtonsMenu));
        return (_inits);
    }();

    _buttons.clear();

    std::for_each(_inits.begin(), _inits.end(), [this](const std::pair<Scene, void (arc::Graphical::*)()> &pair) {
        if (getScene() == pair.first)
            (this->*pair.second)();
    });
}
