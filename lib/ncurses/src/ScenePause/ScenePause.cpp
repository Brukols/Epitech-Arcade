/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** ScenePause
*/

#include "ncurses/ScenePause.hpp"
#include "ncurses/ColorsMode.hpp"

arc::ScenePause::ScenePause()
{
    init();
}

arc::ScenePause::~ScenePause()
{
}

void arc::ScenePause::init()
{
    arc::Rectangle rect(5, 20, arc::MAIN_COLOR_1, arc::BACKGROUND_COLOR);

    rect.setPosition(110, 31);
    rect.setOutlineColors(arc::MAIN_COLOR_1, arc::MAIN_COLOR_1);
    _buttonPlay = std::unique_ptr<Button>(new Button("Play", rect, std::function<void()>()));
    _buttonPlay->setColors(arc::MAIN_COLOR_1, arc::BACKGROUND_COLOR);

    _textPause = std::unique_ptr<Text>(new Text(Utility::getText("resources/ncurses/texts/pause.txt"), arc::MAIN_COLOR_1, arc::BACKGROUND_COLOR));
    _textPause->setPosition(105, 15);
}

void arc::ScenePause::display()
{
    _textPause->display();
    _buttonPlay->display();
}

void arc::ScenePause::event(arc::Event::Type &actualEventType, arc::Event::Key &actualKeyPress)
{
    static int tmp = -1;

    if (actualEventType != arc::Event::Type::MOUSE_PRESSED)
        return;
    if (tmp != -1) {
        tmp = -1;
        return;
    }
    tmp = KEY_MOUSE;
    MEVENT event;
    getmouse(&event);
    if (_buttonPlay->isMouseHover(event.x, event.y))
        eventTogglePause();
    (void)actualKeyPress;
}

bool arc::ScenePause::isActivate() const
{
    return (_activate);
}

void arc::ScenePause::setActivate(bool activate)
{
    _activate = activate;
}

void arc::ScenePause::setFunctionTogglePause(const std::function<void()> &function)
{
    _eventTogglePause = function;
}

void arc::ScenePause::eventTogglePause()
{
    _eventTogglePause();
}