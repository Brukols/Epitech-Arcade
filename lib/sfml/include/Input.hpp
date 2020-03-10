/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Input
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Graphics.hpp>

namespace arc
{
    class Input {
        public:
            Input(const sf::RectangleShape &rect, const sf::Text &text);
            ~Input();

            void addLetter(const sf::Event &event);
            void removeLetter();
            void setFocus(bool focus);
            bool isFocus() const;
            void setDisplay(bool display);

            void display(sf::RenderWindow &window);

        private:
            sf::RectangleShape _rect;
            sf::Text _text;
            sf::String _str;
            bool _focus = false;
            bool _display = true;
    };
} // namespace arc

#endif /* !INPUT_HPP */
