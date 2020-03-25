/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameInit
*/

#include "sdl/SceneEndGame.hpp"
#include "sdl/Utility.hpp"

static arc::IButton *initButtonMenu()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor(arc::Utility::getColor(arc::Utility::BUTTON));
    rect.setSize(220, 120);

    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 30);
    text->setText("Menu");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(400, 800);
    button->setColorHover(arc::Utility::getColor(arc::Utility::BUTTON_HOVER));
    return (button);
}

static arc::IButton *initButtonRestart()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor(arc::Utility::getColor(arc::Utility::BUTTON));
    rect.setSize(220, 120);

    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 30);
    text->setText("Restart");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(1180, 800);
    button->setColorHover(arc::Utility::getColor(arc::Utility::BUTTON_HOVER));
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
    _listScores->init();
}