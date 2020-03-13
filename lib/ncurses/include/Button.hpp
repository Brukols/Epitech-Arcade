/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Button
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <functional>

namespace arc
{
    typedef struct Rect
    {
        size_t top;
        size_t left;
        size_t bottom;
        size_t right;
    } Rect;
    
    class Button {
        public:
            Button(const std::string &name, const Rect &rect, const std::function<void()> &event);
            ~Button();

        private:
            Rect _rect;
            std::function<void()> _event;
    };
} // namespace arc

#endif /* !BUTTON_HPP */
