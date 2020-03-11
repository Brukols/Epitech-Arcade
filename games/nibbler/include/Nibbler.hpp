/*
** EPITECH PROJECT, 2019
** Arcade - Nibbler
** File description:
** Header Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "IGame.hpp"

using namespace arc;

namespace arc {
    class Nibbler : public IGame {
        public:
            Nibbler();
            ~Nibbler();

            size_t getMapHeight() const;
            size_t getMapWidth() const;
            const std::string &getFont() const;
            const std::string &getMusic() const;
            const std::string &getSound() const;
            const std::string &getScore();

            const std::map<char, std::pair<std::string, Color>> &getVisualAssets() const;
            const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &getControls() const;

            const std::vector<std::shared_ptr<Entity>> &getEntities() const;

            const std::vector<std::pair<std::string, std::string>> &getGameControlsFormatString() const;
            const std::vector<std::string> &getGameStatsFormatString() const;

            void restart();
            void updateGame();

            bool isGameOver() const;
        protected:

            size_t _height;
            size_t _width;
            std::string _font;
            std::string _music;
            std::string _sound;
            std::string _strScore;
            int _score;

            std::map<char, std::pair<std::string, Color>> _visualAssets;
            std::map<std::pair<Event::Type, Event::Key>, std::function<void()>> _controls;

            std::vector<std::shared_ptr<Entity>> _entities;
            std::vector<std::shared_ptr<Entity>> _snake;
            std::vector<std::shared_ptr<Entity>> _apple;

            std::vector <std::pair<std::string, std::string>> _gameControls;
            std::vector<std::string> _gameStats;
        private:
            //InitNibbler
            void initNibbler();
            void initVisualAssets();
            void initControls();
            void initEntities();
            void initApple();
            bool isOnSnake(float x, float y);
            void initSnake();
            void initGameControls();
            void initGameStats();

            bool doYouEat();
            void moveSnake();
    };

}

#endif // NIBBLER_HPP_