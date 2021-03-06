/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGame
*/

#ifndef SCENEENDGAME_HPP_
#define SCENEENDGAME_HPP_

#include "IScene.hpp"
#include "ListScores.hpp"
#include "Button.hpp"

namespace arc
{
    class SceneEndGame : public IScene {
        public:
            SceneEndGame();
            ~SceneEndGame();

            void init() override;
            void display(sf::RenderWindow &window) override;
            void event(sf::RenderWindow &window, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress) override;

            void setFunctionMenu(const std::function<void()> &function);
            void setFunctionRestart(const std::function<void()> &function);
            void setScores(const std::vector<std::pair<std::string, std::string>> &scores);
            void setUsername(const std::string &username);

        private:
            void initButtons();

            void eventButtons(const sf::Event &event, sf::RenderWindow &window);
            void eventRestart();
            void eventMenu();

        private:
            sf::Font _font;

            std::vector<std::pair<Button, void (SceneEndGame::*)()>> _buttons;

            std::function<void()> _eventMenu;
            std::function<void()> _eventRestart;
            std::vector<std::pair<std::string, std::string>> _scores;

            ListScores _listScores;

            bool _exit = false;
    };
} // namespace arc

#endif /* !SCENEENDGAME_HPP_ */
