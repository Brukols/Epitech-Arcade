/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** SceneHowToPlay
*/

#include "sfml/SceneHowToPlay.hpp"

arc::SceneHowToPlay::SceneHowToPlay()
{
    initBg();
    initCase();
}

arc::SceneHowToPlay::~SceneHowToPlay()
{
}

void arc::SceneHowToPlay::display(sf::RenderWindow &window)
{
    window.draw(_bg);
    window.draw(_case);
    std::for_each(_texts.begin(), _texts.end(), [&window](std::unique_ptr<Text> &text) {
        text->display(window);
    });
    _buttonOk->displayButton(window);
}

bool arc::SceneHowToPlay::isActivate() const
{
    return (_activate);
}

void arc::SceneHowToPlay::setActivate(bool activate)
{
    _activate = activate;
}

void arc::SceneHowToPlay::event(const sf::Event &event)
{
    if (event.type != sf::Event::MouseButtonReleased)
        return;
    if (_buttonOk->isMouseHover(sf::Mouse::getPosition())) {
        eventButtonOk();
    }
}

void arc::SceneHowToPlay::setFont(const sf::Font &font)
{
    _font = font;
    initButtonOk();
}

void arc::SceneHowToPlay::initTexts(const std::vector<std::pair<std::string, std::string>> &info)
{
    _texts.clear();
    int i = 0;
    std::for_each(info.begin(), info.end(), [this, &i](const std::pair<std::string, std::string> &pair) {
        sf::Text text;

        text.setFont(_font);
        text.setString(pair.first + " : " + pair.second);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(650, i * 30 + 230));
        _texts.push_back(std::unique_ptr<Text>(new Text(_font, text)));
        i++;
    });
}

void arc::SceneHowToPlay::initButtonOk()
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 700));
    _buttonOk = std::unique_ptr<Button>(new Button(std::function<void()>(), rect, "Ok", _font));
    _buttonOk->setHoverColor(sf::Color(90, 90, 90, 255));
}

void arc::SceneHowToPlay::eventButtonOk()
{
    setActivate(false);
}

void arc::SceneHowToPlay::initBg()
{
    _bg.setFillColor(sf::Color(0, 0, 0, 200));
    _bg.setPosition(sf::Vector2f(0, 0));
    _bg.setSize(sf::Vector2f(1920, 1080));
}

void arc::SceneHowToPlay::initCase()
{
    _case.setFillColor(sf::Color(0, 0, 0, 255));
    _case.setPosition(sf::Vector2f(600, 200));
    _case.setSize(sf::Vector2f(700, 450));
    _case.setOutlineThickness(1);
    _case.setOutlineColor(sf::Color::White);
}