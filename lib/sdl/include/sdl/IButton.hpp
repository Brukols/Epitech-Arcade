/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IButton
*/

#ifndef IBUTTON_HPP_
#define IBUTTON_HPP_

#include <SDL2/SDL.h>

namespace arc
{
    class IButton {
        public:
            virtual ~IButton() = default;

            virtual void setPosition(size_t x, size_t y) = 0;
            virtual bool isMouseHover(int x, int y) const = 0;
            virtual void display(SDL_Renderer *window) = 0;
            virtual void setActivate(bool activate) = 0;
            virtual bool isActivate() const = 0;
    };
} // namespace arc

#endif /* !IBUTTON_HPP_ */
