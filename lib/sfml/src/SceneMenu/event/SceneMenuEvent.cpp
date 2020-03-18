/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Event
*/

#include "sfml/SceneMenu.hpp"
#include "sfml/Utility.hpp"

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

    std::for_each(_buttonEnterUsername.begin(), _buttonEnterUsername.end(), [&window](Button &button) {
        if (button.isMouseHover(sf::Mouse::getPosition())) {
            button.clickButton();
        }
    });

    std::for_each(_buttonsListGames.begin(), _buttonsListGames.end(), [this, &window](Button &button) {
        if (button.isMouseHover(sf::Mouse::getPosition())) {
            resetButtonsListGames();
            button.toggleSelect();
            if (button.isSelect()) {
                button.clickButton();
            }
        }
    });
    std::for_each(_buttonsListLibraries.begin(), _buttonsListLibraries.end(), [this, &window](Button &button) {
        if (button.isMouseHover(sf::Mouse::getPosition())) {
            resetButtonsListLibraries();
            button.toggleSelect();
        }
    });
}

static void enteredText(std::vector<arc::Input> &input, sf::Event &event)
{
    std::for_each(input.begin(), input.end(), [&event](arc::Input &input) {
        if (input.isFocus()) {
            input.addLetter(event);
        }
    });
}

void arc::SceneMenu::inputEvent(sf::RenderWindow &window, sf::Event &event)
{
    (void)window;
    if (event.type != sf::Event::TextEntered)
        return;
    if (event.text.unicode == 13) {
        _buttonEnterUsername[0].clickButton();
        return;
    }
    enteredText(_inputs, event);
}

bool arc::SceneMenu::inputIsFocus() const
{
    return (_inputs.end() == std::find_if(_inputs.begin(), _inputs.end(), [this](const Input &input) -> bool {
        if (input.isFocus())
            return (true);
        return (false);
    }) ? false : true);
}

void arc::SceneMenu::event(sf::RenderWindow &window, arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
{
    sf::Event event;

    _actualEventType = arc::Event::Type::NO_EVENT;
    _actualKeyPress = arc::Event::Key::NONE;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            _actualEventType = arc::Event::QUIT;
            window.close();
            return;
        }
        buttonsEvent(window, event);
        if (inputIsFocus()) {
            inputEvent(window, event);
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
    }
}