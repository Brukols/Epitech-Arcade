/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Event
*/

#include "SceneMenu.hpp"
#include "Utility.hpp"

void arc::SceneMenu::resetButtonsListGames()
{
    std::for_each(_buttonsListGames.begin(), _buttonsListGames.end(), [](Button &button) {
        button.resetSelect();
    });
}

void arc::SceneMenu::resetButtonsListLibraries()
{
    std::for_each(_buttonsListLibraries.begin(), _buttonsListLibraries.end(), [](Button &button) {
        button.resetSelect();
    });
}

void arc::SceneMenu::buttonsEvent(sf::RenderWindow &window, sf::Event &event)
{
    if (event.type != sf::Event::MouseButtonReleased)
        return;
    std::for_each(_buttons.begin(), _buttons.end(), [&window](Button &button) {
        if (button.isMouseHover(sf::Mouse::getPosition())) {
            button.clickButton();
        }
    });

    std::for_each(_buttonsListGames.begin(), _buttonsListGames.end(), [this, &window](Button &button) {
        if (button.isMouseHover(sf::Mouse::getPosition())) {
            resetButtonsListGames();
            button.toggleSelect();
        }
    });
    std::for_each(_buttonsListLibraries.begin(), _buttonsListLibraries.end(), [this, &window](Button &button) {
        if (button.isMouseHover(sf::Mouse::getPosition())) {
            resetButtonsListLibraries();
            button.toggleSelect();
        }
    });
}

void arc::SceneMenu::event(sf::RenderWindow &window, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
{
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _actualEventType = arc::Event::QUIT;
            window.close();
            _actualEventType = arc::Event::QUIT;
            return;
        }
        if (event.type == sf::Event::KeyPressed) {
            _actualEventType = arc::Event::KEY_PRESSED;
            _actualKeyPress = Utility::getKey(event);
            if (_actualKeyPress != arc::Event::Key::NONE)
                return;
        }
        if (event.type == sf::Event::KeyReleased) {
            _actualEventType = arc::Event::KEY_RELEASED;
            _actualKeyPress = Utility::getKey(event);
            if (_actualKeyPress != arc::Event::Key::NONE)
                return;
        }
        buttonsEvent(window, event);
    }
    _actualEventType = arc::Event::Type::NO_EVENT;
    _actualKeyPress = arc::Event::Key::NONE;
}