/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** IScene
*/

#ifndef ISCENE_HPP
#define ISCENE_HPP

#include <SFML/Graphics.hpp>
#include "Utils.hpp"

namespace arc
{
    class IScene {
        public:

            virtual void init() = 0;

            virtual void display(sf::RenderWindow &window) = 0;

            virtual void event(sf::RenderWindow &window, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress) = 0;
    };
}

#endif /* !ISCENE_HPP */
