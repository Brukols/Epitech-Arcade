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
            Rectangle(int height, int width, int textColor, int bgColor);
            ~Rectangle();

            void setPosition(size_t x, size_t y);
            void setOutlineColors(int textColor, int bgColor);
            void setColorsSelect(int textColor, int bgColor);
            void setSelect(bool select);
            void setColors(int textColor, int bgColor);

            void display();

            const size_t &getHeight() const;
            const size_t &getWidth() const;
            const size_t &getPosX() const;
            const size_t &getPosY() const;

        private:
            size_t _height;
            size_t _width;

            size_t _x;
            size_t _y;

            int _noPair;
            int _noPairOutline = -1;
            int _noPairSelect = -1;

            bool _select = false;
    };
};

#endif /* !RECTANGLE_HPP */
