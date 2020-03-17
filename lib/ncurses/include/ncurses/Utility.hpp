/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Utility
*/

#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <ncurses.h>
#include "Utils.hpp"

namespace arc
{
    class Utility {
        public:

            static void display(const std::string &text, int x, int y, int noPair);
            static std::string getText(const std::string &path);
            static int generatePairColor(int textColor, int bgColor);
            static arc::Event::Type getEventType(int c);
            static arc::Event::Key getEventKey(int c);

        protected:
        private:
    };
};

#endif /* !UTILITY_HPP_ */
