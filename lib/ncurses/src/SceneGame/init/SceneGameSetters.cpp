/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameSetters
*/

#include "ncurses/SceneGame.hpp"
#include "ncurses/NcursesError.hpp"

void arc::SceneGame::setFunctionBackToMenu(const std::function<void()> &fct)
{
    _eventBackToMenu = fct;
}

void arc::SceneGame::setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls)
{
    _controls = controls;
}

void arc::SceneGame::setMapSize(size_t height, size_t width)
{
    if (height > 51 || width > 68)
        throw MapSizeError("Map size too big");
    _height = height;
    _width = width;
    _rect = Rectangle(1, 2, MAIN_COLOR_1, MAIN_COLOR_1);
    initMap();
}

void arc::SceneGame::updateGameInfo(const std::vector<std::shared_ptr<Entity>> &gameMap)
{
    _gameMap = gameMap;
}