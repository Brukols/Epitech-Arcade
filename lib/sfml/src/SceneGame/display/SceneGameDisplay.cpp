/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** display
*/

#include "SceneGame.hpp"

void arc::SceneGame::displayGame(sf::RenderWindow &window)
{
    std::for_each(_gameMap.begin(), _gameMap.end(), [this, &window](std::shared_ptr<Entity> entity) {
        if (!entity.get()->spritePath.empty()) {
            sf::Sprite sprite;
            sprite.setTexture(_textureMap[entity.get()->spritePath]);
            sprite.setPosition(sf::Vector2f(entity.get()->x, entity.get()->y));
            window.draw(sprite);
        } else {
            _cell.setPosition(sf::Vector2f(entity.get()->x, entity.get()->y));
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