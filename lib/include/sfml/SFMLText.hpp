/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLText
*/

#ifndef SFMLTEXT_HPP
#define SFMLTEXT_HPP

#include <SFML/Graphics.hpp>

namespace arc
{
    class SFMLText {
        public:
            SFMLText(const sf::Font &font, const sf::Text &text);
            ~SFMLText();

            void display(sf::RenderWindow &window);

        private:
            sf::Font _font;
            sf::Text _text;
    };
}


#endif /* !SFMLTEXT_HPP */
