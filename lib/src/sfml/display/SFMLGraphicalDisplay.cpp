/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLGraphicalDisplay
*/

#include "SFMLGraphical.hpp"
#include <vector>

void arc::SFMLGraphical::display()
{
    static std::vector<std::pair<arc::IGraphical::Scene, void (arc::SFMLGraphical::*)(void)>> displays = [this]() -> std::vector<std::pair<arc::IGraphical::Scene, void (arc::SFMLGraphical::*)(void)>> {
        std::vector<std::pair<arc::IGraphical::Scene, void (arc::SFMLGraphical::*)(void)>> displays;

        displays.push_back(std::pair(arc::IGraphical::Scene::MAIN_MENU, &arc::SFMLGraphical::displayMenu));
        return (displays);
    }();

    // CLEAR THE WINDOW
    if (!_window.isOpen())
        return;
    _window.clear();

    // DISPLAY THE SCENE
    std::for_each(displays.begin(), displays.end(), [this](std::pair<arc::IGraphical::Scene, void (arc::SFMLGraphical::*)(void)> display) {
        if (display.first == _actualScene)
            (this->*display.second)();
    });

    _window.display();
}