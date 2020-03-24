/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneGameInitTexts
*/

#include "sdl/SceneGame.hpp"

static arc::Text *initTitleStats()
{
    arc::Text *text = new arc::Text();
    text->setFont(FONT, 30);
    text->setText("Stats");
    text->setPosition(350 / 2 - text->getWidth() / 2, 200);
    text->setColor({255, 255, 255, 255});
    return (text);
}

static arc::Text *initTitleHowToPlay()
{
    arc::Text *text = new arc::Text();
    text->setFont(FONT, 30);
    text->setText("How to play");
    text->setPosition(350 / 2 - text->getWidth() / 2, 550);
    text->setColor({255, 255, 255, 255});
    return (text);
}

void arc::SceneGame::initTexts()
{
    _texts.clear();

    _texts.push_back(std::unique_ptr<Text>(initTitleStats()));
    _texts.push_back(std::unique_ptr<Text>(initTitleHowToPlay()));
}