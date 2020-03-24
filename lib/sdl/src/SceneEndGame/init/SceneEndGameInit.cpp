/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameInit
*/

#include "sdl/SceneEndGame.hpp"

static arc::IButton *initButtonMenu()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor({2, 148, 165, 255});
    rect.setSize(220, 120);

    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 30);
    text->setText("Menu");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(300, 800);
    button->setColorHover({22, 168, 185, 255});
    return (button);
}

static arc::IButton *initButtonRestart()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor({2, 148, 165, 255});
    rect.setSize(220, 120);

    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 30);
    text->setText("Restart");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(1200, 800);
    button->setColorHover({22, 168, 185, 255});
    return (button);
}

void arc::SceneEndGame::initButtons()
{
    _buttons.clear();
    _buttons.push_back(std::pair<std::unique_ptr<IButton>, void (SceneEndGame::*)()>(initButtonMenu(), &SceneEndGame::eventMenu));
    _buttons.push_back(std::pair<std::unique_ptr<IButton>, void (SceneEndGame::*)()>(initButtonRestart(), &SceneEndGame::eventRestart));
}

void arc::SceneEndGame::init()
{
    initButtons();
}