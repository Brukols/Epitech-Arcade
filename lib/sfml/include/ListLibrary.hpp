/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ListLibrary
*/

#ifndef LISTLIBRARY_HPP
#define LISTLIBRARY_HPP

#include <string>
#include <vector>
#include <functional>
#include "Button.hpp"
#include "Text.hpp"
#include <SFML/Graphics.hpp>
#include "Utils.hpp"

namespace arc
{
    class ListLibrary {
        public:
            ListLibrary();
            ~ListLibrary();

            void setListGames(const std::vector<std::string> &name, const std::function<void(const std::string &)> &event,
                const sf::Font &font);
            void setListLibraries(const std::vector<std::string> &name, const std::function<void(const std::string &)> &event,
                const sf::Font &font);
            void display(sf::RenderWindow &window);

        private:
            void initButtonsGames(const std::vector<std::string> &name);
            void initButtonsLibraries(const std::vector<std::string> &name);
            void initTextsGames(const std::vector<std::string> &name);
            void initTextsLibraries(const std::vector<std::string> &name);
        
        private:

            std::vector<std::string> _listGames;
            std::vector<std::string> _listLibraries;
            std::vector<Button> _buttonGames;
            std::vector<Button> _buttonLibs;
            std::vector<Text> _textGames;
            std::vector<Text> _textLibs;
            std::function<void(const std::string &)> _eventChooseGame;
            std::function<void(const std::string &)> _eventChooseLibrary;
            sf::Font _font;
    };
};

#endif /* !LISTLIBRARY_HPP */
