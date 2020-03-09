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
#include "DLLoader.hpp"

namespace arc {
    class Core {
        private:
            enum Direction {
                NEXT,
                PREV,
            };

        public:
            Core(const std::string &libname);
            ~Core();

            void playArcade();

        private:
            void initGraphs();
            void initGames();

            void changeGame(Direction direction);
            void changeGraphical(Direction direction);
            void setGame(const std::string &libname);
            void setGraphical(const std::string &libname);

            const std::vector<std::string> getNamesSharedLib(const std::map<std::string, bool> &map);
            const std::string getLibName(const std::string &path);

        private:
            std::unique_ptr<IGame> _game;
            std::unique_ptr<DLLoader<IGraphical>> _loaderGraph;
            std::unique_ptr<DLLoader<IGame>> _loaderGame;
            std::unique_ptr<IGraphical> _graph;
            std::map<std::string, bool> _graphs;
            std::map<std::string, bool> _games;
    };
}

#endif /* !CORE_HPP */
