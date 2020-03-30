/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGame
*/

#ifndef SCENEENDGAME_HPP_
#define SCENEENDGAME_HPP_

#include "IScene.hpp"
#include "ButtonRect.hpp"
#include "ListScores.hpp"

#include <functional>
#include <vector>

namespace arc
{
    class SceneEndGame : public IScene {
        public:
            SceneEndGame();
            ~SceneEndGame();

            void init() override;
            void display(SDL_Renderer *window) override;
            void event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress) override;

            void setScores(const std::vector<std::pair<std::string, std::string>> &scores);
            void setFunctionRestart(const std::function<void()> &function);
            void setFunctionMenu(const std::function<void()> &function);

            void setUsername(const std::string &username);

        private:
            void initButtons();
            
            void eventRestart();
            void eventMenu();
            void eventButtons(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress);

        private:
            std::vector<std::pair<std::unique_ptr<IButton>, void (SceneEndGame::*)()>> _buttons;

            std::function<void()> _eventRestart;
            std::function<void()> _eventMenu;

            std::unique_ptr<ListScores> _listScores;
    };
} // namespace arc

#endif /* !SCENEENDGAME_HPP_ */
