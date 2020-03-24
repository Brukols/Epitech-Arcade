/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListLibraries
*/

#include "sdl/ListLibraries.hpp"

arc::ListLibraries::ListLibraries()
{
    initRects();
}

arc::ListLibraries::~ListLibraries()
{
}

void arc::ListLibraries::setFont(const std::string &path)
{
    _font = path;
}

void arc::ListLibraries::setEventList(const std::function<void (const std::string &)> &fct)
{
    _eventList = fct;
}

void arc::ListLibraries::setNameList(const std::string &nameList)
{
    arc::Text *text = new arc::Text();

    text->setFont(_font, 30);
    text->setText(nameList);
    text->setPosition(250 - text->getWidth() / 2, 30);
    text->setColor({255, 255, 255, 255});
    _texts.push_back(std::shared_ptr<Text>(text));
}

static const std::string getLibName(const std::string &path)
{
    std::string tmp = path.substr(path.find("lib_arcade_"), path.length());

    tmp = tmp.substr(11, tmp.size() - 14);
    return (tmp);
}

static arc::ButtonRect initButtonList(int y, const std::string &name)
{
    arc::ButtonRect button;

    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor({2, 148, 165, 255});
    rect.setSize(498, 80);

    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 20);
    text->setText(getLibName(name));
    button.setRect(rect);
    button.setText(text);
    button.setPosition(1, y);
    button.setColorHover({22, 168, 185, 255});
    button.setColorSelect({22, 168, 185, 255});
    return (button);
}

void arc::ListLibraries::eventListButtons(const std::string &name)
{
    _eventList(name);
}

void arc::ListLibraries::setNameLibraries(const std::vector<std::string> &list, int chosen)
{
    _buttonsList.clear();

    int i = 0;
    std::for_each(list.begin(), list.end(), [this, &i, &chosen](const std::string &name) {
        _buttonsList.push_back(std::make_pair(initButtonList(i * 80 + 89, name), name));
        if (i == chosen)
            _buttonsList[_buttonsList.size() - 1].first.setSelect(true);
        if (i % 2) {
            _buttonsList[_buttonsList.size() - 1].first.setColor({0, 28, 45, 255});
        } else {
            _buttonsList[_buttonsList.size() - 1].first.setColor({0, 48, 65, 255});
        }
        i++;
    });
}

void arc::ListLibraries::display(SDL_Renderer *window)
{
    std::for_each(_rects.begin(), _rects.end(), [&window](Rectangle &rect) {
        rect.display(window);
    });

    std::for_each(_texts.begin(), _texts.end(), [&window](std::shared_ptr<Text> &text) {
        text->display(window);
    });

    int i = 0;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this, &window, &i](std::pair<ButtonRect, std::string> &button) {
        if (i > 6 + _begin)
            return;
        if (i < _begin) {
            i++;
            return;
        }
        button.first.display(window);
        i++;
    });
}

void arc::ListLibraries::setPosition(int x, int y)
{
    std::for_each(_rects.begin(), _rects.end(), [&x, &y](Rectangle &rect) {
        rect.setPosition(rect.getRect().x + x, rect.getRect().y + y);
    });

    std::for_each(_texts.begin(), _texts.end(), [&x, &y](std::shared_ptr<Text> &text) {
        text->setPosition(text->getPosX() + x, text->getPosY() + y);
    });

    std::for_each(_buttonsList.begin(), _buttonsList.end(), [&x, &y](std::pair<ButtonRect, std::string> &button) {
        button.first.setPosition(button.first.getPosX() + x, button.first.getPosY() + y);
    });
}

void arc::ListLibraries::resetButtonsList()
{
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [](std::pair<ButtonRect, std::string> &button) {
        button.first.setSelect(false);
    });
}

void arc::ListLibraries::eventScrollUp()
{
    if (_begin == 0)
        return;
    _begin--;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this](std::pair<ButtonRect, std::string> &button) {
        button.first.setPosition(button.first.getPosX(), button.first.getPosY() + 80);
    });
}

void arc::ListLibraries::eventScrollDown()
{
    if (_buttonsList.size() <= 6)
        return;
    if (static_cast<long unsigned int>(_begin + 1) == _buttonsList.size() - 6)
        return;
    _begin++;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this](std::pair<ButtonRect, std::string> &button) {
        button.first.setPosition(button.first.getPosX(), button.first.getPosY() - 80);
    });
}

void arc::ListLibraries::event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event)
{
    (void)actualKeyPress;
    int x;
    int y;

    SDL_GetMouseState(&x, &y);
    if (actualEventType == arc::Event::Type::MOUSE_WHEEL) {
        if (!_rects[0].isMouseHover(x, y))
            return;
        if (event.wheel.y > 0) {
            eventScrollUp();
        } else if (event.wheel.y < 0) {
            eventScrollDown();
        }
        return;
    }
    if (actualEventType != arc::Event::Type::MOUSE_RELEASED)
        return;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [&x, &y, this](std::pair<ButtonRect, std::string> &button) {
        if (button.first.isSelect())
            return;
        if (button.first.isMouseHover(x, y)) {
            resetButtonsList();
            eventListButtons(button.second);
            button.first.setSelect(true);
        }
    });
}