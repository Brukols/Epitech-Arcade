/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneScores
*/

#ifndef SCENESCORES_HPP_
#define SCENESCORES_HPP_

#include "IScene.hpp"
#include <vector>
#include "Button.hpp"
#include "ListScores.hpp"

namespace arc
{
    class SceneScores : public IScene {
        public:
            SceneScores();
            ~SceneScores();

            void init() override;
            void display() override;
            void event(arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress) override;

            void setUsername(const std::string &username);
            void setScores(const std::vector<std::pair<std::string, std::string>> &scores);

            bool isActivate() const;
            void setActivate(bool activate);

            void setEventFunctionExit(const std::function<void()> &event);

        private:
            void initButtons();

            void eventButtons(MEVENT &event);

            void eventButtonBack();

        private:
            std::vector<std::pair<Button, void (SceneScores::*)() >> _buttons;
            ListScores _listScores;
            
            std::function<void()> _eventFunctionExit;

            bool _activate = false;
    };
} // namespace arc

#endif /* !SCENESCORES_HPP_ */
