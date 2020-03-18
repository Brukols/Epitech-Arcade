/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneError
*/

#ifndef SCENEERROR_HPP_
#define SCENEERROR_HPP_

#include "Button.hpp"
#include "IScene.hpp"
#include "ColorsMode.hpp"

namespace arc
{
    class SceneError : public IScene {
        public:
            SceneError();
            ~SceneError();

            void init() override;
            void display() override;
            void event(arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress) override;

            void setFunctionBack(const std::function<void()> &eventBack);
            void setErrorMessage(const std::string &msg);

            void clear();

        private:
            void initRects();
            void initButtons();
            void initTexts();
            void eventButtons(MEVENT event);

        private:
            std::vector<Button> _buttons;
            std::vector<Text> _texts;
            std::vector<Rectangle> _rects;

            std::function<void()> _eventBack;
            std::string _errorMsg;
    };
};

#endif /* !SCENEERROR_HPP_ */
