/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** ScenePause
*/

#ifndef SCENEPAUSE_HPP_
#define SCENEPAUSE_HPP_

#include <SDL2/SDL.h>
#include "Rectangle.hpp"
#include "Text.hpp"
#include <memory>

namespace arc
{
    class ScenePause {
        public:
            ScenePause();
            ~ScenePause();

            void display(SDL_Renderer *window);

            bool isActivate() const;
            void setActivate(bool activate);

        private:
            std::unique_ptr<Rectangle> _bg;
            std::unique_ptr<Text> _textPause;

            bool _activate = false;
    };
} // namespace arc

#endif /* !SCENEPAUSE_HPP_ */