/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** Utility
*/

#include "Utility.hpp"

arc::Event::Key arc::Utility::getKey(sf::Event event)
{
    static std::unordered_map<sf::Keyboard::Key, arc::Event::Key> map = []() -> std::unordered_map<sf::Keyboard::Key, arc::Event::Key> {
        std::unordered_map<sf::Keyboard::Key, arc::Event::Key> map;

        map[sf::Keyboard::Key::Unknown] = arc::Event::Key::UNKNOWN;
        map[sf::Keyboard::Key::A] = arc::Event::Key::A;
        map[sf::Keyboard::Key::B] = arc::Event::Key::B;
        map[sf::Keyboard::Key::C] = arc::Event::Key::C;
        map[sf::Keyboard::Key::D] = arc::Event::Key::D;
        map[sf::Keyboard::Key::E] = arc::Event::Key::E;
        map[sf::Keyboard::Key::F] = arc::Event::Key::F;
        map[sf::Keyboard::Key::G] = arc::Event::Key::G;
        map[sf::Keyboard::Key::H] = arc::Event::Key::H;
        map[sf::Keyboard::Key::I] = arc::Event::Key::I;
        map[sf::Keyboard::Key::J] = arc::Event::Key::J;
        map[sf::Keyboard::Key::K] = arc::Event::Key::K;
        map[sf::Keyboard::Key::L] = arc::Event::Key::L;
        map[sf::Keyboard::Key::M] = arc::Event::Key::M;
        map[sf::Keyboard::Key::N] = arc::Event::Key::N;
        map[sf::Keyboard::Key::O] = arc::Event::Key::O;
        map[sf::Keyboard::Key::P] = arc::Event::Key::P;
        map[sf::Keyboard::Key::Q] = arc::Event::Key::Q;
        map[sf::Keyboard::Key::R] = arc::Event::Key::R;
        map[sf::Keyboard::Key::S] = arc::Event::Key::S;
        map[sf::Keyboard::Key::T] = arc::Event::Key::T;
        map[sf::Keyboard::Key::U] = arc::Event::Key::U;
        map[sf::Keyboard::Key::V] = arc::Event::Key::V;
        map[sf::Keyboard::Key::W] = arc::Event::Key::W;
        map[sf::Keyboard::Key::X] = arc::Event::Key::X;
        map[sf::Keyboard::Key::Y] = arc::Event::Key::Y;
        map[sf::Keyboard::Key::Z] = arc::Event::Key::Z;
        map[sf::Keyboard::Key::Return] = arc::Event::Key::RETURN;
        map[sf::Keyboard::Key::Pause] = arc::Event::Key::PAUSE;
        map[sf::Keyboard::Key::BackSpace] = arc::Event::Key::BACKSPACE;
        map[sf::Keyboard::Key::Tab] = arc::Event::Key::TAB;
        map[sf::Keyboard::Key::Escape] = arc::Event::Key::ESCAPE;
        map[sf::Keyboard::Key::Delete] = arc::Event::Key::DELETE;
        map[sf::Keyboard::Key::Up] = arc::Event::Key::UP;
        map[sf::Keyboard::Key::Down] = arc::Event::Key::DOWN;
        map[sf::Keyboard::Key::Left] = arc::Event::Key::LEFT;
        map[sf::Keyboard::Key::Right] = arc::Event::Key::RIGHT;
        map[sf::Keyboard::Key::Insert] = arc::Event::Key::INSERT;
        map[sf::Keyboard::Key::Home] = arc::Event::Key::HOME;
        map[sf::Keyboard::Key::End] = arc::Event::Key::END;
        map[sf::Keyboard::Key::PageUp] = arc::Event::Key::PAGEUP;
        map[sf::Keyboard::Key::PageDown] = arc::Event::Key::PAGEDOWN;
        map[sf::Keyboard::Key::F1] = arc::Event::Key::F1;
        map[sf::Keyboard::Key::F2] = arc::Event::Key::F2;
        map[sf::Keyboard::Key::F3] = arc::Event::Key::F3;
        map[sf::Keyboard::Key::F4] = arc::Event::Key::F4;
        map[sf::Keyboard::Key::F5] = arc::Event::Key::F5;
        map[sf::Keyboard::Key::F6] = arc::Event::Key::F6;
        map[sf::Keyboard::Key::F7] = arc::Event::Key::F7;
        map[sf::Keyboard::Key::F8] = arc::Event::Key::F8;
        map[sf::Keyboard::Key::F9] = arc::Event::Key::F9;
        map[sf::Keyboard::Key::F10] = arc::Event::Key::F10;
        map[sf::Keyboard::Key::F11] = arc::Event::Key::F11;
        map[sf::Keyboard::Key::F12] = arc::Event::Key::F12;
        map[sf::Keyboard::Key::F13] = arc::Event::Key::F13;
        map[sf::Keyboard::Key::F14] = arc::Event::Key::F14;
        map[sf::Keyboard::Key::F15] = arc::Event::Key::F15;
        return (map);
    }();

    if (map.count(event.key.code))
        return (map[event.key.code]);
    return (arc::Event::Key::NONE);
}