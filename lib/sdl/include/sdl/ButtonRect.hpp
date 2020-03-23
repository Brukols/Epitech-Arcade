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

namespace arc
{
    class ButtonRect : public IButton {
        public:
            ButtonRect();
            ~ButtonRect();

            void setPosition(size_t x, size_t y) override;
            bool isMouseHover(size_t x, size_t y) const override;
            void display(SDL_Renderer *window) override;

        private:
            Text _text;
    };
} // namespace arc

#endif /* !BUTTONRECT_HPP_ */
