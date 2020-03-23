/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitButtons
*/

#include "sdl/SceneMenu.hpp"

static arc::IButton *initButtonPlay()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text text;

    rect.setColor({2, 148, 165, 255});
    rect.setSize(220, 120);

    text.setPosition(800, 50);
    text.setColor({255, 255, 255, 255});
    text.setFont(FONT, 30);
    text.setText("Play");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(100, 350);
    button->setColorHover({22, 168, 185, 255});
    return (button);
}

static arc::IButton *initButtonShowScores()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text text;

    rect.setColor({2, 148, 165, 255});
    rect.setSize(220, 120);

    text.setPosition(800, 50);
    text.setColor({255, 255, 255, 255});
    text.setFont(FONT, 30);
    text.setText("Show scores");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(100, 550);
    button->setColorHover({22, 168, 185, 255});
    return (button);
}

static arc::IButton *initButtonExit()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text text;

    rect.setColor({2, 148, 165, 255});
    rect.setSize(220, 120);

    text.setPosition(800, 50);
    text.setColor({255, 255, 255, 255});
    text.setFont(FONT, 30);
    text.setText("Exit");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(100, 750);
    button->setColorHover({22, 168, 185, 255});
    return (button);
}

void arc::SceneMenu::initButtons()
{
    _buttons.clear();
    _buttons.push_back(std::make_pair(std::shared_ptr<IButton>(initButtonPlay()), &arc::SceneMenu::eventPlay));
    _buttons.push_back(std::make_pair(std::shared_ptr<IButton>(initButtonShowScores()), &arc::SceneMenu::eventShowScores));
    _buttons.push_back(std::make_pair(std::shared_ptr<IButton>(initButtonExit()), &arc::SceneMenu::eventExit));
}