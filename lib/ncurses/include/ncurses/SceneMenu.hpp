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
#include "ncurses/Rectangle.hpp"

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

            void initButtonsListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct);
            void initButtonsListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct);

        private:
            void initRects();

        private:
            std::function<void()> _eventFunctionExit;

            std::vector<Rectangle> _rects;
    };
};

#endif /* !SCENEMENU_HPP */
