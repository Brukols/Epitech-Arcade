/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** SceneHowToPlay
*/

#ifndef SCENEHOWTOPLAY_HPP_
#define SCENEHOWTOPLAY_HPP_

#include "Utils.hpp"
#include "Button.hpp"
#include "Text.hpp"

namespace arc
{
    class SceneHowToPlay {
        public:
            SceneHowToPlay();
            ~SceneHowToPlay();

            void display(sf::RenderWindow &window);

            bool isActivate() const;
            void setActivate(bool activate);

            void event(const sf::Event &event);
            void setFont(const sf::Font &font);

        private:
            void initBg();
            void initCase();
            void initTexts();
            void initButtonOk();

            void eventButtonOk();

        private:
            sf::Font _font;
            sf::RectangleShape _bg;
            std::vector<std::unique_ptr<Text>> _texts;
            std::unique_ptr<Button> _buttonOk;
            sf::RectangleShape _case;

            bool _activate = false;
    };
} // namespace arc

#endif /* !SCENEHOWTOPLAY_HPP_ */
