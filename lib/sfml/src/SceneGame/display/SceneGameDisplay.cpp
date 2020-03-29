/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** display
*/

#include "sfml/SceneGame.hpp"
#include <iostream>
void arc::SceneGame::displayGame(sf::RenderWindow &window)
{
    std::for_each(_gameMap.begin(), _gameMap.end(), [this, &window](std::shared_ptr<Entity> entity) {
        if (!entity.get()->spritePath.empty()) {
            sf::Sprite sprite;
            if (!_textureMap.count(entity.get()->spritePath)) {
                if (!_textureMap[entity.get()->spritePath].loadFromFile(entity.get()->spritePath)) {
                    _errorMessages.push_back(ErrorMessage("Unable to load this sprite : " + entity.get()->spritePath, [this]() {
                        _errorMessages.clear();
                        _eventFunctionBackToMenu();
                    }, _font));
                    return;
                }
            }
            sprite.setTexture(_textureMap[entity.get()->spritePath]);
            sprite.setScale(_cell.getSize().x / sprite.getLocalBounds().width, _cell.getSize().y / sprite.getLocalBounds().height);
            sprite.setOrigin(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f);
            if (entity->orientation == arc::Orientation::DOWN) {
                sprite.setRotation(180);
            } else if (entity->orientation == arc::Orientation::RIGHT) {
                sprite.setRotation(90);
            } else if (entity->orientation == arc::Orientation::LEFT) {
                sprite.setRotation(270);
            }
            sprite.setPosition(sf::Vector2f((entity.get()->x + 0.5) * _cell.getSize().x + 100, (entity.get()->y + 0.5) * _cell.getSize().y + 100));
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
    if (_exit == true) {
        return;
    }
    std::for_each(_rects.begin(), _rects.end(), [this, &window](sf::RectangleShape &rect) {
        window.draw(rect);
    });

    std::for_each(_buttons.begin(), _buttons.end(), [this, &window](std::pair<std::unique_ptr<Button>, void (SceneGame::*)()> &button) {
        button.first->displayButton(window);
    });

    std::for_each(_stats.begin(), _stats.end(), [&window](Text &text) {
        text.display(window);
    });

    std::for_each(_howToPlay.begin(), _howToPlay.end(), [&window](Text &text) {
        text.display(window);
    });

    std::for_each(_texts.begin(), _texts.end(), [&window](Text &text) {
        text.display(window);
    });

    displayGame(window);

    if (_scenePause->isActivate()) {
        _scenePause->display(window);
    }

    if (_errorMessages.size() != 0)
        _errorMessages[0].display(window);
}