/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** SceneHowToPlay
*/

#include "sdl/SceneHowToPlay.hpp"
#include <algorithm>

arc::SceneHowToPlay::SceneHowToPlay()
{
    initButtonOk();
    initCase();
    initBg();
    initTexts();
}

arc::SceneHowToPlay::~SceneHowToPlay()
{
}

void arc::SceneHowToPlay::initButtonOk()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor({2, 148, 165, 255});
    rect.setSize(220, 120);

    text->setPosition(800, 50);
    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 30);
    text->setText("Ok");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(850, 750);
    button->setColorHover({22, 168, 185, 255});
    _buttonOk = std::unique_ptr<ButtonRect>(button);
}

void arc::SceneHowToPlay::initTexts()
{
    const std::string names[] = {
        "Previous graphics library : 1",
        "Next graphics library : 0",
        "Previous game : 2",
        "Next game : 9",
        "Restart the game : r",
        "Go back to menu : m",
        "Pause : key space",
        "Exit : key escape"
    };

    for (size_t i = 0; i < 8; i++) {
        arc::Text *text = new arc::Text();

        text->setPosition(650, i * 50 + 250);
        text->setColor({255, 255, 255, 255});
        text->setFont(FONT, 20);
        text->setText(names[i]);
        _texts.push_back(std::unique_ptr<Text>(text));
    }
}

void arc::SceneHowToPlay::initBg()
{
    _bg = std::unique_ptr<Rectangle>(new arc::Rectangle());
    _bg->setPosition(0, 0);
    _bg->setColor({0, 0, 0, 200});
    _bg->setSize(1920, 1080);
}

void arc::SceneHowToPlay::initCase()
{
    _case = std::unique_ptr<Rectangle>(new arc::Rectangle());
    _case->setPosition(550, 200);
    _case->setColor({0, 0, 0, 255});
    _case->setOutline(true);
    _case->setSize(800, 500);
}

void arc::SceneHowToPlay::eventButtonOk()
{
    setActivate(false);
}

void arc::SceneHowToPlay::display(SDL_Renderer *window)
{
    _bg->display(window);
    _case->display(window);
    _buttonOk->display(window);
    std::for_each(_texts.begin(), _texts.end(), [&window](std::unique_ptr<Text> &_text) {
        _text->display(window);
    });
}

bool arc::SceneHowToPlay::isActivate() const
{
    return (_activate);
}

void arc::SceneHowToPlay::setActivate(bool activate)
{
    _activate = activate;
}

void arc::SceneHowToPlay::event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event)
{
    int x;
    int y;

    SDL_GetMouseState(&x, &y);

    if (_buttonOk->isMouseHover(x, y) && actualEventType == arc::Event::Type::MOUSE_RELEASED) {
        eventButtonOk();
    }
    (void)actualEventType;
    (void)actualKeyPress;
    (void)event;
}