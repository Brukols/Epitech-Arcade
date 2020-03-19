/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** MenuScene
*/

#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include "sfml/IScene.hpp"
#include <vector>
#include "sfml/Button.hpp"
#include "sfml/Text.hpp"
#include "sfml/Input.hpp"
#include "sfml/Image.hpp"
#include "List.hpp"
#include <functional>
#include "ErrorMessage.hpp"

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

            const std::string &getUsername();
            void setUsername(const std::string &name);

            void setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen);
            void setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen);

        private:
            void initButtons();
            void initTexts();
            void initInput();
            void initRects();
            void initImages();

            bool inputIsFocus() const;

            void buttonsEvent(sf::RenderWindow &window, sf::Event &event);
            void inputEvent(sf::RenderWindow &window, sf::Event &event);

            void eventValidateUsername();

            void eventButtonPlay();
            void eventErrorMessage(sf::Event &event);

        private:
            SceneState _state = GET_USERNAME;

            std::vector<Button> _buttons;
            std::vector<Text> _texts;
            std::vector<Input> _inputs;
            std::vector<sf::RectangleShape> _rects;

            std::vector<Image> _images;

            sf::Font _font;
            std::vector<std::pair<std::string, std::string>> _scores;

            std::function<void()> _eventExit;
            std::function<void()> _eventPlay;

            std::vector<Text> _textUsername;
            std::vector<Button> _buttonEnterUsername;

            std::string _username;

            std::vector<ErrorMessage> _errorMessages;

            bool _exit = false;

            std::vector<List> _lists;
    };
}

#endif /* !MENUSCENE_HPP */
