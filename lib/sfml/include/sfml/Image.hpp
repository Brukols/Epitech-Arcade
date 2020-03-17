/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Image
*/

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

namespace arc
{
    class Image {
        public:
            Image(const std::string &path);
            ~Image();

            void setPosition(const sf::Vector2f &pos);
            void display(sf::RenderWindow &window);

        private:
            std::string _path;
            std::shared_ptr<sf::Texture> _texture;
            sf::Sprite _sprite;
    };
}

#endif /* !IMAGE_HPP */
