/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** InitImages
*/

#include "sfml/SceneMenu.hpp"

arc::Image initBackground()
{
    arc::Image image("assets/sfml/textures/menu_background.jpg");

    image.setPosition(sf::Vector2f(0, 0));
    return (image);
}

void arc::SceneMenu::initImages()
{
    _images.clear();
    try {
        _images.push_back(initBackground());
    } catch(const std::exception& e) {
        _errorMessages.push_back(ErrorMessage(e.what(), [this](){
            _errorMessages.erase(_errorMessages.begin());
        }, _font));
    }
}