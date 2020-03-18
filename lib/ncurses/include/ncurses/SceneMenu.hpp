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
            void initButtonsListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen);
            void initButtonsListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen);

        private:
            void initRects();
            void initTexts();
            void initButtons();
            void initInputs();

            void eventButtons(MEVENT event);
            void eventInputs(MEVENT event);
            void resetListGames();
            void resetListLibraries();

        private:
            std::function<void()> _eventFunctionExit;
            std::function<void()> _eventFunctionPlay;
            std::function<void(const std::string &)> _eventListGames;
            std::function<void(const std::string &)> _eventListLibs;

            std::vector<Rectangle> _rects;
            std::vector<Text> _texts;
            std::vector<Button> _buttons;
            std::vector<Input> _inputs;

            std::vector<Button> _buttonsListGames;
            std::vector<Button> _buttonsListLibraries;

            std::string _username = "";
    };
};

#endif /* !SCENEMENU_HPP */
