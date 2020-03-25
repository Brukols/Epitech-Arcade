/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInitButtons
*/

#include "sdl/SceneMenu.hpp"
#include "sdl/Utility.hpp"

static arc::IButton *initButtonPlay()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor(arc::Utility::getColor(arc::Utility::BUTTON));
    rect.setSize(220, 120);

    text->setPosition(800, 50);
    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 30);
    text->setText("Play");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(100, 250);
    button->setColorHover(arc::Utility::getColor(arc::Utility::BUTTON_HOVER));
    button->setActivate(false);
    return (button);
}

static arc::IButton *initButtonShowScores()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor(arc::Utility::getColor(arc::Utility::BUTTON));
    rect.setSize(220, 120);

    text->setPosition(800, 50);
    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 30);
    text->setText("Show scores");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(100, 450);
    button->setColorHover(arc::Utility::getColor(arc::Utility::BUTTON_HOVER));
    button->setActivate(false);
    return (button);
}

static arc::IButton *initButtonExit()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor(arc::Utility::getColor(arc::Utility::BUTTON));
    rect.setSize(220, 120);

    text->setPosition(800, 50);
    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 30);
    text->setText("Exit");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(100, 850);
    button->setColorHover(arc::Utility::getColor(arc::Utility::BUTTON_HOVER));
    return (button);
}

static arc::IButton *initButtonHowToPlay()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor(arc::Utility::getColor(arc::Utility::BUTTON));
    rect.setSize(220, 120);

    text->setPosition(800, 50);
    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 30);
    text->setText("How to play");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(100, 650);
    button->setColorHover(arc::Utility::getColor(arc::Utility::BUTTON_HOVER));
    return (button);
}

static arc::IButton *initButtonChangeToBlueTheme()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor(arc::Utility::getColor(arc::Utility::BUTTON));
    rect.setSize(220, 120);

    text->setPosition(800, 50);
    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 22);
    text->setText("Switch to blue");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(1600, 50);
    button->setColorHover(arc::Utility::getColor(arc::Utility::BUTTON_HOVER));
    return (button);
}

static arc::IButton *initButtonChangeToRedTheme()
{
    arc::ButtonRect *button = new arc::ButtonRect();
    arc::Rectangle rect;
    arc::Text *text = new arc::Text();

    rect.setColor(arc::Utility::getColor(arc::Utility::BUTTON));
    rect.setSize(220, 120);

    text->setPosition(800, 50);
    text->setColor({255, 255, 255, 255});
    text->setFont(FONT, 22);
    text->setText("Switch to Red");
    button->setRect(rect);
    button->setText(text);
    button->setPosition(1600, 50);
    button->setColorHover(arc::Utility::getColor(arc::Utility::BUTTON_HOVER));
    return (button);
}

void arc::SceneMenu::initButtons()
{
    _buttons.clear();
    _buttons.push_back(std::make_pair(std::shared_ptr<IButton>(initButtonPlay()), &arc::SceneMenu::eventPlay));
    _buttons.push_back(std::make_pair(std::shared_ptr<IButton>(initButtonShowScores()), &arc::SceneMenu::eventShowScores));
    _buttons.push_back(std::make_pair(std::shared_ptr<IButton>(initButtonHowToPlay()), &arc::SceneMenu::eventHowToPlay));
    _buttons.push_back(std::make_pair(std::shared_ptr<IButton>(initButtonExit()), &arc::SceneMenu::eventExit));
    if (Utility::getTheme() == Utility::BLUE) {
        _buttons.push_back(std::make_pair(std::shared_ptr<IButton>(initButtonChangeToRedTheme()), &arc::SceneMenu::eventChangeTheme));
    } else {
        _buttons.push_back(std::make_pair(std::shared_ptr<IButton>(initButtonChangeToBlueTheme()), &arc::SceneMenu::eventChangeTheme));
    }
}