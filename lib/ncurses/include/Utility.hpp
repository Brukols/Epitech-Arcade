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

            static void display(const std::string &text, Color &textColor, Color &bgColor, int x, int y);

        protected:
        private:
    };
};

#endif /* !UTILITY_HPP_ */
