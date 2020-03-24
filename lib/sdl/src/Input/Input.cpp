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
    _text->setColor({0, 0, 0, 255});
    _textHover->setFont(FONT, 25);
    _textHover->setText("Enter a username");
    _textHover->setColor({150, 150, 150, 255});
    _textHover->setPosition(5, 5);
    _text->setPosition(5, 5);

    _cursor = std::unique_ptr<Rectangle>(new Rectangle());
    _cursor->setSize(2, 27);
    _cursor->setPosition(5, 5);
    _cursor->setColor({0, 0, 0, 255});

    _clock = std::clock();
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

const std::string &arc::Input::getText() const
{
    return (_text->getString());
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
    _cursor->setPosition(_cursor->getPosX() + _text->getWidth(), _cursor->getPosY());
    _cursorPosition = _text->getString().size();
}

void arc::Input::display(SDL_Renderer *window)
{
    if (std::clock() - _clock > 400000) {
        _clock = std::clock();
        _cursorDisplay = !_cursorDisplay;
    }

    if (_select) {
        _rect->setColor(_colorRectSelect);
        _rect->display(window);
        _text->display(window);
        if (_cursorDisplay || _editing)
            _cursor->display(window);
    } else {
        _rect->setColor(_colorRect);
        _rect->display(window);
        if (_text->getString().size() == 0)
            _textHover->display(window);
        else
            _text->display(window);
    }
}

void arc::Input::setColorOutline(const SDL_Color &color)
{
    _colorOutlineRect = color;
}

void arc::Input::moveCursorToLeft()
{
    if (_cursorPosition == 0)
        return;
    _delete = true;
    _cursorPosition--;
    std::string tmp(1, _text->getString()[_cursorPosition]);
    _cursor->setPosition(_cursor->getPosX() - _text->getWidthFont(tmp), _cursor->getPosY());
}

void arc::Input::moveCursorToRight()
{
    if (_add == false)
        return;
    _add = false;
    if (static_cast<size_t>(_cursorPosition) >= _text->getString().size())
        return;
    std::string tmp(1, _text->getString()[_cursorPosition]);
    _cursor->setPosition(_cursor->getPosX() + _text->getWidthFont(tmp), _cursor->getPosY());
    _cursorPosition++;
}

void arc::Input::resetClock()
{
    _clock = std::clock();
    _cursorDisplay = true;
}

void arc::Input::deleteCharacter()
{
    std::string text = _text->getString();
    std::string newText = "";

    if (_delete == false)
        return;
    _delete = false;
    for (int i = 0; text[i]; i++) {
        if (i == _cursorPosition)
            continue;
        newText += text[i];
    }
    _text->setText(newText);
}

void arc::Input::addCharacter(const char *c)
{
    std::string text = _text->getString();
    std::string newText = "";
    int i = 0;

    for (; text[i]; i++) {
        if (i == _cursorPosition) {
            newText += c;
        }
        newText += text[i];
    }
    if (i == _cursorPosition)
        newText += c;
    if (_text->getWidthFont(newText) > _rect->getWidth() - 5)
        return;
    _add = true;
    _text->setText(newText);
}

void arc::Input::deleteCharacterForSuppr()
{
    std::string text = _text->getString();
    std::string newText = "";

    for (int i = 0; text[i]; i++) {
        if (i == _cursorPosition)
            continue;
        newText += text[i];
    }
    _text->setText(newText);
}

void arc::Input::event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const SDL_Event &event)
{
    int x;
    int y;

    SDL_GetMouseState(&x, &y);
    if (actualKeyPress == arc::Event::Key::LEFT && actualEventType == arc::Event::Type::KEY_RELEASED && _text->getString().size() != 0 && _select) {
        moveCursorToLeft();
        resetClock();
        return;
    } else if (actualKeyPress == arc::Event::Key::RIGHT && actualEventType == arc::Event::Type::KEY_RELEASED && _text->getString().size() != 0 && _select) {
        _add = true;
        moveCursorToRight();
        resetClock();
        return;
    } else if (actualKeyPress == arc::Event::Key::BACKSPACE && actualEventType == arc::Event::Type::KEY_RELEASED && _text->getString().size() != 0 && _select) {
        moveCursorToLeft();
        deleteCharacter();
        resetClock();
        return;
    } else if (actualKeyPress == arc::Event::Key::DELETE && actualEventType == arc::Event::Type::KEY_RELEASED && _text->getString().size() != 0 && _select) {
        deleteCharacterForSuppr();
        resetClock();
        return;
    } else if (actualKeyPress == arc::Event::Key::RETURN && actualEventType == arc::Event::Type::KEY_RELEASED && _select) {
        _select = false;
        _rect->setOutline(false);
        return;
    }
    if (event.type == SDL_TEXTINPUT && _select) {
        addCharacter(event.text.text);
        moveCursorToRight();
        resetClock();
        return;
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