/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitButtons
*/

#include "sdl/SceneMenu.hpp"

static arc::IButton *initButtonEx()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text text;

    rect.setColor({255, 0, 0, 255});
    rect.setSize(200, 100);

    text.setPosition(800, 50);
    text.setColor({255, 255, 255, 255});
    text.setFont(FONT, 20);
    text.setText("Play");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(100, 100);
    return (button);
}

void arc::SceneMenu::initButtons()
{
    _buttons.clear();
    _buttons.push_back(std::shared_ptr<IButton>(initButtonEx()));
}