/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

namespace arc
{
    class Sprite {
        public:
            Sprite(const std::string &path);
            ~Sprite();

            void display(SDL_Renderer *window);
            void setScale(int width, int height);
            void setPosition(int x, int y);
            int getWidth() const;
            int getHeight() const;
            void setRotation(float angle);

        private:
            SDL_Surface *_image;
            SDL_Texture *_texture = nullptr;
            SDL_Rect _rect;
            float _angle = 0;
    };
} // namespace arc

#endif /* !SPRITE_HPP_ */
