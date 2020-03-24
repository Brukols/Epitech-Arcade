/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGame
*/

#include "sdl/SceneGame.hpp"
#include "Utils.hpp"

arc::SceneGame::SceneGame()
{
}

arc::SceneGame::~SceneGame()
{
}

void arc::SceneGame::setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls)
{
    _controls = controls;
}

void arc::SceneGame::setFunctionMenu(const std::function<void()> &function)
{
    _eventMenu = function;
}

void arc::SceneGame::setFunctionTogglePause(const std::function<void()> &function)
{
    _eventPause = function;
}

void arc::SceneGame::setHowToPlay(const std::vector<std::pair<std::string, std::string>> &info)
{
    (void)info;
}

void arc::SceneGame::setGameStats(const std::vector<std::pair<std::string, std::string>> &info)
{
    (void)info;
}

void arc::SceneGame::updateGameInfo(const std::vector<std::shared_ptr<Entity>> &gameMap)
{
    _gameMap = gameMap;
}

void arc::SceneGame::setMapSize(size_t height, size_t width)
{
    _cell = std::unique_ptr<Rectangle>(new Rectangle());

    _cell.get()->setPosition(0, 0);
    _cell.get()->setColor({0, 0, 0, 255});
    _cell.get()->setSize(1200 / width, 900 / height);
}

void arc::SceneGame::setGameTitle(const std::string &game)
{
    (void)game;
}