/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneGame
*/

#ifndef SCENEGAME_HPP
#define SCENEGAME_HPP

#include "IScene.hpp"

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

        private:
            
    };
}

#endif /* !SCENEGAME_HPP */
