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

            void setLib(IGraphical *lib);
            void setGame(IGame *game);

            void playArcade();

        protected:
        private:
            std::unique_ptr<IGame> _game;
            std::unique_ptr<IGraphical> _lib;
    };
}

#endif /* !CORE_HPP */
