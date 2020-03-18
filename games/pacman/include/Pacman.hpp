/*
** EPITECH PROJECT, 2019
** Arcade - Pacman
** File description:
** Header Pacman
*/

#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "IGame.hpp"

#include <ctime>
#include <chrono>

using namespace arc;


namespace arc {
    class Pacman : public IGame {
        public:
            Pacman();
            ~Pacman();

            size_t getMapHeight() const override;
            size_t getMapWidth() const override;
            const std::string &getFont() const override;
            const std::string &getMusic() const override;
            const std::string &getSound() const override;
            const std::string &getScore() override;

            const std::map<char, std::pair<std::string, Color>> &getVisualAssets() const override;
            const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &getControls() const override;

            const std::vector<std::shared_ptr<Entity>> &getEntities() const override;

            const std::vector<std::pair<std::string, std::string>> &getGameControlsFormatString() const override;
            const std::vector<std::string> &getGameStatsFormatString() const override;

            void restart() override;
            void updateGame() override;

            bool isGameOver() const override;
            const std::string &getTitle() const override;
        protected:
            std::chrono::time_point<std::chrono::system_clock> _start;
            std::chrono::time_point<std::chrono::system_clock> _end;
            // int _elapsedMilliseconds;

            size_t _height;
            size_t _width;
            std::string _font;
            std::string _music;
            std::string _sound;
            std::string _strScore;
            std::string _title;
            int _score;

            std::map<char, std::pair<std::string, Color>> _visualAssets;
            std::map<std::pair<Event::Type, Event::Key>, std::function<void()>> _controls;

            std::vector<std::shared_ptr<Entity>> _entities;
            std::vector<std::shared_ptr<Entity>> _pacman;
            // std::vector<std::shared_ptr<Entity>> _snake;
            // std::vector<std::shared_ptr<Entity>> _apple;

            std::vector <std::pair<std::string, std::string>> _gameControls;
            std::vector<std::string> _gameStats;
        private:
            // InitPacman
            void initPacmanGame();
            void initVisualAssets();
            void initControls();
            void initEntities();
            // void initFruits();
            // bool isOnSnake(float x, float y);
            void initPacman();
            void initGameControls();
            void initGameStats();

            bool doYouEat();
            void movePacman();
            //void updateOrientationSnake();
    };
}

#endif // NIBBLER_HPP_