/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScores
*/

#include "sdl/ListScores.hpp"
#include "sdl/Utility.hpp"

arc::ListScores::ListScores()
{
    _buttons.clear();
}

arc::ListScores::~ListScores()
{
}

void arc::ListScores::changeColor()
{
    int i = 0;
    std::for_each(_buttons.begin(), _buttons.end(), [&i, this](std::pair<std::unique_ptr<ButtonRect>, std::unique_ptr<ButtonRect>> &button) {
        if (i % 2) {
            button.first->setColor(Utility::getColor(Utility::BUTTON_LIST));
            button.first->setColorHover(Utility::getColor(Utility::BUTTON_LIST));
            button.second->setColor(Utility::getColor(Utility::BUTTON_LIST));
            button.second->setColorHover(Utility::getColor(Utility::BUTTON_LIST));
        } else {
            button.first->setColor(Utility::getColor(Utility::BUTTON_LIST_2));
            button.first->setColorHover(Utility::getColor(Utility::BUTTON_LIST_2));
            button.second->setColor(Utility::getColor(Utility::BUTTON_LIST_2));
            button.second->setColorHover(Utility::getColor(Utility::BUTTON_LIST_2));
        }
        i++;
    });
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
    int i = 0;
    std::for_each(_buttons.begin(), _buttons.end(), [this, &i](std::pair<std::unique_ptr<ButtonRect>, std::unique_ptr<ButtonRect>> &button) {
        if (button.first->getText() == _username) {
            button.first->setColor(Utility::getColor(Utility::BUTTON_HOVER));
            button.second->setColor(Utility::getColor(Utility::BUTTON_HOVER));
            button.first->setColorHover(Utility::getColor(Utility::BUTTON_HOVER));
            button.second->setColorHover(Utility::getColor(Utility::BUTTON_HOVER));
        } else {
            if (i % 2) {
                button.first.get()->setColor(Utility::getColor(Utility::BUTTON_LIST));
                button.first.get()->setColorHover(Utility::getColor(Utility::BUTTON_LIST));
                button.second.get()->setColor(Utility::getColor(Utility::BUTTON_LIST));
                button.second.get()->setColorHover(Utility::getColor(Utility::BUTTON_LIST));
            } else {
                button.first.get()->setColor(Utility::getColor(Utility::BUTTON_LIST_2));
                button.first.get()->setColorHover(Utility::getColor(Utility::BUTTON_LIST_2));
                button.second.get()->setColor(Utility::getColor(Utility::BUTTON_LIST_2));
                button.second.get()->setColorHover(Utility::getColor(Utility::BUTTON_LIST_2));
            }
        }
        i++;
    });
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
            _buttons[_buttons.size() - 1].first.get()->setColor(Utility::getColor(Utility::BUTTON_LIST));
            _buttons[_buttons.size() - 1].first.get()->setColorHover(Utility::getColor(Utility::BUTTON_LIST));
            _buttons[_buttons.size() - 1].second.get()->setColor(Utility::getColor(Utility::BUTTON_LIST));
            _buttons[_buttons.size() - 1].second.get()->setColorHover(Utility::getColor(Utility::BUTTON_LIST));
        } else {
            _buttons[_buttons.size() - 1].first.get()->setColor(Utility::getColor(Utility::BUTTON_LIST_2));
            _buttons[_buttons.size() - 1].first.get()->setColorHover(Utility::getColor(Utility::BUTTON_LIST_2));
            _buttons[_buttons.size() - 1].second.get()->setColor(Utility::getColor(Utility::BUTTON_LIST_2));
            _buttons[_buttons.size() - 1].second.get()->setColorHover(Utility::getColor(Utility::BUTTON_LIST_2));
        }
        if (_username == pair.first) {
            _buttons[_buttons.size() - 1].first.get()->setColor(Utility::getColor(Utility::BUTTON_HOVER));
            _buttons[_buttons.size() - 1].first.get()->setColorHover(Utility::getColor(Utility::BUTTON_HOVER));
            _buttons[_buttons.size() - 1].second.get()->setColor(Utility::getColor(Utility::BUTTON_HOVER));
            _buttons[_buttons.size() - 1].second.get()->setColorHover(Utility::getColor(Utility::BUTTON_HOVER));
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