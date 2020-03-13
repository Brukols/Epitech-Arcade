/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <string>
#include <ncurses.h>
#include "Utils.hpp"
#include "Utility.hpp"

namespace arc
{
    class Rectangle {
        public:
            Rectangle(int height, int width);
            ~Rectangle();

            void setBackgroundColor(int r, int g, int b);
            void setOutlineColor(int r, int g, int b);
            void setPosition(size_t x, size_t y);

            void display();

        protected:
        private:
            size_t _height;
            size_t _width;

            size_t _x;
            size_t _y;

            Color _color;
            Color _outlineColor;
    };
};

#endif /* !RECTANGLE_HPP */
