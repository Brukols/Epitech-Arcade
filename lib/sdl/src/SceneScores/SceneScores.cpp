/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneScores
*/

#include "sdl/SceneScores.hpp"
#include <algorithm>

arc::SceneScores::SceneScores()
{
    _listScores = std::unique_ptr<ListScores>(new ListScores());
}

arc::SceneScores::~SceneScores()
{
}

static arc::Rectangle *initBackground()
{
    arc::Rectangle *rect = new arc::Rectangle();

    rect->setPosition(0, 0);
    rect->setColor({0, 0, 0, 150});
    rect->setSize(1920, 1080);
    return (rect);
}

void arc::SceneScores::initRects()
{
    _rects.clear();
    _rects.push_back(std::unique_ptr<Rectangle>(initBackground()));
}

void arc::SceneScores::init()
{
    initRects();
    _listScores->init();
}

void arc::SceneScores::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _listScores->setScores(scores);
}

void arc::SceneScores::display(SDL_Renderer *window)
{
    std::for_each(_rects.begin(), _rects.end(), [&window](std::unique_ptr<Rectangle> &rect) {
        rect->display(window);
    });

    _listScores->display(window);
}

bool arc::SceneScores::isActivate() const
{
    return (_activate);
}

void arc::SceneScores::setActivate(bool activate)
{
    _activate = activate;
}

void arc::SceneScores::event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event)
{
    if (actualEventType == arc::Event::Type::MOUSE_RELEASED) {
        if (!_listScores->isMouseHover()) {
            setActivate(false);
            return;
        }
    }
    _listScores->event(actualEventType, actualKeyPress, event);
}