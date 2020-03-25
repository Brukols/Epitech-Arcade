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

    _textPause->setPosition(800, 500);
    _textPause->setColor({255, 255, 255, 255});
    _textPause->setFont(FONT, 100);
    _textPause->setText("Pause");

    _bg = std::unique_ptr<Rectangle>(new arc::Rectangle());
    _bg->setPosition(0, 0);
    _bg->setColor({0, 0, 0, 100});
    _bg->setSize(1920, 1080);
}

arc::ScenePause::~ScenePause()
{
}

void arc::ScenePause::display(SDL_Renderer *window)
{
    _bg->display(window);
    _textPause->display(window);
}

bool arc::ScenePause::isActivate() const
{
    return (_activate);
}

void arc::ScenePause::setActivate(bool activate)
{
    _activate = activate;
}