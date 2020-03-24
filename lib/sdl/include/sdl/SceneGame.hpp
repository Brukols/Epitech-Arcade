/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGame
*/

#ifndef SCENEGAME_HPP_
#define SCENEGAME_HPP_

#include "IScene.hpp"
#include "sdl/Rectangle.hpp"
#include "sdl/ButtonRect.hpp"
#include "sdl/Text.hpp"
#include <vector>
#include <map>
#include <functional>

namespace arc
{
    class SceneGame : public IScene {
        public:
            SceneGame();
            ~SceneGame();

            /*
            Override function
            */
            void init() override;
            void display(SDL_Renderer *window) override;
            void event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress) override;

            /*
            Function from Graphical
            */
            void setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls);
            void setFunctionMenu(const std::function<void()> &function);
            void setFunctionTogglePause(const std::function<void()> &function);
            void setHowToPlay(const std::vector<std::pair<std::string, std::string>> &info);
            void setGameStats(const std::vector<std::pair<std::string, std::string>> &info);
            void updateGameInfo(const std::vector<std::shared_ptr<Entity>> &gameMap);
            void setMapSize(size_t height, size_t width);
            void setGameTitle(const std::string &game);

        private:
            void initRects();
            void initButtons();

            void eventMenu();

            void eventButtons(const arc::Event::Type &type, const arc::Event::Key &key);

        private:
            std::vector<std::unique_ptr<Rectangle>> _rects;
            std::vector<std::unique_ptr<Text>> _texts;
            std::vector<std::pair<std::unique_ptr<IButton>, void (SceneGame::*)()>> _buttons;

            std::unique_ptr<Text> _title;

            std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> _controls;
            std::vector<std::shared_ptr<Entity>> _gameMap;
            std::function<void()> _eventMenu;
            std::function<void()> _eventPause;

            std::unique_ptr<Rectangle> _cell;
    };
} // namespace arc

#endif /* !SCENEGAME_HPP_ */
