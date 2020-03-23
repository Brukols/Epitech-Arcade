/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenu
*/

#ifndef SCENEMENU_HPP_
#define SCENEMENU_HPP_

#include "IScene.hpp"
#include "Rectangle.hpp"
#include "Text.hpp"
#include <algorithm>

namespace arc
{
    class SceneMenu : public IScene {
        public:
            SceneMenu();
            ~SceneMenu();

            void init();
            void display(SDL_Renderer *window);
            void event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress);

        private:
            void initRects();
            void initTexts();
        
        private:
            std::vector<Rectangle> _rects;
            std::vector<Text> _texts;
    };
} // namespace arc

#endif /* !SCENEMENU_HPP_ */
