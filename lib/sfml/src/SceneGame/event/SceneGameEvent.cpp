/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Event
*/

#include "sfml/SceneGame.hpp"
#include "sfml/Utility.hpp"

void arc::SceneGame::eventErrorMessage(sf::Event &event)
{
    if (event.type != sf::Event::MouseButtonReleased)
        return;
    if (_errorMessages[0].isHoverButton(sf::Mouse::getPosition()))
        _errorMessages[0].clickButton();
}

void arc::SceneGame::event(sf::RenderWindow &window, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
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
        if (_errorMessages.size() != 0) {
            eventErrorMessage(event);
            return;
        }
        eventButtons(window, event);
        if (event.type == sf::Event::KeyPressed) {
            _actualEventType = arc::Event::KEY_PRESSED;
            _actualKeyPress = Utility::getKey(event);
            // if (_actualKeyPress != arc::Event::Key::NONE)
            //     return;
        }
        if (event.type == sf::Event::KeyReleased) {
            _actualEventType = arc::Event::KEY_RELEASED;
            _actualKeyPress = Utility::getKey(event);
            // if (_actualKeyPress != arc::Event::Key::NONE)
            //     return;
        }
        std::pair pair = std::pair<Event::Type, Event::Key>(_actualEventType, _actualKeyPress);
        if (_controls.count(pair)) {
            _controls[pair]();
            return;
        }
    }
}