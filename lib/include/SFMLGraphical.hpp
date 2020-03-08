/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLGRAPHICLA
*/

#ifndef SFMLGRAPHICAL_HPP
#define SFMLGRAPHICAL_HPP

#include "IGraphical.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Utils.hpp"

namespace arc
{
 
    class SFMLGraphical : public IGraphical {

        public:
            SFMLGraphical();
            ~SFMLGraphical();


            /*
            ** Override methods for IGraphical
            */

            void display() override;
            Event::Type getEventType() override;
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
            void setSprites(const std::map<char, std::string> &sprites) override;
            void setBackgroundColors(const std::map<char, Color> &sprites) override;
            void updateGameInfo(const std::vector<Entity> &entities) override;

            void setMusic(const std::string &music) override;
            void playSound(const std::string &sound) override;

            /*
            ** End of override methods for IGraphical
            */

        private:
            arc::Event::Key getKey(sf::Event event) const;
            void displayMenu();
            // void displayPauseMenu();
            // void displayGame();
            // void displayEndGame();
            // void displayList();
            // void displayHowToPlay();
            // void displayGetInput();
            void drawButton(const std::string &name, const sf::Vector2f &size, const sf::Vector2f &pos, const sf::Color &color);
            void drawText(const std::string &name, size_t size, const sf::Vector2f &pos, const sf::Color &color);

        private:
            std::unique_ptr<sf::RenderWindow> _window;

            std::vector<std::string> _listGames;
            std::vector<std::string> _listLibraries;
            std::vector<std::pair<std::string, std::string>> _scores;
            std::function<void (const std::string &)> _eventChooseGame;
            std::function<void (const std::string &)> _eventChooseLibrary;

            std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> _controls;

            std::function<void()> _eventPlayButton;
            std::function<void()> _eventRestartButton;
            std::function<void()> _eventMenuButton;
            std::function<void()> _eventTogglePauseButton;

            std::vector<Entity> _entities;
            std::string _username;

            arc::Event::Type _actualEventType = arc::Event::Type::NO_EVENT;
            arc::Event::Key _actualKeyPress = arc::Event::Key::NONE;

            arc::IGraphical::Scene _actualScene = arc::IGraphical::Scene::MAIN_MENU;

            sf::Font _font;

            std::vector<std::pair<std::string, std::string>> _infoHowToPlay;
            std::vector<std::string> _infoGameStat;

            std::map<char, std::string> _sprites;
            std::map<char, Color> _backgroundColors;
    };

};

#endif /* !SFMLGRAPHICAL_HPP */
