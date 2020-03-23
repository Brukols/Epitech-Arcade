/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenu
*/

#ifndef SCENEMENU_HPP_
#define SCENEMENU_HPP_

#include "IScene.hpp"

namespace arc
{
    class SceneMenu : public IScene {
        public:
            SceneMenu();
            ~SceneMenu();

            void init();
            void display(SDL_Window *window);
            void event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress);

        private:
    };
} // namespace arc

#endif /* !SCENEMENU_HPP_ */
