/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ErrorMessage
*/

#ifndef ERRORMESSAGE_HPP_
#define ERRORMESSAGE_HPP_

#include "Button.hpp"
#include "Text.hpp"

namespace arc
{
    class ErrorMessage {
        public:
            ErrorMessage(const std::string &message, const std::function<void()> &event, const sf::Font &font);
            ~ErrorMessage();

            void display(sf::RenderWindow &window);
            bool isHoverButton(const sf::Vector2i &pos) const;
            void click();

        private:
            std::vector<Button> _button;
            std::vector<Text> _text;
            sf::RectangleShape _rect;

            std::function<void()> _event;
    };
} // namespace arc

#endif /* !ERRORMESSAGE_HPP_ */
