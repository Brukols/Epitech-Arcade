/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneScores
*/

#ifndef SCENESCORES_HPP_
#define SCENESCORES_HPP_

#include "IScene.hpp"
#include "Image.hpp"
#include "ListScores.hpp"

namespace arc
{
    class SceneScores {
        public:
            SceneScores();
            ~SceneScores();

            void init();
            void display(sf::RenderWindow &window);
            void event(const sf::Event &event, sf::RenderWindow &window);

            void setFont(const sf::Font &font);
            void setUsername(const std::string &username);
            void setScores(const std::vector<std::pair<std::string, std::string>> &scores);

            bool isActivate() const;
            void setActivate(bool activate);

        private:
            void initRects();
            void initImages();

            void eventCloseImage();

        private:
            ListScores _listScores;
            std::vector<std::pair<Image, void (SceneScores::*)()>> _images;
            std::vector<sf::RectangleShape> _rects;

            bool _activate = false;
    };
} // namespace arc

#endif /* !SCENESCORES_HPP_ */
