/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** ScenePause
*/

#ifndef SCENEPAUSE_HPP_
#define SCENEPAUSE_HPP_

#include <memory>
#include <functional>
#include "Text.hpp"
#include "Button.hpp"
#include "Utils.hpp"

namespace arc
{
    class ScenePause {
        public:
            ScenePause();
            ~ScenePause();

            void display(sf::RenderWindow &window);

            bool isActivate() const;
            void setActivate(bool activate);

            void setFunctionTogglePause(const std::function<void()> &function);
            void event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const sf::Event &event, sf::RenderWindow &window);
            void setFont(const sf::Font &font);

        private:
            void eventTogglePause();
            void initButtonPlay();

        private:
            sf::RectangleShape _bg;
            std::unique_ptr<Text> _textPause;
            std::unique_ptr<Button> _buttonPlay;

            std::function<void()> _eventTogglePause;
            sf::Font _font;

            bool _activate = false;
    };
} // namespace arc

#endif /* !SCENEPAUSE_HPP_ */
