/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GRAPHICLA
*/

#ifndef GRAPHICAL_HPP
#define GRAPHICAL_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "IGraphical.hpp"
#include "Utils.hpp"
#include "Button.hpp"
#include "Text.hpp"
#include "IScene.hpp"

namespace arc
{
 
    class Graphical : public IGraphical {

        public:
            Graphical();
            ~Graphical();


            /*
            ** Override methods for IGraphical
            */

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

            const std::string &getUsername() const override;
            Scene getScene() const override;
            void setScene(Scene scene) override;

            void setHowToPlay(const std::vector<std::pair<std::string, std::string>> &info) override;
            void setGameStatsFormatString(const std::vector<std::string> &info) override;
            void setFont(const std::string &font) override;
            void updateGameInfo(const std::vector<std::shared_ptr<Entity>> &gameMap) override;
            void setVisualAssets(const std::map<char, std::pair<std::string, Color>> &sprites);

            void setMusic(const std::string &music) override;
            void playSound(const std::string &sound) override;

            void setMapSize(size_t height, size_t width);
            void setGameTitle(const std::string &game);

            /*
            ** End of override methods for IGraphical
            */

        private:
            sf::RenderWindow _window;

            std::map<Scene, std::unique_ptr<IScene>> _scenes;

            std::vector<std::pair<std::string, std::string>> _scores;

            std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> _controls;

            std::function<void()> _eventRestartButton; // A suppr
            std::function<void()> _eventMenuButton; // A suppr
            std::function<void()> _eventTogglePauseButton; // A suppr

            std::vector<std::shared_ptr<Entity>> _entities;
            std::string _username;

            arc::Event::Type _actualEventType = arc::Event::Type::NO_EVENT;
            arc::Event::Key _actualKeyPress = arc::Event::Key::NONE;

            arc::IGraphical::Scene _actualScene = arc::IGraphical::Scene::MAIN_MENU;

            sf::Font _font;

            std::vector<std::pair<std::string, std::string>> _infoHowToPlay;
            std::vector<std::string> _infoGameStat;

            std::map<char, std::string> _sprites;
            std::map<char, Color> _backgroundColors;

            bool _exit = false;
    };
};

#endif /* !GRAPHICAL_HPP */
