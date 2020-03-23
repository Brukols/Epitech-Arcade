/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphical
*/

#ifndef GRAPHICAL_HPP_
#define GRAPHICAL_HPP_

#include "IGraphical.hpp"
#include <SDL2/SDL.h>
#include <map>
#include "IScene.hpp"

namespace arc
{
    class Graphical : public IGraphical {
        public:
            Graphical();
            ~Graphical();

            void display() override;
            Event::Type getEventType() const override;
            Event::Key getKeyPressed() const override;

            void setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen = -1) override;
            void setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen = -1) override;
            void setScores(const std::vector<std::pair<std::string, std::string>> &scores) override;

            void setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls) override;

            void setFunctionPlay(const std::function<void()> &function) override;
            void setFunctionRestart(const std::function<void()> &function) override;
            void setFunctionMenu(const std::function<void()> &function) override;
            void setFunctionTogglePause(const std::function<void()> &function) override;

            const std::string &getUsername() override;
            void setUsername(const std::string &username) override;

            Scene getScene() const override;
            void setScene(Scene scene) override;

            void setHowToPlay(const std::vector<std::pair<std::string, std::string>> &info) override;
            void setGameStats(const std::vector<std::pair<std::string, std::string>> &info) override;
            void updateGameInfo(const std::vector<std::shared_ptr<Entity>> &gameMap) override;

            void setMapSize(size_t height, size_t width) override;
            void setGameTitle(const std::string &game) override;

        private:
            SDL_Window *_window;

            std::map<Scene, std::unique_ptr<IScene>> _scenes;

            arc::Event::Type _actualEventType = arc::Event::Type::NO_EVENT;
            arc::Event::Key _actualKeyPress = arc::Event::Key::NONE;

            arc::IGraphical::Scene _actualScene = arc::IGraphical::Scene::MAIN_MENU;

            bool _exit = false;

            std::string _username = ""; // A suppr
    };
} // namespace arc

#endif /* !GRAPHICAL_HPP_ */
