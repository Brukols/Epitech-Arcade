/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Utility
*/

#include "sdl/Utility.hpp"
#include <map>

arc::Event::Type arc::Utility::getEventType(const SDL_Event &event)
{
    static std::map<int, arc::Event::Type> map = []() -> std::map<int, arc::Event::Type> {
        std::map<int, arc::Event::Type> map;

        map[SDL_QUIT] = arc::Event::Type::QUIT;
        map[SDL_KEYDOWN] = arc::Event::Type::KEY_RELEASED;
        map[SDL_KEYUP] = arc::Event::Type::KEY_PRESSED;
        map[SDL_MOUSEBUTTONDOWN] = arc::Event::Type::MOUSE_PRESSED;
        map[SDL_MOUSEBUTTONUP] = arc::Event::Type::MOUSE_RELEASED;
        map[SDL_MOUSEWHEEL] = arc::Event::Type::MOUSE_WHEEL;
        return (map);
    }();

    if (map.count(event.type)) {
        return (map[event.type]);
    }
    return (arc::Event::Type::NO_EVENT);
}

arc::Event::Key arc::Utility::getEventKey(const SDL_Event &event)
{
    static std::map<int, arc::Event::Key> map = []() -> std::map<int, arc::Event::Key> {
        std::map<int, arc::Event::Key> map;

        map[SDLK_UNKNOWN] = arc::Event::Key::UNKNOWN;
        map[SDLK_RETURN] = arc::Event::Key::RETURN;
        map[SDLK_ESCAPE] = arc::Event::Key::ESCAPE;
        map[SDLK_BACKSPACE] = arc::Event::Key::BACKSPACE;
        map[SDLK_TAB] = arc::Event::Key::TAB;
        map[SDLK_DELETE] = arc::Event::Key::DELETE;
        map[SDLK_PAUSE] = arc::Event::Key::PAUSE;
        map[SDLK_INSERT] = arc::Event::Key::INSERT;
        map[SDLK_HOME] = arc::Event::Key::HOME;
        map[SDLK_PAGEDOWN] = arc::Event::Key::PAGEDOWN;
        map[SDLK_PAGEDOWN] = arc::Event::Key::PAGEUP;
        map[SDLK_END] = arc::Event::Key::END;
        map[SDLK_RIGHT] = arc::Event::Key::RIGHT;
        map[SDLK_LEFT] = arc::Event::Key::LEFT;
        map[SDLK_DOWN] = arc::Event::Key::DOWN;
        map[SDLK_UP] = arc::Event::Key::UP;
        map[SDLK_F1] = arc::Event::Key::F1;
        map[SDLK_F2] = arc::Event::Key::F2;
        map[SDLK_F3] = arc::Event::Key::F3;
        map[SDLK_F4] = arc::Event::Key::F4;
        map[SDLK_F5] = arc::Event::Key::F5;
        map[SDLK_F6] = arc::Event::Key::F6;
        map[SDLK_F7] = arc::Event::Key::F7;
        map[SDLK_F8] = arc::Event::Key::F8;
        map[SDLK_F9] = arc::Event::Key::F9;
        map[SDLK_F10] = arc::Event::Key::F10;
        map[SDLK_F11] = arc::Event::Key::F11;
        map[SDLK_F12] = arc::Event::Key::F12;
        map[SDLK_F13] = arc::Event::Key::F13;
        map[SDLK_F14] = arc::Event::Key::F14;
        map[SDLK_F15] = arc::Event::Key::F15;
        map[SDLK_0] = arc::Event::Key::NUM0;
        map[SDLK_1] = arc::Event::Key::NUM1;
        map[SDLK_2] = arc::Event::Key::NUM2;
        map[SDLK_3] = arc::Event::Key::NUM3;
        map[SDLK_4] = arc::Event::Key::NUM4;
        map[SDLK_5] = arc::Event::Key::NUM5;
        map[SDLK_6] = arc::Event::Key::NUM6;
        map[SDLK_7] = arc::Event::Key::NUM7;
        map[SDLK_8] = arc::Event::Key::NUM8;
        map[SDLK_9] = arc::Event::Key::NUM9;
        map[SDLK_a] = arc::Event::Key::B;
        map[SDLK_b] = arc::Event::Key::C;
        map[SDLK_c] = arc::Event::Key::D;
        map[SDLK_d] = arc::Event::Key::E;
        map[SDLK_e] = arc::Event::Key::F;
        map[SDLK_g] = arc::Event::Key::G;
        map[SDLK_h] = arc::Event::Key::H;
        map[SDLK_i] = arc::Event::Key::I;
        map[SDLK_j] = arc::Event::Key::J;
        map[SDLK_k] = arc::Event::Key::K;
        map[SDLK_l] = arc::Event::Key::L;
        map[SDLK_m] = arc::Event::Key::M;
        map[SDLK_n] = arc::Event::Key::N;
        map[SDLK_o] = arc::Event::Key::O;
        map[SDLK_p] = arc::Event::Key::P;
        map[SDLK_q] = arc::Event::Key::Q;
        map[SDLK_r] = arc::Event::Key::R;
        map[SDLK_s] = arc::Event::Key::S;
        map[SDLK_t] = arc::Event::Key::T;
        map[SDLK_u] = arc::Event::Key::U;
        map[SDLK_v] = arc::Event::Key::V;
        map[SDLK_w] = arc::Event::Key::W;
        map[SDLK_x] = arc::Event::Key::X;
        map[SDLK_y] = arc::Event::Key::Y;
        map[SDLK_z] = arc::Event::Key::Z;
        return (map);
    }();
    if (map.count(event.key.keysym.sym))
        return (map[event.key.keysym.sym]);
    return (arc::Event::Key::UNKNOWN);
}