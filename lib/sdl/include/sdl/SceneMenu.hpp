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
#include "ButtonRect.hpp"
#include <algorithm>
#include <memory>

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
            void initButtons();
        
        private:
            std::vector<Rectangle> _rects;
            std::vector<Text> _texts;
            std::vector<std::shared_ptr<IButton>> _buttons;
    };
} // namespace arc

#endif /* !SCENEMENU_HPP_ */
