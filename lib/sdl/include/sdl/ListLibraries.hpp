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
#include "Utils.hpp"
#include <functional>
#include <vector>
#include <memory>

namespace arc
{
    class ListLibraries {
        public:
            ListLibraries();
            ~ListLibraries();

            void setPosition(int x, int y);
            void setFont(const std::string &path);
            void setEventList(const std::function<void (const std::string &)> &fct);
            void setNameList(const std::string &nameList);
            void setNameLibraries(const std::vector<std::string> &list, int chosen);
            bool event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event);

            void display(SDL_Renderer *window);
            bool hasASelectButton() const;
            void changeColor();

        private:
            void initRects();

            void resetButtonsList();

            void eventListButtons(const std::string &name);

            void eventScrollDown();
            void eventScrollUp();

        private:
            std::vector<Rectangle> _rects;
            std::vector<std::shared_ptr<Text>> _texts;
            std::vector<std::pair<ButtonRect, std::string>> _buttonsList;

            std::function<void(const std::string &)> _eventList;
            std::string _font;

            int _begin = 0;
    };
} // namespace arc

#endif /* !LISTLIBRARIES_HPP_ */
