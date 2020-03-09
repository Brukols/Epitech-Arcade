/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** MenuScene
*/

#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include "IScene.hpp"
#include <vector>
#include "Button.hpp"
#include "Text.hpp"

namespace arc
{
    class SceneMenu : public IScene {
        public:
            SceneMenu();
            ~SceneMenu();

            void init() override;
            void display(sf::RenderWindow &window) override;
            void event(sf::RenderWindow &window, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress) override;

            void setFont(const sf::Font &font);

        private:
            void initButtons();
            void initTexts();

        private:
            std::vector<Button> _buttons;
            std::vector<Text> _texts;
            sf::Font _font;
            std::vector<std::pair<std::string, std::string>> _scores;
    };
}

#endif /* !MENUSCENE_HPP */
