/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "Utils.hpp"
#include <string>
#include "ncurses/Utility.hpp"

namespace arc
{
    class Text {
        public:
            Text(const std::string &name, int textColor, int bgColor);
            ~Text();

            void setPosition(int x, int y);
            void display();

        private:
            std::string _text;

            int _noPair;

            int _x;
            int _y;
    };
};

#endif /* !TEXT_HPP_ */
