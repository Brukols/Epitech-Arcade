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
            const std::string getInput();

            void display(sf::RenderWindow &window);

        private:
            sf::RectangleShape _rect;
            sf::RectangleShape _cursor;
            sf::Text _textHover;
            sf::Text _text;
            sf::String _str;
            bool _focus = false;
            bool _display = true;
            int _position = 0;
    };
} // namespace arc

#endif /* !INPUT_HPP */
