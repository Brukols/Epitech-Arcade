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
    // CLEAR THE WINDOW
    if (!_window.isOpen())
        return;
    _window.clear();

    // DISPLAY THE SCENE
    _scenes[_actualScene].get()->display(_window);
    _window.display();
    _scenes[_actualScene].get()->event(_window, _actualEventType, _actualKeyPress);
    if (_exit == true) {
        _actualEventType = arc::Event::Type::QUIT;
    }
}