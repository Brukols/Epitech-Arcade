/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** ScenePause
*/

#ifndef SCENEPAUSE_HPP_
#define SCENEPAUSE_HPP_

#include "IScene.hpp"
#include "Rectangle.hpp"
#include <functional>
#include <memory>
#include "Text.hpp"
#include "Button.hpp"

namespace arc
{
    class ScenePause : public IScene {
        public:
            ScenePause();
            ~ScenePause();

            void init() override;
            void display() override;
            void event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress) override;

            bool isActivate() const;
            void setActivate(bool activate);

            void setFunctionTogglePause(const std::function<void()> &function);

        private:
            void eventTogglePause();
        
        private:
            std::unique_ptr<Text> _textPause;
            std::unique_ptr<Button> _buttonPlay;

            std::function<void()> _eventTogglePause;

            bool _activate = false;

    };
} // namespace arc

#endif /* !SCENEPAUSE_HPP_ */
