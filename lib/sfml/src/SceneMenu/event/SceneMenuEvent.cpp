/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Event
*/

#include "sfml/SceneMenu.hpp"
#include "sfml/Utility.hpp"

void arc::SceneMenu::eventHowToPlay()
{
    _sceneHowToPlay->setActivate(true);
}

void arc::SceneMenu::buttonsEvent(sf::RenderWindow &window, sf::Event &event)
{
    std::for_each(_lists.begin(), _lists.end(), [this, &event](List &list) {
        list.event(event);
    });

    if (event.type != sf::Event::MouseButtonReleased)
        return;
    std::for_each(_buttons.begin(), _buttons.end(), [this, &window](std::pair<Button, void (SceneMenu::*)()> &button) {
        if (button.first.isMouseHover(sf::Mouse::getPosition())) {
            (this->*button.second)();
        }
    });

    std::for_each(_buttonEnterUsername.begin(), _buttonEnterUsername.end(), [this, &window](std::pair<Button, void (SceneMenu::*)()> &button) {
        if (button.first.isMouseHover(sf::Mouse::getPosition())) {
            (this->*button.second)();
        }
    });
}

void arc::SceneMenu::inputEvent(sf::RenderWindow &window, sf::Event &event)
{
    (void)window;
    std::for_each(_inputs.begin(), _inputs.end(), [&event, this](Input &input) {
        if (input.isFocus()) {
            input.event(event);
            if (!input.isFocus()) {
                eventValidateUsername();
            }
        }
    });
}

bool arc::SceneMenu::inputIsFocus() const
{
    return (_inputs.end() == std::find_if(_inputs.begin(), _inputs.end(), [this](const Input &input) -> bool {
        if (input.isFocus())
            return (true);
        return (false);
    }) ? false : true);
}

void arc::SceneMenu::eventErrorMessage(sf::Event &event)
{
    if (event.type != sf::Event::MouseButtonReleased)
        return;
    if (_errorMessages[0].isHoverButton(sf::Mouse::getPosition()))
        _errorMessages[0].click();
}

void arc::SceneMenu::event(sf::RenderWindow &window, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
{
    sf::Event event;

    if (_exit == true) {
        _actualEventType = arc::Event::Type::QUIT;
        return;
    }
    _actualEventType = arc::Event::Type::NO_EVENT;
    _actualKeyPress = arc::Event::Key::NONE;
    if (_lists.size() > 1 && _lists[1].hasASelectButton()) {
        _buttons[0].first.setActivate(true);
        _buttons[2].first.setActivate(true);
    }
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            _actualEventType = arc::Event::QUIT;
            _actualKeyPress = arc::Event::ESCAPE;
            return;
        }
        if (_errorMessages.size() != 0) {
            eventErrorMessage(event);
            continue;
        }
        if (_sceneScores.isActivate()) {
            _sceneScores.event(event);
        } else if (_sceneHowToPlay->isActivate()) {
            _sceneHowToPlay->event(event);
        } else
            buttonsEvent(window, event);
        if (inputIsFocus()) {
            inputEvent(window, event);
            continue;
        }
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

void arc::SceneMenu::eventButtonExit()
{
    _eventExit();
}