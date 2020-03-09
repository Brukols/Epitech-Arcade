/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GraphicalDisplay
*/

#include "Graphical.hpp"
#include <vector>

void arc::Graphical::display()
{
    static std::vector<std::pair<arc::IGraphical::Scene, void (arc::Graphical::*)(void)>> displays = [this]() -> std::vector<std::pair<arc::IGraphical::Scene, void (arc::Graphical::*)(void)>> {
        std::vector<std::pair<arc::IGraphical::Scene, void (arc::Graphical::*)(void)>> displays;

        displays.push_back(std::pair(arc::IGraphical::Scene::MAIN_MENU, &arc::Graphical::displayMenu));
        return (displays);
    }();

    // CLEAR THE WINDOW
    if (!_window.isOpen())
        return;
    _window.clear();

    // DISPLAY THE SCENE
    std::for_each(displays.begin(), displays.end(), [this](std::pair<arc::IGraphical::Scene, void (arc::Graphical::*)(void)> display) {
        if (display.first == _actualScene)
            (this->*display.second)();
    });

    _window.display();
}