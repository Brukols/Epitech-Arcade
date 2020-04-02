/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ScenesScoresEvent
*/

#include "sfml/SceneScores.hpp"

void arc::SceneScores::event(const sf::Event &event, sf::RenderWindow &window)
{
    _listScores.event(event, window);

    if (event.type != sf::Event::MouseButtonReleased)
        return;
    std::for_each(_images.begin(), _images.end(), [this, &window](std::pair<Image, void (SceneScores::*)()> &pair) {
        if (pair.first.isMouseHover(sf::Mouse::getPosition(window)))
            (this->*pair.second)();
    });
}

void arc::SceneScores::eventCloseImage()
{
    setActivate(false);
}