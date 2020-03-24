/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScores
*/

#ifndef LISTSCORES_HPP_
#define LISTSCORES_HPP_

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "Utils.hpp"
#include <memory>
#include "Rectangle.hpp"
#include "ButtonRect.hpp"
#include <algorithm>

namespace arc
{
    class ListScores {
        public:
            ListScores();
            ~ListScores();

            void init();
            void setUsername(const std::string &username);
            void setScores(const std::vector<std::pair<std::string, std::string>> &scores);
            void display(SDL_Renderer *window);
            void event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event);

            bool isMouseHover() const;

        private:
            void initRects();
            void initTexts();

            void eventScrollUp();
            void eventScrollDown();

        private:
            std::vector<std::unique_ptr<Rectangle>> _rects;
            std::vector<std::unique_ptr<Text>> _texts;
            std::vector<std::pair<std::unique_ptr<ButtonRect>, std::unique_ptr<ButtonRect>>> _buttons;
            std::string _username = "";

            int _begin = 0;
    };
} // namespace arc

#endif /* !LISTSCORES_HPP_ */
