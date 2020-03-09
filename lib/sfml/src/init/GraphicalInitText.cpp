/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** text
*/

#include "Graphical.hpp"

void arc::Graphical::initText()
{
    static std::vector<std::pair<Scene, void (arc::Graphical::*)()>> _inits = [this]() -> std::vector<std::pair<Scene, void (arc::Graphical::*)()>> {
        std::vector<std::pair<Scene, void (arc::Graphical::*)()>> _inits;

        _inits.push_back(std::pair<Scene, void (arc::Graphical::*)()>(MAIN_MENU, &arc::Graphical::initTextMenu));
        return (_inits);
    }();

    _text.clear();

    std::for_each(_inits.begin(), _inits.end(), [this](const std::pair<Scene, void (arc::Graphical::*)()> &pair) {
        if (getScene() == pair.first)
            (this->*pair.second)();
    });
}