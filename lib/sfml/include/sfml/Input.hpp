/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Input
*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Graphics.hpp>
#include "Utils.hpp"
#include <ctime>

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
            void event(const sf::Event &event);

        private:
            void deleteCharacterForSuppr();
            void resetClock();

        private:
            sf::RectangleShape _rect;
            sf::RectangleShape _cursor;
            sf::Text _textHover;
            sf::Text _text;
            sf::String _str;
            bool _focus = false;
            bool _display = true;
            int _position = 0;

            std::clock_t _clock;
            bool _displayCursor = true;
    };
} // namespace arc

#endif /* !INPUT_HPP */
