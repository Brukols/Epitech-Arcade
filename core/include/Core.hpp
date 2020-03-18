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

        public:
            Core(const std::string &libname);
            ~Core();

            void playArcade();

        private:
            void initGraphs();
            void initGames();

            void setGame(const std::string &libname);
            void setGraphical(const std::string &libname);

            const std::vector<std::string> getNamesSharedGraphs();
            const std::vector<std::string> getNamesSharedGames();
            const std::string getLibName(const std::string &path);

            void setNextGraphical();
            void setNextGame();
            void setPrevGraphical();
            void setPrevGame();

            void functionPlay();

        private:
            std::vector<std::pair<std::string, std::unique_ptr<DLLoader<IGraphical>>>> _graphs;
            std::vector<std::pair<std::string, std::unique_ptr<DLLoader<IGame>>>> _games;

            std::unique_ptr<IGame> _game;
            std::unique_ptr<IGraphical> _graph;
            
            int _indexGame = -1;
            int _indexGraph = -1;
    };
}

#endif /* !CORE_HPP */
