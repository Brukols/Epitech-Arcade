/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Button
*/

#include "Graphical.hpp"

arc::Button::Button(const std::function<void()> &event, const sf::RectangleShape &rect) : 
    _rect(rect),
    _event(event),
    _hoverColor(sf::Color(0, 0, 0, 0)),
    _mainColor(rect.getFillColor()),
    _outlineColor(rect.getOutlineColor())
{
}

arc::Button::~Button()
{
}

bool arc::Button::isMouseHover(const sf::Vector2i &pos) const
{
    sf::Vector2f _pos = _rect.getPosition();
    sf::Vector2f _size = _rect.getSize();

    if (pos.x > _pos.x && pos.x < _pos.x + _size.x && pos.y > _pos.y && pos.y < _pos.y + _size.y)
        return (true);
    return (false);
}

void arc::Button::clickButton()
{
    _event();
}

void arc::Button::displayButton(sf::RenderWindow &window)
{
    if (isMouseHover(sf::Mouse::getPosition(window))) {
        if (_select) {
            _rect.setFillColor(_selectHoverColor);
            _rect.setOutlineColor(_selectOutlineColor);
            window.draw(_rect);
        } else {
            _rect.setFillColor(_hoverColor);
            _rect.setOutlineColor(_outlineColor);
            window.draw(_rect);
        }
        return;
    }
    if (_select) {
        _rect.setFillColor(_selectColor);
        _rect.setOutlineColor(_selectOutlineColor);
    } else {
        _rect.setFillColor(_mainColor);
        _rect.setOutlineColor(_outlineColor);
    }
    window.draw(_rect);
}

void arc::Button::setPosition(const sf::Vector2f &pos)
{
    _rect.setPosition(pos);
}

void arc::Button::setSize(const sf::Vector2f &size)
{
    _rect.setSize(size);
}

void arc::Button::setColor(const sf::Color &color)
{
    _mainColor = color;
    _rect.setFillColor(color);
}

void arc::Button::setThicknessColor(const sf::Color &color)
{
    _rect.setOutlineColor(color);
}

void arc::Button::setOutlineThickness(int lgt)
{
    _rect.setOutlineThickness(lgt);
}

void arc::Button::setEvent(const std::function<void()> &function)
{
    _event = function;
}

void arc::Button::setHoverColor(const sf::Color &color)
{
    _hoverColor = color;
}

void arc::Button::toggleSelect()
{
    _select = !_select;
}

void arc::Button::setColorSelect(sf::Color selectColor, sf::Color selectOutlineColor, sf::Color selectHoverColor)
{
    _selectColor = selectColor;
    _selectOutlineColor = selectOutlineColor;
    _selectHoverColor = selectHoverColor;
}