/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListLibraries
*/

#ifndef LISTLIBRARIES_HPP_
#define LISTLIBRARIES_HPP_

#include "sdl/Text.hpp"
#include "sdl/ButtonRect.hpp"
#include "sdl/Rectangle.hpp"
#include <functional>
#include <vector>
#include <memory>

namespace arc
{
    class ListLibraries {
        public:
            ListLibraries();
            ~ListLibraries();

            void setFont(const std::string &path);
            void setEventList(const std::function<void (const std::string &)> &fct);
            void setNameList(const std::string &nameList);
            void setNameLibraries(const std::vector<std::string> &list, int chosen);

            void display(SDL_Renderer *window);

        private:
            void initRects();

        private:
            std::vector<Rectangle> _rects;
            std::vector<Text> _texts;
            std::vector<std::pair<std::shared_ptr<IButton>, void (ListLibraries::*)()>> _buttons;

            std::function<void(const std::string &)> _eventList;
            std::string _font;
    };
} // namespace arc

#endif /* !LISTLIBRARIES_HPP_ */
