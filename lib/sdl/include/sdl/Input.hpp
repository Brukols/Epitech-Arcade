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
#include <memory>
#include "Utils.hpp"
#include <ctime>

namespace arc
{
    class Input {
        public:
            Input();
            ~Input();

            void setPosition(int x, int y);
            void setSize(int w, int h);
            void setColor(const SDL_Color &color);
            void setColorSelect(const SDL_Color &color);
            bool isSelect() const;
            void setSelect(bool select);
            void setColorOutline(const SDL_Color &color);

            void setText(const std::string &text);
            const std::string &getText() const;

            void display(SDL_Renderer *window);

            void event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event);

        private:
            void moveCursorToLeft();
            void moveCursorToRight();
            void resetClock();
            void deleteCharacter();
            void addCharacter(const char *c);
            void deleteCharacterForSuppr();

        private:
            std::unique_ptr<Text> _text;
            std::unique_ptr<Rectangle> _rect;
            std::unique_ptr<Text> _textHover;
            std::unique_ptr<Rectangle> _cursor;
            SDL_Color _colorRect;
            SDL_Color _colorRectSelect;
            SDL_Color _colorOutlineRect = {255, 255, 255, 255};

            std::clock_t _clock;
            bool _cursorDisplay = true;
            bool _editing = false;

            int _cursorPosition = 0;

            bool _select = false;

            bool _delete = false;
            bool _add = false;
    };
} // namespace arc

#endif /* !INPUT_HPP_ */
