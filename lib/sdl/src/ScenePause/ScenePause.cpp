/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** ScenePause
*/

#include "sdl/ScenePause.hpp"

arc::ScenePause::ScenePause()
{
    _textPause = std::unique_ptr<Text>(new arc::Text());

    _textPause->setPosition(800, 300);
    _textPause->setColor({255, 255, 255, 255});
    _textPause->setFont(FONT, 100);
    _textPause->setText("Pause");

    _bg = std::unique_ptr<Rectangle>(new arc::Rectangle());
    _bg->setPosition(0, 0);
    _bg->setColor({0, 0, 0, 200});
    _bg->setSize(1920, 1080);

    initButtonPlay();
}

arc::ScenePause::~ScenePause()
{
}

void arc::ScenePause::initButtonPlay()
{
    _buttonPlay = std::unique_ptr<ButtonRect>(new arc::ButtonRect());

    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor({2, 148, 165, 255});
    rect.setSize(220, 120);

    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 30);
    text->setText("Play");

    _buttonPlay->setRect(rect);
    _buttonPlay->setText(text);
    _buttonPlay->setPosition(850, 600);
    _buttonPlay->setColorHover({22, 168, 185, 255});
}

void arc::ScenePause::display(SDL_Renderer *window)
{
    _bg->display(window);
    _textPause->display(window);
    _buttonPlay->display(window);
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

void arc::ScenePause::event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event)
{
    int x;
    int y;

    SDL_GetMouseState(&x, &y);

    if (_buttonPlay->isMouseHover(x, y) && actualEventType == arc::Event::Type::MOUSE_RELEASED) {
        eventTogglePause();
    }
}