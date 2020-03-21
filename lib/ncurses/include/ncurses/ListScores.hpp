/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScores
*/

#ifndef LISTSCORES_HPP_
#define LISTSCORES_HPP_

#include <vector>

#include "Text.hpp"
#include "Rectangle.hpp"
#include <ncurses.h>
#include "Button.hpp"

namespace arc
{
    class ListScores {
        public:
            ListScores();
            ~ListScores();

            void init();
            void setUsername(const std::string &username);
            void setScores(const std::vector<std::pair<std::string, std::string>> &scores);
            void display();
            void event(const MEVENT &event);

        private:
            void initTextsScores();

            void initRects();
            void initTexts();
            void initButtons();

            void scrollDown();
            void scrollUp();

        private:
            std::string _username;
            std::vector<std::pair<std::string, std::string>> _scores;

            std::vector<std::pair<Button, Button>> _textScores;

            std::vector<Rectangle> _rects;
            std::vector<Text> _texts;
            std::vector<Button> _buttons;

            int _begin = 0;
    };
} // namespace arc

#endif /* !LISTSCORES_HPP_ */
