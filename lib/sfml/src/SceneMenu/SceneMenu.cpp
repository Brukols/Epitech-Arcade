/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenu
*/

#include "sfml/SceneMenu.hpp"
#include <SFML/Graphics.hpp>

arc::SceneMenu::SceneMenu()
{
    if (!_font.loadFromFile("resources/sfml/fonts/Raleway-Bold.ttf")) {
        _exit = true;
        return;
    }
    initButtons();
    initTexts();
    initInput();
    initRects();
    initImages();
    _lists.clear();
    _sceneScores.setFont(_font);
    _sceneHowToPlay = std::unique_ptr<SceneHowToPlay>(new SceneHowToPlay());
    _sceneHowToPlay->setFont(_font);
}

arc::SceneMenu::~SceneMenu()
{
}

const std::string &arc::SceneMenu::getUsername()
{
    return (_username);
}