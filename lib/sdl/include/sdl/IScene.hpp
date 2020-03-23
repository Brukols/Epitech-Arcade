/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include "Utils.hpp"
#include <SDL2/SDL.h>

namespace arc
{
    class IScene {
        public:
            virtual ~IScene() = default;

            virtual void init() = 0;
            virtual void display(SDL_Window *window) = 0;
            virtual void event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress) = 0;
    };
} // namespace arc

#endif /* !ISCENE_HPP_ */
