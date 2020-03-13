/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenu
*/

#ifndef SCENEMENU_HPP
#define SCENEMENU_HPP

#include "IScene.hpp"
#include <functional>
#include <ncurses.h>

namespace arc
{
    class SceneMenu : public IScene {
        public:
            SceneMenu();
            ~SceneMenu();

            void init();
            void display(WINDOW *win);
            void event(WINDOW *win, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress);

            void setFunctionExit(std::function<void()> fct);

        private:
            std::function<void()> _eventFunctionExit;
    };
};

#endif /* !SCENEMENU_HPP */
