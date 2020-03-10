/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** MenuScene
*/

#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include "IScene.hpp"
#include <vector>
#include "Button.hpp"
#include "Text.hpp"
#include "Input.hpp"

namespace arc
{
    class SceneMenu : public IScene {

        private:
            enum SceneState {
                GET_USERNAME,
                MENU
            };


        public:
            SceneMenu();
            ~SceneMenu();

            void init() override;
            void display(sf::RenderWindow &window) override;
            void event(sf::RenderWindow &window, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress) override;

            void setFont(const sf::Font &font);

            void setFunctionExit(const std::function<void()> &);
            void setFunctionPlay(const std::function<void()> &);

            void setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen = -1);
            void setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen = -1);

        private:
            void initButtons();
            void initTexts();
            void initInput();
            void initRects();

            void resetButtonsListGames();
            void resetButtonsListLibraries();

            /*
            ** List games and libraries management
            */
            void initButtonsListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct);
            void initButtonsListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct);
            void initTextsListGames(const std::vector<std::string> &games);
            void initTextsListLibraries(const std::vector<std::string> &libraries);


            void buttonsEvent(sf::RenderWindow &window, sf::Event &event);
            void inputEvent(sf::RenderWindow &window, sf::Event &event);

            void eventValidateUsername();

            void eventButtonPlay();

        private:
            SceneState _state = GET_USERNAME;

            std::vector<Button> _buttons;
            std::vector<Text> _texts;
            std::vector<Input> _inputs;
            std::vector<sf::RectangleShape> _rects;

            sf::Font _font;
            std::vector<std::pair<std::string, std::string>> _scores;

            std::function<void()> _eventExit;
            std::function<void()> _eventPlay;

            /*
            ** List games and libraries management
            */
            std::vector<Button> _buttonsListGames;
            std::vector<Button> _buttonsListLibraries;
            std::vector<Text> _textsListGames;
            std::vector<Text> _textsListLibraries;

            std::vector<Text> _textUsername;
            std::vector<Button> _buttonEnterUsername;
    };
}

#endif /* !MENUSCENE_HPP */
