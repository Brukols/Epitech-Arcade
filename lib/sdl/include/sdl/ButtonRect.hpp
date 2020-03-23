/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Button
*/

#ifndef BUTTONRECT_HPP_
#define BUTTONRECT_HPP_

#include "IButton.hpp"
#include <string>
#include <SDL2/SDL_ttf.h>
#include "Text.hpp"
#include "Rectangle.hpp"

namespace arc
{
    class ButtonRect : public IButton {
        public:
            ButtonRect();
            ~ButtonRect();

            void setRect(const Rectangle &rect);
            void setText(const Text &text);
            void setPosition(size_t x, size_t y) override;
            bool isMouseHover(int x, int y) const override;
            void display(SDL_Renderer *window) override;
            void setColorHover(const SDL_Color &color);

        private:

        private:
            Rectangle _rect;
            Text _text;
            SDL_Color _color;
            SDL_Color _colorHover;
    };
} // namespace arc

#endif /* !BUTTONRECT_HPP_ */
