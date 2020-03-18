/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Utility
*/

#include "ncurses/Utility.hpp"
#include <streambuf>
#include <fstream>
#include <map>

void arc::Utility::display(const std::string &text, int x, int y, int noPair)
{
    attron(COLOR_PAIR(noPair));
    attron(A_BOLD);
    for (size_t i = 0; i < text.size(); y++, i++) {
        size_t tmp_x = x;
        for (; text[i] != '\n' && i < text.size(); i++, tmp_x++) {
            mvprintw(y, tmp_x, "%c", text[i]);
        }
    }
    attroff(COLOR_PAIR(noPair));
    attroff(A_BOLD);
}

std::string arc::Utility::getText(const std::string &path)
{
    std::ifstream file(path);
    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return (str);
}

int arc::Utility::generatePairColor(int textColor, int bgColor)
{
    static int noPair = 0;

    noPair++;
    init_pair(noPair, textColor, bgColor);
    return (noPair);
}

arc::Event::Type arc::Utility::getEventType(int c)
{
    if (c == KEY_MOUSE) {
        return (arc::Event::Type::MOUSE_PRESSED);
    }
    return (arc::Event::Type::KEY_PRESSED);
}

arc::Event::Key arc::Utility::getEventKey(int c)
{
    static std::map<int, arc::Event::Key> keys = []() -> std::map<int, arc::Event::Key> {
        std::map<int, arc::Event::Key> keys;

        keys['a'] = arc::Event::Key::A;
        keys['A'] = arc::Event::Key::A;
        keys['b'] = arc::Event::Key::B;
        keys['B'] = arc::Event::Key::B;
        keys['c'] = arc::Event::Key::C;
        keys['C'] = arc::Event::Key::C;
        keys['d'] = arc::Event::Key::D;
        keys['D'] = arc::Event::Key::D;
        keys['e'] = arc::Event::Key::E;
        keys['E'] = arc::Event::Key::E;
        keys['f'] = arc::Event::Key::F;
        keys['F'] = arc::Event::Key::F;
        keys['g'] = arc::Event::Key::G;
        keys['G'] = arc::Event::Key::G;
        keys['h'] = arc::Event::Key::H;
        keys['H'] = arc::Event::Key::H;
        keys['i'] = arc::Event::Key::I;
        keys['I'] = arc::Event::Key::I;
        keys['j'] = arc::Event::Key::J;
        keys['J'] = arc::Event::Key::J;
        keys['k'] = arc::Event::Key::K;
        keys['K'] = arc::Event::Key::K;
        keys['l'] = arc::Event::Key::L;
        keys['L'] = arc::Event::Key::L;
        keys['m'] = arc::Event::Key::M;
        keys['M'] = arc::Event::Key::M;
        keys['n'] = arc::Event::Key::N;
        keys['N'] = arc::Event::Key::N;
        keys['o'] = arc::Event::Key::O;
        keys['O'] = arc::Event::Key::O;
        keys['p'] = arc::Event::Key::P;
        keys['P'] = arc::Event::Key::P;
        keys['q'] = arc::Event::Key::Q;
        keys['Q'] = arc::Event::Key::Q;
        keys['r'] = arc::Event::Key::R;
        keys['R'] = arc::Event::Key::R;
        keys['s'] = arc::Event::Key::S;
        keys['S'] = arc::Event::Key::S;
        keys['t'] = arc::Event::Key::T;
        keys['T'] = arc::Event::Key::T;
        keys['u'] = arc::Event::Key::U;
        keys['U'] = arc::Event::Key::U;
        keys['v'] = arc::Event::Key::V;
        keys['V'] = arc::Event::Key::V;
        keys['w'] = arc::Event::Key::W;
        keys['W'] = arc::Event::Key::W;
        keys['x'] = arc::Event::Key::X;
        keys['X'] = arc::Event::Key::X;
        keys['y'] = arc::Event::Key::Y;
        keys['Y'] = arc::Event::Key::Y;
        keys['z'] = arc::Event::Key::Z;
        keys['Z'] = arc::Event::Key::Z;
        keys[KEY_BACKSPACE] = arc::Event::Key::BACKSPACE;
        keys[KEY_ENTER] = arc::Event::Key::RETURN;
        keys[KEY_CTAB] = arc::Event::Key::TAB;
        keys[KEY_EXIT] = arc::Event::Key::ESCAPE;
        keys[KEY_UP] = arc::Event::Key::UP;
        keys[KEY_DOWN] = arc::Event::Key::DOWN;
        keys[KEY_LEFT] = arc::Event::Key::LEFT;
        keys[KEY_RIGHT] = arc::Event::Key::RIGHT;
        keys[KEY_HOME] = arc::Event::Key::HOME;
        keys[KEY_END] = arc::Event::Key::END;
        keys[KEY_PPAGE] = arc::Event::Key::PAGEUP;
        keys[KEY_NPAGE] = arc::Event::Key::PAGEDOWN;
        return (keys);
    }();

    if (keys.count(c))
        return (keys[c]);
    return (arc::Event::Key::NONE);
}