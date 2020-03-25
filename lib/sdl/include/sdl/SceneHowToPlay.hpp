/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** SceneHowToPlay
*/

#ifndef SCENEHOWTOPLAY_HPP_
#define SCENEHOWTOPLAY_HPP_

#include "Text.hpp"
#include "Rectangle.hpp"
#include <memory>
#include "ButtonRect.hpp"
#include <vector>
#include "Utils.hpp"

namespace arc
{
    class SceneHowToPlay {
        public:
            SceneHowToPlay();
            ~SceneHowToPlay();

            void display(SDL_Renderer *window);
        
            bool isActivate() const;
            void setActivate(bool activate);

            void event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event);

        private:
            void initButtonOk();
            void initTexts();
            void initBg();
            void initCase();

            void eventButtonOk();

        private:
            std::unique_ptr<ButtonRect> _buttonOk;
            std::vector<std::unique_ptr<Text>> _texts;
            std::unique_ptr<Rectangle> _bg;
            std::unique_ptr<Rectangle> _case;

            bool _activate = false;
    };
} // namespace arc

#endif /* !SCENEHOWTOPLAY_HPP_ */
