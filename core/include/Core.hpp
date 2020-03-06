/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Core
*/

#ifndef CORE_HPP
#define CORE_HPP

#include <memory>
#include "IGame.hpp"
#include "IGraphical.hpp"

namespace arc {
    class Core {
        public:
            Core(const std::string &libname);
            ~Core();

            void playArcade();

        private:
            void initGraphs() noexcept;
            void initGames() noexcept;

            void changeGame(const std::string &name);
            void changeGraphical(const std::string &name);
            const std::string &nextGame();

        private:
            std::unique_ptr<IGame> _game;
            std::unique_ptr<IGraphical> _graph;
            std::map<std::string, bool> _graphs;
            std::map<std::string, bool> _games;
    };
}

#endif /* !CORE_HPP */
