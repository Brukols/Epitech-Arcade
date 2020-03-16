/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** Utility
*/

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "sfml/Graphical.hpp"

namespace arc
{
    class Utility {
        public:

            static arc::Event::Key getKey(sf::Event event);
    };
}

#endif /* !UTILITY_HPP */
