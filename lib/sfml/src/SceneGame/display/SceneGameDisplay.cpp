/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** display
*/

#include "SceneGame.hpp"
#include <iostream>
void arc::SceneGame::displayGame(sf::RenderWindow &window)
{
    std::for_each(_gameMap.begin(), _gameMap.end(), [this, &window](std::shared_ptr<Entity> entity) {
        if (!entity.get()->spritePath.empty()) {
            sf::Sprite sprite;
            if (!_textureMap.count(entity.get()->spritePath)) {
                _textureMap[entity.get()->spritePath].loadFromFile(entity.get()->spritePath);
            }
            sprite.setTexture(_textureMap[entity.get()->spritePath]);
            sprite.setScale(_cell.getSize().x / sprite.getTextureRect().width, _cell.getSize().y / sprite.getTextureRect().height);
            sprite.setPosition(sf::Vector2f(entity.get()->x * _cell.getSize().x + 100, entity.get()->y * _cell.getSize().y + 100));
            window.draw(sprite);
        } else {
            _cell.setPosition(sf::Vector2f(entity.get()->x * _cell.getSize().x + 100, entity.get()->y * _cell.getSize().y + 100));
            _cell.setFillColor(sf::Color(entity.get()->backgroundColor.r, entity.get()->backgroundColor.g, entity.get()->backgroundColor.b, entity.get()->backgroundColor.a));
            window.draw(_cell);
        }
    });
}

void arc::SceneGame::display(sf::RenderWindow &window)
{
    std::for_each(_rects.begin(), _rects.end(), [this, &window](sf::RectangleShape &rect) {
        window.draw(rect);
    });

    std::for_each(_buttons.begin(), _buttons.end(), [this, &window](Button &button) {
        button.displayButton(window);
    });

    displayGame(window);
}