/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include <SDL2/SDL.h>

namespace arc
{
    class Rectangle {
        public:
            Rectangle();
            ~Rectangle();

            void setPosition(size_t x, size_t y);
            void setSize(size_t w, size_t h);
            void setColor(const SDL_Color &color);

            void display(SDL_Renderer *window);

        private:
            SDL_Rect _rect;
            SDL_Color _color;
    };
} // namespace arc

#endif /* !RECTANGLE_HPP_ */
