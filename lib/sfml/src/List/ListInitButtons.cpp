/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListInitButtons
*/

#include "sfml/List.hpp"

static arc::Button initButtonArrowDown(const sf::Font &font, std::function<void()> &fct)
{
    sf::RectangleShape rect(sf::Vector2f(400, 60));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(0, 540));

    arc::Button button(fct, rect, "", font);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    return (button);
}

static arc::Button initButtonArrowUp(const sf::Font &font, std::function<void()> &fct)
{
    sf::RectangleShape rect(sf::Vector2f(400, 60));

    rect.setFillColor(sf::Color(100, 100, 100, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(0, 60));

    arc::Button button(fct, rect, "", font);
    button.setHoverColor(sf::Color(90, 90, 90, 255));
    return (button);
}

void arc::List::functionKeyDown()
{
    if (_buttonsList.size() <= 6)
        return;
    if (static_cast<long unsigned int>(_begin + 1) == _buttonsList.size() - 6)
        return;
    _begin++;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this](Button &button) {
        button.setPosition(sf::Vector2f(button.getPosition().x, button.getPosition().y - 60));
    });
}

void arc::List::functionKeyUp()
{
    if (_begin == 0)
        return;
    _begin--;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this](Button &button) {
        button.setPosition(sf::Vector2f(button.getPosition().x, button.getPosition().y + 60));
    });
}

void arc::List::initButtons(const sf::Font &font)
{
    std::vector<std::pair<arc::Button (*)(const sf::Font &, std::function<void()> &), std::function<void()>>> buttons;

    buttons.push_back(std::pair<arc::Button (*)(const sf::Font &, std::function<void()> &), std::function<void()>>(initButtonArrowDown, [this]() {}));
    buttons.push_back(std::pair<arc::Button (*)(const sf::Font &, std::function<void()> &), std::function<void()>>(initButtonArrowUp, [this](){}));

    _buttons.clear();
    std::for_each(buttons.begin(), buttons.end(), [this, &font](std::pair<arc::Button (*)(const sf::Font &, std::function<void()> &), std::function<void()>> &pair) {
        _buttons.push_back(pair.first(font, pair.second));
    });
}

void arc::List::initButtonsList(const std::vector<std::string> &list, int chosen, const std::function<void (const std::string &)> &fct, const sf::Font &font)
{
    int y = 120;

    int i = 0;
    _buttonsList.clear();
    std::for_each(list.begin(), list.end(), [this, &y, &fct, &i, &chosen, &font](const std::string &name) {
        sf::RectangleShape rect(sf::Vector2f(400, 60));

        if (i % 2) {
            rect.setFillColor(sf::Color(120, 120, 220, 255));
        } else {
            rect.setFillColor(sf::Color(100, 100, 200, 255));
        }
        rect.setOutlineColor(sf::Color::White);
        rect.setOutlineThickness(1);
        rect.setPosition(sf::Vector2f(0, y));

        arc::Button button([this, name, fct](){fct(name);}, rect, name, font);

        if (i == chosen)
            button.setEvent([this](){});
        button.setHoverColor(sf::Color(20, 20, 100, 255));
        button.setColorSelect(sf::Color(20, 20, 100, 255), sf::Color::White, sf::Color(20, 20, 100, 255));
        if (i == chosen)
            button.toggleSelect();
        button.setCharacterSize(20);
        _buttonsList.push_back(button);
        y += 60;
        i++;
    });
}