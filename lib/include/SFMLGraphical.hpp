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

namespace arc
{
 
    class SFMLGraphical : public IGraphical {

        public:
            SFMLGraphical();
            ~SFMLGraphical();

            // OVERRIDE

            void display() override;
            Event::Type getEventType() override;
            Event::Key getKeyPressed() const override;
            size_t getScreenWidth() const override;
            size_t getScreenHeight() const override;

            void setScene(Scene scene) override;
            Scene getScene() const override;

            void setMainMenuOptions(const std::map<std::string, std::function<void()>> &mainMenu) override;
            void setPauseMenuOptions(const std::map<std::string, std::function<void()>> &pauseMenu) override;
            void setList(const std::vector<std::string> &list) override;
            void setGetInputMessage(const std::string &message) override;
            void setEndGameMessage(const std::string &message) override;
            void updateGameInfo(const std::vector<std::vector<char>> &gameMap) override;
            const std::string &getInput() const override;

            void setSprites(const std::map<char, std::string> &sprites) override;
            void setBackgroundColors(const std::map<char, Color> &sprites) override;
            void setFont(const std::string &font) override;

            void setGameStatsFormatString(const std::string &info) override;
            void setHowToPlayFormatString(const std::string &info) override;
        
        
        protected:
        
        
        private:
            std::unique_ptr<sf::RenderWindow> _window;
            std::string _test; // TO DELETE
    };

};

#endif /* !SFMLGRAPHICAL_HPP */
