/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameDisplay
*/

#include "sdl/SceneGame.hpp"
#include "sdl/Sprite.hpp"
#include <iostream>

void arc::SceneGame::display(SDL_Renderer *window)
{
    std::for_each(_rects.begin(), _rects.end(), [&window](std::unique_ptr<Rectangle> &rect) {
        rect.get()->display(window);
    });

    std::for_each(_buttons.begin(), _buttons.end(), [&window](std::pair<std::unique_ptr<IButton>, void (SceneGame::*)()> &button) {
        button.first->display(window);
    });

    std::for_each(_gameMap.begin(), _gameMap.end(), [&window, this](std::shared_ptr<Entity> &entity) {
        if (!entity->spritePath.empty()) {
            if (!_textureMap.count(entity->spritePath)) {
                _textureMap[entity->spritePath] = std::unique_ptr<Sprite>(new Sprite(entity->spritePath));
            }
            if (entity->orientation == arc::Orientation::DOWN) {
                _textureMap[entity->spritePath]->setRotation(180);
            } else if (entity->orientation == arc::Orientation::RIGHT) {
                _textureMap[entity->spritePath]->setRotation(90);
            } else if (entity->orientation == arc::Orientation::LEFT) {
                _textureMap[entity->spritePath]->setRotation(270);
            } else {
                _textureMap[entity->spritePath]->setRotation(0);
            }
            _textureMap[entity->spritePath]->setScale(_cell->getWidth(), _cell->getHeight());
            _textureMap[entity->spritePath]->setPosition(entity->x * _cell->getWidth() + 500, entity->y * _cell->getHeight() + 100);
            _textureMap[entity->spritePath]->display(window);
        } else {
            _cell.get()->setPosition(entity->x * _cell.get()->getWidth() + 500, entity->y * _cell.get()->getHeight() + 100);
            _cell.get()->setColor({entity->backgroundColor.r, entity->backgroundColor.g, entity->backgroundColor.b, entity->backgroundColor.a});
            _cell.get()->display(window);
        }
    });

    std::for_each(_howToPlay.begin(), _howToPlay.end(), [&window](std::unique_ptr<Text> &text) {
        text->display(window);
    });

    std::for_each(_stats.begin(), _stats.end(), [&window](std::unique_ptr<Text> &text) {
        text->display(window);
    });

    std::for_each(_texts.begin(), _texts.end(), [&window](std::unique_ptr<Text> &text) {
        text->display(window);
    });

    _title->display(window);

    if (_scenePause->isActivate()) {
        _scenePause->display(window);
    }

    SDL_RenderPresent(window);
}