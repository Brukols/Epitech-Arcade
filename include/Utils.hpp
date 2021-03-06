/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <string>

namespace arc {

    struct Color {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };

    enum Orientation {
        UP,
        RIGHT,
        DOWN,
        LEFT,
    };

    enum EntityType {
        PLAYER,
        ENEMY,
        OBSTACLE,
        CONSUMABLE,
        OTHER,
    };

    struct Entity {
        Entity() {
            static int _id = 0;

            id = _id++;
        }

        std::string spritePath;
        Orientation orientation;

        Color backgroundColor;

        EntityType type;

        float x;
        float y;

        int id;

        bool operator==(const Entity &rhs) const {
            return (id == rhs.id);
        }

        bool operator!=(const Entity &rhs) const {
            return !(rhs == *this);
        }
    };

    namespace Event {
        enum Key {
            NONE,
            UNKNOWN,
            A,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K,
            L,
            M,
            N,
            O,
            P,
            Q,
            R,
            S,
            T,
            U,
            V,
            W,
            X,
            Y,
            Z,
            RETURN,
            PAUSE,
            BACKSPACE,
            TAB,
            ESCAPE,
            ENTER,
            DELETE,
            UP,
            DOWN,
            LEFT,
            RIGHT,
            INSERT,
            HOME,
            END,
            PAGEUP,
            PAGEDOWN,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            F13,
            F14,
            F15,
            MOUSE_1,
            MOUSE_2,
            MOUSE_3,
            NUM1,
            NUM2,
            NUM3,
            NUM4,
            NUM5,
            NUM6,
            NUM7,
            NUM8,
            NUM9,
            NUM0,
        };

        enum Type {
            NO_EVENT,
            MOUSE_PRESSED,
            MOUSE_RELEASED,
            MOUSE_WHEEL,
            KEY_PRESSED,
            KEY_RELEASED,
            QUIT,
            RESIZE,
        };

    }
}

#endif /* UTILS_HPP_ */
