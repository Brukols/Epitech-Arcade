/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGame
*/

#ifndef SCENEGAME_HPP_
#define SCENEGAME_HPP_

#include "IScene.hpp"
#include "Button.hpp"
#include "Text.hpp"
#include "Rectangle.hpp"
#include <map>

#include <functional>

namespace arc
{
    class SceneGame : public IScene {
        public:
            SceneGame();
            ~SceneGame();

            void init() override;
            void display() override;
            void event(arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress) override;

            void setFunctionBackToMenu(const std::function<void()> &fct);
            void setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls);

        private:
            void initButtons();
            void initTexts();
            void initRects();

            void eventButtons(MEVENT event);

        private:

            std::function<void()> _eventBackToMenu;
            std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> _controls;

            std::vector<Button> _buttons;
            std::vector<Text> _texts;
            std::vector<Rectangle> _rects;
    };
};

#endif /* !SCENEGAME_HPP_ */
