/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Utility
*/

#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include "Utils.hpp"
#include <SDL2/SDL.h>

namespace arc
{
    class Utility {
        public:
            enum ColorType {
                BUTTON,
                BUTTON_HOVER,
                BACKGROUND_COLOR,
                BUTTON_LIST,
                BUTTON_LIST_2,
                BUTTON_LIST_HOVER,
                SIDE_RECTANGLE,
            };
            enum Theme {
                NONE,
                ORNAMENTAL,
                BLUE,
            };
        public:

            static arc::Event::Type getEventType(const SDL_Event &event);
            static arc::Event::Key getEventKey(const SDL_Event &event);
            static void changeCursor(SDL_SystemCursor cursor, bool display = false);
            static Theme getTheme(Theme theme = NONE);
            static SDL_Color getColor(ColorType type);

    };
} // namespace arc


#endif /* !UTILITY_HPP_ */
