/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameDisplay
*/

#include "ncurses/SceneGame.hpp"


void arc::SceneGame::display()
{
    if (_scenePause->isActivate()) {
        _scenePause->display();
        return;
    }
    std::for_each(_rects.begin(), _rects.end(), [this](Rectangle &rect) {
        rect.display();
    });

    std::for_each(_buttons.begin(), _buttons.end(), [this](std::pair<Button, void (SceneGame::*)()> &button) {
        button.first.display();
    });

    std::for_each(_gameMap.begin(), _gameMap.end(), [this](std::shared_ptr<Entity> entity) {
        _rect.setPosition(entity.get()->x * 2 + 6, entity.get()->y + 3);
        _rect.setColors(arc::BACKGROUND_COLOR, Utility::generateColor(entity.get()->backgroundColor));
        _rect.display();
    });

    std::for_each(_texts.begin(), _texts.end(), [](Text &text) {
        text.display();
    });

    std::for_each(_howToPlay.begin(), _howToPlay.end(), [](Text &text) {
        text.display();
    });

    std::for_each(_stats.begin(), _stats.end(), [](Text &text) {
        text.display();
    });
}