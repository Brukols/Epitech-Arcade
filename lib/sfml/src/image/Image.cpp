/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Image
*/

#include "sfml/Image.hpp"

arc::Image::Image(const std::string &path) : _path(path)
{
    _texture = std::shared_ptr<sf::Texture>(new sf::Texture());
    if (!_texture.get()->loadFromFile(path))
        return;
    _sprite.setTexture(*_texture.get(), true);
}

arc::Image::~Image()
{
}

void arc::Image::setPosition(const sf::Vector2f &pos)
{
    _sprite.setPosition(pos);
}

void arc::Image::display(sf::RenderWindow &window)
{
    window.draw(_sprite);
}