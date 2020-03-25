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
#include <memory>

namespace arc
{
    class ButtonRect : public IButton {
        public:
            ButtonRect();
            ~ButtonRect();

            void setRect(const Rectangle &rect);
            void setText(Text *text);

            void setPosition(size_t x, size_t y) override;
            bool isMouseHover(int x, int y) const override;
            void setActivate(bool activate) override;
            bool isActivate() const override;
            void display(SDL_Renderer *window) override;
            
            void setColorDisable(const SDL_Color &color);
            void setColorHover(const SDL_Color &color);
            void setColor(const SDL_Color &color);
            void setColorSelect(const SDL_Color &color);
            void setSelect(bool select);
            bool isSelect() const;

            int getPosX() const;
            int getPosY() const;

            const std::string &getText() const;

        private:

        private:
            Rectangle _rect;
            std::shared_ptr<Text> _text;
            SDL_Color _color;
            SDL_Color _colorHover;
            SDL_Color _colorSelect;
            SDL_Color _colorDisable = {100, 100, 100, 255};

            bool _select = false;
            bool _activate = true;
    };
} // namespace arc

#endif /* !BUTTONRECT_HPP_ */
