/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneGame
*/

#ifndef SCENEGAME_HPP
#define SCENEGAME_HPP

#include "IScene.hpp"
#include <vector>
#include "Button.hpp"
#include "Text.hpp"

namespace arc
{
    class SceneGame : public IScene {
        public:
            SceneGame();
            ~SceneGame();

            void init() override;
            void display(sf::RenderWindow &window) override;
            void event(sf::RenderWindow &window, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress) override;

            void setFont(const sf::Font &font);

            void initButtons();
            void initTexts();
            void initRects();

            void eventFunctionBackToMenu(std::function<void()> event);

        private:
            void eventButtons(sf::RenderWindow &window, sf::Event &event);


        private:
            std::vector<Button> _buttons;
            std::vector<Text> _texts;
            std::vector<sf::RectangleShape> _rects;
            sf::Font _font;

            std::function<void()> _eventFunctionBackToMenu;
    };
}

#endif /* !SCENEGAME_HPP */
