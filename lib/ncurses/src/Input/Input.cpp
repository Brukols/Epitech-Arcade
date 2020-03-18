/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Input
*/

#include "ncurses/Input.hpp"
#include "ncurses/ColorsMode.hpp"

arc::Input::Input(const Rectangle &rect, const Text &text) : _rect(rect), _textIndication(text), _text(Text("", MAIN_COLOR_1, MAIN_COLOR_8))
{
    _text.setPosition(_rect.getPosX(), _rect.getPosY() + _rect.getHeight() / 2);
}

arc::Input::~Input()
{
}

void arc::Input::display()
{
    _rect.display();
    _textIndication.display();
    _text.display();
}

bool arc::Input::isMouseHover(size_t x, size_t y) const
{
    if (x >= _rect.getPosX() && x <= _rect.getPosX() + _rect.getWidth() && y >= _rect.getPosY() && y <= _rect.getPosY() + _rect.getHeight()) {
        return (true);
    }
    return (false);
}

void arc::Input::setColorsSelect(int textColor, int bgColor)
{
    _rect.setColorsSelect(textColor, bgColor);
}

void arc::Input::setActivate(bool activate)
{
    _activate = activate;
    if (_activate) {
        _rect.setSelect(true);
    } else {
        _rect.setSelect(false);
    }
}

bool arc::Input::isActivate() const
{
    return (_activate);
}

void arc::Input::addLetter(int c)
{
    if (_text.getText().size() + 1 > _rect.getWidth())
        return;
    if (isprint(c)) {
        _text.setText(_text.getText() + static_cast<char>(c));
        _text.setPosition(_rect.getWidth() / 2 - _text.getText().size() / 2 + _rect.getPosX(), _rect.getPosY() + _rect.getHeight() / 2);
    }
}

void arc::Input::removeLetter()
{
    std::string text = _text.getText();

    if (!text.empty())
        text.pop_back();
    _text.setText(text);
    _text.setPosition(_rect.getWidth() / 2 - _text.getText().size() / 2 + _rect.getPosX(), _rect.getPosY() + _rect.getHeight() / 2);
}