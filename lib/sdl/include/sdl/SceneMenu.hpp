/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenu
*/

#ifndef SCENEMENU_HPP_
#define SCENEMENU_HPP_

#include "sdl/IScene.hpp"
#include "sdl/Rectangle.hpp"
#include "sdl/Text.hpp"
#include "sdl/ButtonRect.hpp"
#include <algorithm>
#include <memory>
#include "sdl/ListLibraries.hpp"
#include "sdl/ListScores.hpp"
#include "sdl/SceneScores.hpp"
#include "sdl/Input.hpp"
#include "sdl/SceneHowToPlay.hpp"

namespace arc
{
    class SceneMenu : public IScene {
        public:
            SceneMenu();
            ~SceneMenu();

            void init();
            void display(SDL_Renderer *window);
            void event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress);

            void setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen);
            void setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen);
            void setHowToPlay(const std::vector<std::pair<std::string, std::string>> &info);

            void setFunctionPlay(const std::function<void()> &function);
            void setScores(const std::vector<std::pair<std::string, std::string>> &scores);

            const std::string &getUsername();
            void setUsername(const std::string &username);

        private:
            void initRects();
            void initTexts();
            void initButtons();
            void initInputUsername();

            void eventExit();
            void eventPlay();
            void eventShowScores();
            void eventHowToPlay();
            void eventChangeTheme();

            void eventButtons(const arc::Event::Type &type, const arc::Event::Key &key);
        
        private:
            std::vector<Rectangle> _rects;
            std::vector<std::shared_ptr<Text>> _texts;
            std::vector<std::pair<std::shared_ptr<IButton>, void (SceneMenu::*)()>> _buttons;
            ListLibraries _listGraphical;
            ListLibraries _listGames;

            std::function<void()> _eventPlay;

            std::unique_ptr<ListScores> _listScores;

            std::unique_ptr<SceneScores> _sceneScores;

            std::unique_ptr<Input> _inputUsername;

            std::unique_ptr<SceneHowToPlay> _sceneHowToPlay;

            bool _exit = false;
    };
} // namespace arc

#endif /* !SCENEMENU_HPP_ */
