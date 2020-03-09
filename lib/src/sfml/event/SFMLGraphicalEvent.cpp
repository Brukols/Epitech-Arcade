/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SFMLGraphicalEvent
*/

#include "SFMLGraphical.hpp"
#include "Utils.hpp"
#include <iostream>

bool arc::SFMLGraphical::clickAButton(const sf::Vector2i &pos)
{
    bool click = false;

    std::for_each(_buttons.begin(), _buttons.end(), [this, pos, &click](SFMLButton &button) {
        if (click == true)
            return;
        if (button.isMouseHover(pos)) {
            button.clickButton();
            click = true;
        }
    });
    return (click);
}

arc::Event::Type arc::SFMLGraphical::getEventType()
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _actualEventType = arc::Event::QUIT;
            _window.close();
            return (arc::Event::QUIT);
        }
        if (event.type == sf::Event::KeyPressed) {
            _actualEventType = arc::Event::KEY_PRESSED;
            _actualKeyPress = getKey(event);
            if (_actualKeyPress != arc::Event::Key::NONE)
                return (_actualEventType);
        }
        if (event.type == sf::Event::KeyReleased) {
            _actualEventType = arc::Event::KEY_RELEASED;
            _actualKeyPress = getKey(event);
            if (_actualKeyPress != arc::Event::Key::NONE)
                return (_actualEventType);
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            if (clickAButton(sf::Mouse::getPosition()))
                return (_actualEventType);
        }
    }
    _actualEventType = arc::Event::Type::NO_EVENT;
    _actualKeyPress = arc::Event::Key::NONE;
    return (arc::Event::NO_EVENT);
}

arc::Event::Key arc::SFMLGraphical::getKeyPressed() const
{
    return (_actualKeyPress);
}


const sf::Keyboard::Key sfmlKeys[] = {
    sf::Keyboard::Key::Unknown,
    sf::Keyboard::Key::A,
    sf::Keyboard::Key::B,
    sf::Keyboard::Key::C,
    sf::Keyboard::Key::D,
    sf::Keyboard::Key::E,
    sf::Keyboard::Key::F,
    sf::Keyboard::Key::G,
    sf::Keyboard::Key::H,
    sf::Keyboard::Key::I,
    sf::Keyboard::Key::J,
    sf::Keyboard::Key::K,
    sf::Keyboard::Key::L,
    sf::Keyboard::Key::M,
    sf::Keyboard::Key::N,
    sf::Keyboard::Key::O,
    sf::Keyboard::Key::P,
    sf::Keyboard::Key::Q,
    sf::Keyboard::Key::R,
    sf::Keyboard::Key::S,
    sf::Keyboard::Key::T,
    sf::Keyboard::Key::U,
    sf::Keyboard::Key::V,
    sf::Keyboard::Key::W,
    sf::Keyboard::Key::X,
    sf::Keyboard::Key::Y,
    sf::Keyboard::Key::Z,
    sf::Keyboard::Key::Return,
    sf::Keyboard::Key::Pause,
    sf::Keyboard::Key::BackSpace,
    sf::Keyboard::Key::Tab,
    sf::Keyboard::Key::Escape,
    sf::Keyboard::Key::Delete,
    sf::Keyboard::Key::Up,
    sf::Keyboard::Key::Down,
    sf::Keyboard::Key::Left,
    sf::Keyboard::Key::Right,
    sf::Keyboard::Key::Insert,
    sf::Keyboard::Key::Home,
    sf::Keyboard::Key::End,
    sf::Keyboard::Key::PageUp,
    sf::Keyboard::Key::PageDown,
    sf::Keyboard::Key::F1,
    sf::Keyboard::Key::F2,
    sf::Keyboard::Key::F3,
    sf::Keyboard::Key::F4,
    sf::Keyboard::Key::F5,
    sf::Keyboard::Key::F6,
    sf::Keyboard::Key::F7,
    sf::Keyboard::Key::F8,
    sf::Keyboard::Key::F9,
    sf::Keyboard::Key::F10,
    sf::Keyboard::Key::F11,
    sf::Keyboard::Key::F12,
    sf::Keyboard::Key::F13,
    sf::Keyboard::Key::F14,
    sf::Keyboard::Key::F15,
};

const arc::Event::Key arcKeys[] = {
    arc::Event::Key::UNKNOWN,
    arc::Event::Key::A,
    arc::Event::Key::B,
    arc::Event::Key::C,
    arc::Event::Key::D,
    arc::Event::Key::E,
    arc::Event::Key::F,
    arc::Event::Key::G,
    arc::Event::Key::H,
    arc::Event::Key::I,
    arc::Event::Key::J,
    arc::Event::Key::K,
    arc::Event::Key::L,
    arc::Event::Key::M,
    arc::Event::Key::N,
    arc::Event::Key::O,
    arc::Event::Key::P,
    arc::Event::Key::Q,
    arc::Event::Key::R,
    arc::Event::Key::S,
    arc::Event::Key::T,
    arc::Event::Key::U,
    arc::Event::Key::V,
    arc::Event::Key::W,
    arc::Event::Key::X,
    arc::Event::Key::Y,
    arc::Event::Key::Z,
    arc::Event::Key::RETURN,
    arc::Event::Key::PAUSE,
    arc::Event::Key::BACKSPACE,
    arc::Event::Key::TAB,
    arc::Event::Key::ESCAPE,
    arc::Event::Key::DELETE,
    arc::Event::Key::UP,
    arc::Event::Key::DOWN,
    arc::Event::Key::LEFT,
    arc::Event::Key::RIGHT,
    arc::Event::Key::INSERT,
    arc::Event::Key::HOME,
    arc::Event::Key::END,
    arc::Event::Key::PAGEUP,
    arc::Event::Key::PAGEDOWN,
    arc::Event::Key::F1,
    arc::Event::Key::F2,
    arc::Event::Key::F3,
    arc::Event::Key::F4,
    arc::Event::Key::F5,
    arc::Event::Key::F6,
    arc::Event::Key::F7,
    arc::Event::Key::F8,
    arc::Event::Key::F9,
    arc::Event::Key::F10,
    arc::Event::Key::F11,
    arc::Event::Key::F12,
    arc::Event::Key::F13,
    arc::Event::Key::F14,
    arc::Event::Key::F15,
};

arc::Event::Key arc::SFMLGraphical::getKey(sf::Event event) const
{
    for (size_t i = 0; i < 57; i++) {
        if (event.key.code == sfmlKeys[i])
            return (arcKeys[i]);
    }
    return (arc::Event::Key::NONE);
}