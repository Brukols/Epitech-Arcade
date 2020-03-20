/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** InitImages
*/

#include "sfml/SceneMenu.hpp"

arc::Image initBackground()
{
    arc::Image image("resources/sfml/textures/menu_background.jpg");

    image.setPosition(sf::Vector2f(0, 0));
    return (image);
}

void arc::SceneMenu::initImages()
{
    static std::vector<arc::Image (*)()> images = [this]() -> std::vector<arc::Image (*)()> {
        std::vector<arc::Image (*)()> images;

        images.push_back(initBackground);
        return (images);
    }();

    _images.clear();

    std::for_each(images.begin(), images.end(), [this](arc::Image (*image)()) {
        try {
            _images.push_back(image());
        } catch(const std::exception& e) {
            _errorMessages.push_back(ErrorMessage(e.what(), [this](){
                _errorMessages.erase(_errorMessages.begin());
            }, _font));
        }
    });
}