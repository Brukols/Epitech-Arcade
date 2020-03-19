/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "Rectangle.hpp"
#include "Text.hpp"
#include <cctype>

namespace arc
{
    class Input {
        public:
            Input(const Rectangle &rect, const Text &text);
            ~Input();

            void display();
            bool isMouseHover(size_t x, size_t y) const;
            void setActivate(bool activate);
            bool isActivate() const;

            void setColorsSelect(int textColor, int bgColor);

            void addLetter(int c);
            void removeLetter();

            const std::string &getText() const;
            void setText(const std::string &text);

        private:
            Rectangle _rect;
            Text _textIndication;
            bool _activate = false;
            Text _text;
    };
} // namespace arc

#endif /* !INPUT_HPP_ */
