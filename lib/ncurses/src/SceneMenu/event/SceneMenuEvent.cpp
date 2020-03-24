/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenu
*/

#include "ncurses/SceneMenu.hpp"
#include "Utils.hpp"

void arc::SceneMenu::eventShowScores()
{
    _sceneScores.init();
    _sceneScores.setActivate(true);
    clear();
}

void arc::SceneMenu::event(arc::Event::Type &_actualEventType, arc::Event::Key &_actualKeyPress)
{
    if (_sceneScores.isActivate()) {
        _sceneScores.event(_actualEventType, _actualKeyPress);
        return;
    }
    int c = wgetch(stdscr);
    static int tmp = -1;

    _actualEventType = Utility::getEventType(c);
    _actualKeyPress = Utility::getEventKey(c);
    if (c == KEY_MOUSE) {
        if (tmp != -1) {
            tmp = -1;
            return;
        }
        tmp = c;
        MEVENT event;
        getmouse(&event);
        eventInputs(event);
        eventButtons(event);
        return;
    }
    if (_inputs[0].isActivate()) {
        if (c == KEY_BACKSPACE) {
            _inputs[0].removeLetter();
            return;
        }
        if (c == '\n') {
            _inputs[0].setActivate(false);
            _username = _inputs[0].getText();
            return;
        }
        _inputs[0].addLetter(c);

        _actualEventType = arc::Event::Type::NO_EVENT;
        _actualKeyPress = arc::Event::Key::NONE;
        return;
    }
    if (_actualKeyPress == arc::Event::Key::ESCAPE) {
        _eventFunctionExit();
        _actualEventType = arc::Event::QUIT;
    }
}