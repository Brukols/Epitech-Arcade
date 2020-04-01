/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScoresEvent
*/

#include "sfml/ListScores.hpp"

void arc::ListScores::event(const sf::Event &event, sf::RenderWindow &window)
{
    if (event.type != sf::Event::MouseWheelScrolled)
        return;

    sf::Vector2i pos = sf::Mouse::getPosition(window);

    if (pos.x > _rects[0].getPosition().x && pos.x < _rects[0].getPosition().x + _rects[0].getLocalBounds().width && pos.y > _rects[0].getPosition().y && pos.y < _rects[0].getPosition().y + _rects[0].getLocalBounds().height) {
        if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
            if (event.mouseWheelScroll.delta < 0)
                scrollUp();
            else
                scrollDown();
        }
    }
}

void arc::ListScores::scrollUp()
{
    if (_begin == 0)
        return;
    _begin--;
    std::for_each(_textScores.begin(), _textScores.end(), [this](std::pair<Text, Text> &pair) {
        pair.first.setPosition(sf::Vector2f(450 + 250 - pair.first.getText().getLocalBounds().width / 2, pair.first.getPosition().y + 50));
        pair.second.setPosition(sf::Vector2f(950 + 250 - pair.second.getText().getLocalBounds().width / 2, pair.second.getPosition().y + 50));
    });
}

void arc::ListScores::scrollDown()
{
    if (_textScores.size() <= 10)
        return;
    if (static_cast<long unsigned int>(_begin + 1) == _textScores.size() - 9)
        return;
    _begin++;
    std::for_each(_textScores.begin(), _textScores.end(), [this](std::pair<Text, Text> &pair) {
        pair.first.setPosition(sf::Vector2f(450 + 250 - pair.first.getText().getLocalBounds().width / 2, pair.first.getPosition().y - 50));
        pair.second.setPosition(sf::Vector2f(950 + 250 - pair.second.getText().getLocalBounds().width / 2, pair.second.getPosition().y - 50));
    });
}