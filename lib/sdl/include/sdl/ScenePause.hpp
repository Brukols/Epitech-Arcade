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
#include "ButtonRect.hpp"
#include <functional>
#include "Utils.hpp"

namespace arc
{
    class ScenePause {
        public:
            ScenePause();
            ~ScenePause();

            void display(SDL_Renderer *window);

            bool isActivate() const;
            void setActivate(bool activate);

            void setFunctionTogglePause(const std::function<void()> &function);
            void event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event);

            void changeColor();

        private:
            void eventTogglePause();
            void initButtonPlay();

        private:
            std::unique_ptr<Rectangle> _bg;
            std::unique_ptr<Text> _textPause;
            std::unique_ptr<ButtonRect> _buttonPlay;

            std::function<void()> _eventTogglePause;

            bool _activate = false;
    };
} // namespace arc

#endif /* !SCENEPAUSE_HPP_ */