/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneGame
*/

#ifndef SCENEGAME_HPP
#define SCENEGAME_HPP

#include "IScene.hpp"
#include <vector>
#include "Button.hpp"
#include "Text.hpp"
#include <memory>

namespace arc
{
    class SceneGame : public IScene {
        public:
            SceneGame();
            ~SceneGame();

            void init() override;
            void display(sf::RenderWindow &window) override;
            void event(sf::RenderWindow &window, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress) override;

            void setFont(const sf::Font &font);

            void initButtons();
            void initTexts();
            void initRects();

            void eventFunctionBackToMenu(std::function<void()> event);

            void setMapSize(size_t height, size_t width);
            void updateGameInfo(const std::vector<std::shared_ptr<Entity>> &gameMap);

            void setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls);

        private:
            void eventButtons(sf::RenderWindow &window, sf::Event &event);

            void displayGame(sf::RenderWindow &window);

        private:
            std::vector<Button> _buttons;
            std::vector<Text> _texts;
            std::vector<sf::RectangleShape> _rects;
            sf::Font _font;

            std::function<void()> _eventFunctionBackToMenu;

            size_t _mapWidth;
            size_t _mapHeight;

            sf::RectangleShape _cell;
            std::map<std::string, sf::Texture> _textureMap;
            std::vector<std::shared_ptr<Entity>> _gameMap;

            std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> _controls;
    };
}

#endif /* !SCENEGAME_HPP */