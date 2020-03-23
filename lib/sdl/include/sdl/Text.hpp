/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "defines.hpp"

namespace arc
{
    class Text {
        public:
            Text();
            ~Text();

            void setPosition(size_t x, size_t y);
            void setColor(const SDL_Color &color);
            void setFont(const std::string &path, int size);
            void display(SDL_Renderer *window);

        private:
            SDL_Surface *_surface = nullptr;
            SDL_Texture *_texture = nullptr;
            std::string _text = "coucou";
            TTF_Font *_font = nullptr;
            SDL_Color _color;

            size_t _x;
            size_t _y;
    };
} // namespace arc

#endif /* !TEXT_HPP_ */
