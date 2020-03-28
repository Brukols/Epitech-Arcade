/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** SceneHowToPlay
*/

#include "sdl/SceneHowToPlay.hpp"
#include <algorithm>
#include "sdl/Utility.hpp"

arc::SceneHowToPlay::SceneHowToPlay()
{
    initButtonOk();
    initCase();
    initBg();
    // initTexts();
}

arc::SceneHowToPlay::~SceneHowToPlay()
{
}

void arc::SceneHowToPlay::changeColor()
{
    _buttonOk->setColor(Utility::getColor(Utility::BUTTON));
    _buttonOk->setColorHover(Utility::getColor(Utility::BUTTON_HOVER));
}

void arc::SceneHowToPlay::initButtonOk()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor(Utility::getColor(Utility::BUTTON));
    rect.setSize(220, 120);

    text->setPosition(800, 50);
    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 30);
    text->setText("Ok");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(850, 750);
    button->setColorHover(Utility::getColor(Utility::BUTTON_HOVER));
    _buttonOk = std::unique_ptr<ButtonRect>(button);
}

void arc::SceneHowToPlay::initTexts(const std::vector<std::pair<std::string, std::string>> &info)
{
    _texts.clear();
    int i = 0;
    std::for_each(info.begin(), info.end(), [this, &i](const std::pair<std::string, std::string> &pair) {
        arc::Text *text = new arc::Text();

        text->setPosition(650, i * 30 + 250);
        text->setColor({255, 255, 255, 255});
        text->setFont(FONT, 20);
        text->setText(pair.first + " : " + pair.second);
        _texts.push_back(std::unique_ptr<Text>(text));
        i++;
    });
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