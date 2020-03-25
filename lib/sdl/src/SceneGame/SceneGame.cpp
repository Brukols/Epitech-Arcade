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
    _scenePause = std::unique_ptr<ScenePause>(new ScenePause());
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
    _howToPlay.clear();
    int y = 620;
    std::for_each(info.begin(), info.end(), [this, &y](const std::pair<std::string, std::string> &pair) {
        Text *text = new Text();
        text->setFont(FONT, 16);
        text->setText(pair.first + " : " + pair.second);
        text->setPosition(20, y);
        text->setColor({255, 255, 255, 255});
        _howToPlay.push_back(std::unique_ptr<Text>(text));
        y += 40;
    });
}

void arc::SceneGame::setGameStats(const std::vector<std::pair<std::string, std::string>> &info)
{
    _stats.clear();
    int y = 270;
    std::for_each(info.begin(), info.end(), [this, &y](const std::pair<std::string, std::string> &pair) {
        Text *text = new Text();
        text->setFont(FONT, 16);
        text->setText(pair.first + " : " + pair.second);
        text->setPosition(20, y);
        text->setColor({255, 255, 255, 255});
        _stats.push_back(std::unique_ptr<Text>(text));
        y += 40;
    });
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
    _title = std::unique_ptr<Text>(new Text());

    _title->setFont(FONT, 40);
    _title->setText(game);
    _title->setColor({255, 255, 255, 255});
    _title->setPosition(350 / 2 - _title->getWidth() / 2, 30);
}

void arc::SceneGame::setGamePause(bool pause)
{
    _scenePause->setActivate(pause);
}