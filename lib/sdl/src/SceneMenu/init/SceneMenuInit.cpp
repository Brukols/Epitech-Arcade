/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuInit
*/

#include "sdl/SceneMenu.hpp"

void arc::SceneMenu::init()
{
    initRects();
    initTexts();
    initButtons();
}

void arc::SceneMenu::initInputUsername()
{
    _inputUsername = std::unique_ptr<Input>(new Input());
    _inputUsername->setColor({255, 255, 255, 255});
    _inputUsername->setColorSelect({255, 255, 255, 255});
    _inputUsername->setSize(300, 60);
    _inputUsername->setPosition(40, 30);
    _inputUsername->setColorOutline({22, 168, 185, 255});
}