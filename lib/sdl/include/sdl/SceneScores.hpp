/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneScores
*/

#ifndef SCENESCORES_HPP_
#define SCENESCORES_HPP_

#include "Rectangle.hpp"
#include <vector>
#include <memory>
#include "sdl/ListScores.hpp"

namespace arc
{
    class SceneScores {
        public:
            SceneScores();
            ~SceneScores();

            void init();

            void display(SDL_Renderer *window);
            bool isActivate() const;
            void setActivate(bool activate);
            void setScores(const std::vector<std::pair<std::string, std::string>> &scores);

            void event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event);

            void changeColor();

        private:
            void initRects();

        private:
            std::vector<std::unique_ptr<Rectangle>> _rects;
            bool _activate = false;

            std::unique_ptr<ListScores> _listScores;
    };
} // namespace arc

#endif /* !SCENESCORES_HPP_ */
