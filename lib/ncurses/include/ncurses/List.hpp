/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** List
*/

#ifndef LIST_HPP_
#define LIST_HPP_

#include "Button.hpp"
#include "Rectangle.hpp"
#include "Text.hpp"
#include <vector>

namespace arc
{
    class List {
        public:
            List(const std::vector<std::string> &list, int chosen, const std::string &nameList, const std::function<void (const std::string &)> &fct);
            ~List();

            void display();
            void setPosition(size_t x, size_t y);
            void event(const MEVENT &event);

            void setColors(int outlineColorRect, int bgColorList, int textColorList, int bgColorHoverList, int textColorHoverList);

        private:
            void initButtons();
            void initButtonsList(const std::vector<std::string> &list, int chosen, const std::function<void(const std::string &)> &fct);
            void resetButtonsList();
            void functionKeyDown();
            void functionKeyUp();

        private:
            Rectangle _bgRect;
            Text _title;
            
            std::vector<Button> _buttons;
            std::vector<Button> _buttonsList;

            std::function<void(const std::string &)> _eventList;

            int _begin = 0;
    };
} // namespace arc

#endif /* !LIST_HPP_ */
