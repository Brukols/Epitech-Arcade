/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Text
*/

#ifndef TEXT_HPP
#define TEXT_HPP

#include <SFML/Graphics.hpp>
#include <string>

namespace arc
{
    class Text {
        public:
            Text(const sf::Font &font, const sf::Text &text);
            ~Text();

            void display(sf::RenderWindow &window);
            void setText(const std::string &text);
            void setDisplay(bool display);

        private:
            sf::Font _font;
            sf::Text _text;
            bool _display = true;
    };
}


#endif /* !TEXT_HPP */
