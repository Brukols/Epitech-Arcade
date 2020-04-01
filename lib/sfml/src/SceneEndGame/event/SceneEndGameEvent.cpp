/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameEvent
*/

#include "sfml/SceneEndGame.hpp"
#include "sfml/Utility.hpp"

void arc::SceneEndGame::eventRestart()
{
    _eventRestart();
}

void arc::SceneEndGame::eventMenu()
{
    _eventMenu();
}

void arc::SceneEndGame::eventButtons(const sf::Event &event, sf::RenderWindow &window)
{
    if (event.type != sf::Event::MouseButtonReleased)
        return;
    std::for_each(_buttons.begin(), _buttons.end(), [this, &window](std::pair<Button, void (SceneEndGame::*)()> &button) {
        if (button.first.isMouseHover(sf::Mouse::getPosition(window)))
            (this->*button.second)();
    });
}

void arc::SceneEndGame::event(sf::RenderWindow &window, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
{
    sf::Event event;

    if (_exit == true) {
        _actualEventType = arc::Event::Type::QUIT;
        return;
    }
    _actualEventType = arc::Event::Type::NO_EVENT;
    _actualKeyPress = arc::Event::Key::NONE;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            _actualEventType = arc::Event::QUIT;
            window.close();
            return;
        }
        eventButtons(event, window);
        _listScores.event(event, window);
        if (event.type == sf::Event::KeyPressed) {
            _actualEventType = arc::Event::KEY_PRESSED;
            _actualKeyPress = Utility::getKey(event);
        }
        if (event.type == sf::Event::KeyReleased) {
            _actualEventType = arc::Event::KEY_RELEASED;
            _actualKeyPress = Utility::getKey(event);
        }
    }
}