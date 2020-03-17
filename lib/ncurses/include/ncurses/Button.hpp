/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Button
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <functional>
#include "Text.hpp"
#include <ncurses.h>
#include "Rectangle.hpp"

namespace arc
{
    class Button {
        public:
            Button(const std::string &name, const Rectangle &rect, const std::function<void()> &event);
            ~Button();

            void setColors(int textColor, int bgColor);
            void display();
            // void setHoverColors(int textColor, int bgColor);

            void toggleSelect();
            void resetSelect();
            bool isSelect() const;
            void click();
            bool isMouseHover(size_t x, size_t y) const;

            void setColorsSelect(int textColor, int bgColor);
            void setColorsTextSelect(int textColor, int bgColor);

        private:
            std::string _name;
            Rectangle _rect;
            std::function<void()> _event;

            Text _text = Text("", COLOR_WHITE, COLOR_BLACK);
            int _noPair;

            int _noPairSelect = -1;

            bool _select = false;
    };
} // namespace arc

#endif /* !BUTTON_HPP */
