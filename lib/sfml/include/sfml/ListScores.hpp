/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScores
*/

#ifndef LISTSCORES_HPP_
#define LISTSCORES_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Text.hpp"

namespace arc
{
    class ListScores {
        public:
            ListScores();
            ListScores(const sf::Font &font, const std::vector<std::pair<std::string, std::string>> &scores, const std::string &username);
            ~ListScores();

            void init();
            void setFont(const sf::Font &font);
            void setUsername(const std::string &username);
            void setScores(const std::vector<std::pair<std::string, std::string>> &scores);
            void display(sf::RenderWindow &window);

        private:
            void initTextsScores();

        private:
            sf::Font _font;
            std::string _username;
            std::vector<std::pair<std::string, std::string>> _scores;

            std::vector<std::pair<Text, Text>> _textScores;
    };
} // namespace arc

#endif /* !LISTSCORES_HPP_ */
