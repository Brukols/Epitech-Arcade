/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** ScenePause
*/

#include "sfml/ScenePause.hpp"

arc::ScenePause::ScenePause()
{
    _bg.setFillColor(sf::Color(0, 0, 0, 200));
    _bg.setPosition(sf::Vector2f(0, 0));
    _bg.setSize(sf::Vector2f(1920, 1080));
}

arc::ScenePause::~ScenePause()
{
}

void arc::ScenePause::display(sf::RenderWindow &window)
{
    window.draw(_bg);
    _textPause->display(window);
    _buttonPlay->displayButton(window);
}

void arc::ScenePause::setFont(const sf::Font &font)
{
    _font = font;

    sf::Text text;
    text.setFont(_font);
    text.setString("Pause");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(760, 400));
    _textPause = std::unique_ptr<Text>(new Text(_font, text));

    initButtonPlay();
}

bool arc::ScenePause::isActivate() const
{
    return (_activate);
}

void arc::ScenePause::setActivate(bool activate)
{
    _activate = activate;
}

void arc::ScenePause::setFunctionTogglePause(const std::function<void()> &function)
{
    _eventTogglePause = function;
}

void arc::ScenePause::event(const arc::Event::Type &actualEventType, const arc::Event::Key &actualKeyPress, const sf::Event &event)
{
    if (event.type != sf::Event::MouseButtonReleased)
        return;
    if (_buttonPlay->isMouseHover(sf::Mouse::getPosition())) {
        eventTogglePause();
    }
    (void)actualEventType;
    (void)actualKeyPress;
}

void arc::ScenePause::eventTogglePause()
{
    _eventTogglePause();
}

void arc::ScenePause::initButtonPlay()
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(800, 650));

    _buttonPlay = std::unique_ptr<Button>(new Button(std::function<void()>(), rect, "Play", _font));
    _buttonPlay->setHoverColor(sf::Color(90, 90, 90, 255));
}