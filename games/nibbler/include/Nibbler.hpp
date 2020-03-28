/*
** EPITECH PROJECT, 2019
** Arcade - Nibbler
** File description:
** Header Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "IGame.hpp"

#include <ctime>
#include <chrono>
#include <cmath>

#define MOVE 0.2

using namespace arc;

namespace arc {
    class Nibbler : public IGame {
        public:
            Nibbler();
            ~Nibbler();

            size_t getMapHeight() const override;
            size_t getMapWidth() const override;
            const std::string &getMusic() const override;
            const std::string &getSound() const override;
            const std::string &getScore() override;

            const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &getControls() const override;

            const std::vector<std::shared_ptr<Entity>> &getEntities() const override;

            const std::vector<std::pair<std::string, std::string>> &getGameControls() const override;
            const std::vector<std::pair<std::string, std::string>> &getGameStats() const override;

            void restart() override;
            void updateGame() override;

            bool isGameOver() const override;
            const std::string &getTitle() const override;
        protected:
            std::chrono::time_point<std::chrono::system_clock> _start;
            std::chrono::time_point<std::chrono::system_clock> _end;
            int _elapsedMilliseconds;

            size_t _height;
            size_t _width;
            std::string _music;
            std::string _sound;
            std::string _strScore;
            std::string _title;
            int _score;

            std::map<std::pair<Event::Type, Event::Key>, std::function<void()>> _controls;

            std::vector<std::shared_ptr<Entity>> _entities;
            std::vector<std::shared_ptr<Entity>> _snake;
            std::vector<std::shared_ptr<Entity>> _apple;

            int _nbApple;

            std::vector <std::pair<std::string, std::string>> _gameControls;
            std::vector <std::pair<std::string, std::string>> _gameStats;
        private:
            //InitNibbler
            void initNibbler();
            void initControls();
            void initEntities();
            void initApple();
            void initSnake();
            void initGameControls();
            void initGameStats();

            bool doYouEat();
            void addBodySnake();
            void moveSnake();
            void updateOrientationSnake();
            bool isCollision() const;
            bool isOnSnake(float x, float y);
            bool isPossibleAdd(float x, float y);
            void addBodySnakeFirstPlace(std::shared_ptr<Entity> &o);
    };

}

#endif // NIBBLER_HPP_