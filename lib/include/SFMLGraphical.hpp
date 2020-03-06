/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLGRAPHICLA
*/

#ifndef SFMLGRAPHICAL_HPP
#define SFMLGRAPHICAL_HPP

#include "IGraphical.hpp"

namespace arc
{
 
    class SFMLGraphical : public IGraphical {

        public:
            SFMLGraphical();
            ~SFMLGraphical();

            void display();
            Event::Type getEventType() const override;
            Event::Key getKeyPressed() const override;
            size_t getScreenWidth() const override;
            size_t getScreenHeight() const  override;

            void setScene(Scene scene) const override;
            Scene getScene() const override;

            void setMainMenuOptions(const std::vector<std::string> &mainMenu) override;
            void setPauseMenuOptions(const std::vector<std::string> &pauseMenu) override;
            void setList(const std::vector<std::string> &list) override;
            void setGetInputMessage(const std::string &message) override;
            void setEndGameMessage(const std::string &message) override;
            void updateGameInfo(const std::vector<std::vector<char>> &gameMap) override;

            const std::string &getSceneChoice(Scene scene) const override;

            void setSprites(const std::map<char, std::string> &sprites) override;
            void setBackgroundColors(const std::map<char, Color> &sprites) override;
            void setFont(const std::string &font) override;

            void setGameStatsFormatString(const std::string &info) override;
            void setHowToPlayFormatString(const std::string &info) override;
        protected:
        private:
    };

};

#endif /* !SFMLGRAPHICAL_HPP */
