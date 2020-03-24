/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Input
*/

#include "sdl/Input.hpp"

arc::Input::Input()
{
    _rect = std::unique_ptr<Rectangle>(new Rectangle());
    _text = std::unique_ptr<Text>(new Text());
    _textHover = std::unique_ptr<Text>(new Text());
    _text->setFont(FONT, 25);
    _textHover->setFont(FONT, 25);
    _textHover->setText("Enter a username");
    _textHover->setColor({150, 150, 150, 255});
    _textHover->setPosition(5, 5);
    _text->setPosition(5, 5);

    _cursor = std::unique_ptr<Rectangle>(new Rectangle());
    _cursor->setSize(2, 27);
    _cursor->setPosition(5, 5);
    _cursor->setColor({0, 0, 0, 255});
}

arc::Input::~Input()
{
}

void arc::Input::setPosition(int x, int y)
{
    _rect->setPosition(x, y);
    _text->setPosition(x + 5, y + _textHover->getHeight() / 2);
    _textHover->setPosition(x + 5, y + _textHover->getHeight() / 2);
    _cursor->setPosition(x + 5, y + _textHover->getHeight() / 2 + 2);
}

void arc::Input::setSize(int w, int h)
{
    _rect->setSize(w, h);
}

void arc::Input::setColor(const SDL_Color &color)
{
    _colorRect = color;
}

void arc::Input::setColorSelect(const SDL_Color &color)
{
    _colorRectSelect = color;
}

bool arc::Input::isSelect() const
{
    return (_select);
}

void arc::Input::setSelect(bool select)
{
    _select = select;
}

void arc::Input::setText(const std::string &text)
{
    _text->setText(text);
}

void arc::Input::display(SDL_Renderer *window)
{
    if (_select) {
        _rect->setColor(_colorRectSelect);
        _rect->display(window);
        _text->display(window);
        _cursor->display(window);
    } else {
        _rect->setColor(_colorRect);
        _rect->display(window);
        if (_text->getString().empty())
            _textHover->display(window);
        else
            _text->display(window);
    }
}

void arc::Input::setColorOutline(const SDL_Color &color)
{
    _colorOutlineRect = color;
}

void arc::Input::event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event)
{
    int x;
    int y;

    SDL_GetMouseState(&x, &y);
    if (actualKeyPress == arc::Event::Key::BACKSPACE && actualEventType == arc::Event::Type::KEY_RELEASED && _text->getString().size() != 0) {
        // MOve cursor
        _cursorPosition--;
        std::string tmp(1, _text->getString()[_cursorPosition]);
        _cursor->setPosition(_cursor->getPosX() - _text->getWidthFont(tmp), _cursor->getPosY());
        
        tmp = _text->getString();
        tmp.pop_back();
        _text->setText(tmp);
    }
    if (event.type == SDL_TEXTINPUT && _select) {
        _text->setText(_text->getString() + event.text.text);

        // Move cursor
        std::string tmp(1, _text->getString()[_cursorPosition]);
        _cursor->setPosition(_cursor->getPosX() + _text->getWidthFont(tmp), _cursor->getPosY());
        _cursorPosition++;
    }
    if (actualEventType != arc::Event::Type::MOUSE_RELEASED) {
        return;
    }
    if (_rect->isMouseHover(x, y)) {
        _rect->setColorOutline(_colorOutlineRect);
        _rect->setOutline(true);
        _select = true;
    } else {
        _rect->setOutline(false);
        _select = false;
    }
}