/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneGame
*/

#include "sfml/SceneGame.hpp"

void arc::SceneGame::eventFunctionBackToMenu(std::function<void()> event)
{
    _eventFunctionBackToMenu = event;
}

void arc::SceneGame::setMapSize(size_t height, size_t width)
{
    _mapHeight = height;
    _mapWidth = width;
    sf::RectangleShape rect(sf::Vector2f(static_cast<float>(1200 / width), static_cast<float>(900 / height)));
    _cell = rect;
}

void arc::SceneGame::updateGameInfo(const std::vector<std::shared_ptr<Entity>> &gameMap)
{
    _gameMap = gameMap;
}

void arc::SceneGame::setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls)
{
    _controls = controls;
}