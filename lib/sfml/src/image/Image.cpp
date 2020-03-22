/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Image
*/

#include "sfml/Image.hpp"
#include "sfml/SFMLErrors.hpp"

arc::Image::Image(const std::string &path) : _path(path)
{
    _texture = std::shared_ptr<sf::Texture>(new sf::Texture());
    if (!_texture.get()->loadFromFile(path))
        throw SpriteError("Cannot load this image : " + path, "Image");
    _sprite.setTexture(*_texture.get(), true);
}

arc::Image::~Image()
{
}

void arc::Image::setPosition(const sf::Vector2f &pos)
{
    _pos = pos;
    _sprite.setPosition(pos);
}

void arc::Image::display(sf::RenderWindow &window)
{
    window.draw(_sprite);
}

const sf::Vector2f &arc::Image::getPosition() const
{
    return (_pos);
}

bool arc::Image::isMouseHover(const sf::Vector2i &pos) const
{
    if (pos.x > _pos.x && pos.x < _pos.x + _sprite.getLocalBounds().width && pos.y > _pos.y && pos.y < _pos.y + _sprite.getLocalBounds().height)
        return (true);
    return (false);
}