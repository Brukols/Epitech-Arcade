/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMenu
*/

#include "sfml/SceneMenu.hpp"
#include <SFML/Graphics.hpp>
#include "sfml/SFMLErrors.hpp"

arc::SceneMenu::SceneMenu()
{
    if (!_font.loadFromFile("resources/sfml/fonts/Raleway-Bold.ttf")) {
        throw FontError("Unable to load the font", "SceneMenu");
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

void arc::SceneMenu::setHowToPlay(const std::vector<std::pair<std::string, std::string>> &info)
{
    _sceneHowToPlay->initTexts(info);
}

const std::string &arc::SceneMenu::getUsername()
{
    return (_username);
}