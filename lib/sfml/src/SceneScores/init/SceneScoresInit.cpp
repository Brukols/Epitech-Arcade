/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneScoresInit
*/

#include "sfml/SceneScores.hpp"

static sf::RectangleShape initBackground()
{
    sf::RectangleShape rect(sf::Vector2f(1920, 1080));

    rect.setFillColor(sf::Color(0, 0, 0, 210));
    rect.setPosition(sf::Vector2f(0, 0));
    return (rect);
}

void arc::SceneScores::initRects()
{
    std::vector<sf::RectangleShape (*)()> rects;

    rects.push_back(initBackground);

    _rects.clear();

    std::for_each(rects.begin(), rects.end(), [this](sf::RectangleShape (*fct)()) {
        _rects.push_back(fct());
    });
}

static arc::Image initCloseImage()
{
    arc::Image image("assets/sfml/textures/close.png");

    image.setPosition(sf::Vector2f(1400, 120));
    return (image);
}

void arc::SceneScores::initImages()
{
    std::vector<std::pair<arc::Image (*)(), void (SceneScores::*)()>> images;

    images.push_back(std::pair<arc::Image (*)(), void (SceneScores::*)()>(initCloseImage, &arc::SceneScores::eventCloseImage));

    _images.clear();

    std::for_each(images.begin(), images.end(), [this](std::pair<arc::Image (*)(), void (SceneScores::*)()> &pair) {
        _images.push_back(std::pair<Image, void (SceneScores::*)()>(pair.first(), pair.second));
    });
}

void arc::SceneScores::init()
{
    initRects();
    initImages();
    _listScores.init();
}