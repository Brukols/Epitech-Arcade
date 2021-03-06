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

            const SDL_Color &getColor() const;

            void display(SDL_Renderer *window);

            const SDL_Rect &getRect() const;
            void setOutline(bool outline);

            bool isMouseHover(int x, int y) const;

            int getHeight() const;
            int getWidth() const;

            void setColorOutline(const SDL_Color &color);

            int getPosX() const;
            int getPosY() const;

        private:
            SDL_Rect _rect;
            SDL_Color _color;
            bool _outline = false;
            SDL_Color _outlineColor = {255, 255, 255, 255};
    };
} // namespace arc

#endif /* !RECTANGLE_HPP_ */
