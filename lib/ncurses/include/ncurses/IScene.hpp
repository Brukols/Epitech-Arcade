/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Iscnee
*/

#ifndef ISCENE_HPP
#define ISCENE_HPP

#include <ncurses.h>
#include "Utils.hpp"

namespace arc
{
    class IScene {
        public:

            virtual void init() = 0;
            virtual void display(WINDOW *win) = 0;
            virtual void event(WINDOW *win, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress) = 0;

        protected:
        private:
    };
}

#endif /* !ISCENE_HPP */
