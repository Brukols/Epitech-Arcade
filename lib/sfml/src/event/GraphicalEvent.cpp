/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GraphicalEvent
*/

#include "Graphical.hpp"
#include "Utils.hpp"
#include <iostream>

// bool arc::Graphical::clickAButton(const sf::Vector2i &pos)
// {
//     bool click = false;

//     std::for_each(_buttons.begin(), _buttons.end(), [this, pos, &click](Button &button) {
//         if (click == true)
//             return;
//         if (button.isMouseHover(pos)) {
//             button.clickButton();
//             click = true;
//         }
//     });
//     return (click);
// }

arc::Event::Type arc::Graphical::getEventType()
{
    _scenes[_actualScene].get()->event(_window, _actualEventType, _actualKeyPress);
    return (_actualEventType);
}

arc::Event::Key arc::Graphical::getKeyPressed() const
{
    return (_actualKeyPress);
}