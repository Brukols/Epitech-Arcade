/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Text
*/

#ifndef TEXT_HPP
#define TEXT_HPP

#include <SFML/Graphics.hpp>

namespace arc
{
    class Text {
        public:
            Text(const sf::Font &font, const sf::Text &text);
            ~Text();

            void display(sf::RenderWindow &window);

        private:
            sf::Font _font;
            sf::Text _text;
    };
}


#endif /* !TEXT_HPP */
