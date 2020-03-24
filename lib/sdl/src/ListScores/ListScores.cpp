/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScores
*/

#include "sdl/ListScores.hpp"

arc::ListScores::ListScores()
{
}

arc::ListScores::~ListScores()
{
}

static arc::Rectangle *initBackground()
{
    arc::Rectangle *rect = new arc::Rectangle();

    rect->setPosition(400, 100);
    rect->setColor({0, 0, 0, 255});
    rect->setSize(1000, 600);
    rect->setOutline(true);
    return (rect);
}

void arc::ListScores::initRects()
{
    _rects.clear();
    _rects.push_back(std::unique_ptr<Rectangle>(initBackground()));
}

static arc::Text *initTitle()
{
    arc::Text *text = new arc::Text();
    text->setFont(FONT, 30);
    text->setText("Scores");
    text->setPosition(500 - text->getWidth() / 2 + 400, 130);
    text->setColor({255, 255, 255, 255});
    return (text);
}

void arc::ListScores::initTexts()
{
    _texts.clear();
    _texts.push_back(std::unique_ptr<Text>(initTitle()));
}

void arc::ListScores::init()
{
    initRects();
    initTexts();
}

void arc::ListScores::setUsername(const std::string &username)
{
    _username = username;
}

static arc::ButtonRect *initButtonUsername(const std::string &username, int y)
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor({2, 148, 165, 255});
    rect.setSize(499, 50);

    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 16);
    text->setText(username);
    button->setRect(rect);
    button->setText(text);
    button->setPosition(401, y);
    button->setColorHover({22, 168, 185, 255});
    return (button);
}

static arc::ButtonRect *initButtonScore(const std::string &score, int y)
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor({2, 148, 165, 255});
    rect.setSize(500, 50);

    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 16);
    text->setText(score);
    button->setRect(rect);
    button->setText(text);
    button->setPosition(899, y);
    button->setColorHover({22, 168, 185, 255});
    return (button);
}

void arc::ListScores::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _buttons.clear();
    _begin = 0;
    int y = 199;
    int i = 0;
    std::for_each(scores.begin(), scores.end(), [this, &y, &i](const std::pair<std::string, std::string> &pair) {
        _buttons.push_back(std::pair<std::unique_ptr<ButtonRect>, std::unique_ptr<ButtonRect>>(initButtonUsername(pair.first, y), initButtonScore(pair.second, y)));
        if (i % 2) {
            static_cast<ButtonRect *>(_buttons[_buttons.size() - 1].first.get())->setColor({0, 28, 45, 255});
            static_cast<ButtonRect *>(_buttons[_buttons.size() - 1].first.get())->setColorHover({0, 28, 45, 255});
            static_cast<ButtonRect *>(_buttons[_buttons.size() - 1].second.get())->setColor({0, 28, 45, 255});
            static_cast<ButtonRect *>(_buttons[_buttons.size() - 1].second.get())->setColorHover({0, 28, 45, 255});
        } else {
            static_cast<ButtonRect *>(_buttons[_buttons.size() - 1].first.get())->setColor({0, 48, 65, 255});
            static_cast<ButtonRect *>(_buttons[_buttons.size() - 1].first.get())->setColorHover({0, 48, 65, 255});
            static_cast<ButtonRect *>(_buttons[_buttons.size() - 1].second.get())->setColor({0, 48, 65, 255});
            static_cast<ButtonRect *>(_buttons[_buttons.size() - 1].second.get())->setColorHover({0, 48, 65, 255});
        }
        y += 50;
        i++;
    });
}

void arc::ListScores::display(SDL_Renderer *window)
{
    std::for_each(_rects.begin(), _rects.end(), [&window](std::unique_ptr<Rectangle> &rect) {
        rect->display(window);
    });

    int i = 0;
    std::for_each(_buttons.begin(), _buttons.end(), [&window, &i, this](std::pair<std::unique_ptr<ButtonRect>, std::unique_ptr<ButtonRect>> &button) {
        if (i > 9 + _begin)
            return;
        if (i < _begin) {
            i++;
            return;
        }
        button.first->display(window);
        button.second->display(window);
        i++;
    });

    std::for_each(_texts.begin(), _texts.end(), [&window](std::unique_ptr<Text> &text) {
        text->display(window);
    });
}

void arc::ListScores::eventScrollDown()
{
    if (_buttons.size() <= 9)
        return;
    if (static_cast<long unsigned int>(_begin + 1) == _buttons.size() - 9)
        return;
    _begin++;
    std::for_each(_buttons.begin(), _buttons.end(), [this](std::pair<std::unique_ptr<ButtonRect>, std::unique_ptr<ButtonRect>> &button) {
        button.first->setPosition(button.first->getPosX(), button.first->getPosY() - 50);
        button.second->setPosition(button.second->getPosX(), button.second->getPosY() - 50);
    });
}

void arc::ListScores::eventScrollUp()
{
    if (_begin == 0)
        return;
    _begin--;
    std::for_each(_buttons.begin(), _buttons.end(), [this](std::pair<std::unique_ptr<ButtonRect>, std::unique_ptr<ButtonRect>> &button) {
        button.first->setPosition(button.first->getPosX(), button.first->getPosY() + 50);
        button.second->setPosition(button.second->getPosX(), button.second->getPosY() + 50);
    });
}

void arc::ListScores::event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event)
{
    (void)actualKeyPress;
    int x;
    int y;

    SDL_GetMouseState(&x, &y);
    if (actualEventType == arc::Event::Type::MOUSE_WHEEL) {
        if (!_rects[0]->isMouseHover(x, y))
            return;
        if (event.wheel.y > 0) {
            eventScrollUp();
        } else if (event.wheel.y < 0) {
            eventScrollDown();
        }
        return;
    }
}

bool arc::ListScores::isMouseHover() const
{
    int x;
    int y;

    SDL_GetMouseState(&x, &y);
    return (_rects[0]->isMouseHover(x, y));
}