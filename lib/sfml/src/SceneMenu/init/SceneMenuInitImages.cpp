/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** InitImages
*/

#include "SceneMenu.hpp"

arc::Image initBackground()
{
    arc::Image image("resources/sprites/menu_background.jpg");

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
        _images.push_back(image());
    });
}