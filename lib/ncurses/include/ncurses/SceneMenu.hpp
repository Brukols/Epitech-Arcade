/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenu
*/

#ifndef SCENEMENU_HPP
#define SCENEMENU_HPP

#include "IScene.hpp"
#include <functional>
#include <ncurses.h>
#include "ncurses/Rectangle.hpp"
#include "ncurses/Text.hpp"
#include "ncurses/Button.hpp"
#include "ColorsMode.hpp"
#include "Input.hpp"
#include "List.hpp"
#include "ncurses/SceneScores.hpp"

namespace arc
{
    class SceneMenu : public IScene {
        public:
            SceneMenu();
            ~SceneMenu();

            void init();
            void display();
            void event(arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress);

            void setFunctionExit(const std::function<void()> fct);
            void setFunctionPlay(const std::function<void()> &fct);

            const std::string &getUsername();
            void setUsername(const std::string &name);

            void setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen);
            void setListLibraries(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen);
            void setScores(const std::vector<std::pair<std::string, std::string>> &scores);
            void setHowToPlay(const std::vector<std::pair<std::string, std::string>> &info);

        private:
            void initRects();
            void initTexts();
            void initButtons();
            void initInputs();

            void eventShowScores();

            void eventButtons(MEVENT event);
            void eventInputs(MEVENT event);

        private:
            std::function<void()> _eventFunctionExit;
            std::function<void()> _eventFunctionPlay;

            std::vector<Rectangle> _rects;
            std::vector<Text> _texts;
            std::vector<Button> _buttons;
            std::vector<Input> _inputs;
            std::vector<Text> _howToPlay;

            std::string _username = "";

            std::vector<List> _lists;

            SceneScores _sceneScores;
    };
};

#endif /* !SCENEMENU_HPP */
