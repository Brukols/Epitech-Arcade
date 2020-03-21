/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGame
*/

#ifndef SCENEENDGAME_HPP_
#define SCENEENDGAME_HPP_

#include "IScene.hpp"
#include "Button.hpp"
#include "Text.hpp"
#include "Rectangle.hpp"

#include <vector>

namespace arc
{
    class SceneEndGame : public IScene {
        public:
            SceneEndGame();
            ~SceneEndGame();

            void init() override;
            void display() override;
            void event(arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress) override;

            void setFunctionMenu(const std::function<void()> &function);
            void setFunctionRestart(const std::function<void()> &function);
            void setScores(const std::vector<std::pair<std::string, std::string>> &scores);
            void setUsername(const std::string &username);

        private:
            void initButtons();

            void eventButtons(const MEVENT &event);

        private:
            std::vector<Button> _buttons;
            std::vector<Rectangle> _rects;

            std::function<void()> _eventMenu;
            std::function<void()> _eventRestart;
    };
} // namespace arc

#endif /* !SCENEENDGAME_HPP_ */
