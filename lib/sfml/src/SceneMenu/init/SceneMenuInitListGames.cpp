/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ListGames
*/

#include "SceneMenu.hpp"

static arc::Button initButton(const std::string &name, const std::function<void ()> &fct, int y, sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(320, 70));

    rect.setFillColor(sf::Color(120, 20, 20, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(6);
    rect.setPosition(sf::Vector2f(150, y));
    arc::Button button(fct, rect, name, font);
    button.setHoverColor(sf::Color(150, 50, 50, 255));
    button.setColorSelect(sf::Color(150, 50, 50, 255), sf::Color(20, 150, 20, 255), sf::Color(150, 50, 50, 255));
    (void)fct;
    button.setActivate(false);
    return (button);
}

static const std::string getLibName(const std::string &path)
{
    std::string tmp = path.substr(path.find("lib_arcade_"), path.length());

    tmp = tmp.substr(11, tmp.size() - 14);
    return (tmp);
}

void arc::SceneMenu::initButtonsListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct)
{
    int y = 440;
    _buttonsListGames.clear();

    std::for_each(games.begin(), games.end(), [this, &y, fct](const std::string &name) {
        _buttonsListGames.push_back(initButton(getLibName(name), [this, &fct, name]() {
            _eventListGames(name);
        }, y, _font));
        y += 150;
    });
}