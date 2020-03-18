/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ListLibraries
*/

#include "sfml/SceneMenu.hpp"

static arc::Button initButton(const std::string &name, std::function<void ()> fct, int y, sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(320, 70));

    rect.setFillColor(sf::Color(20, 20, 120, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(6);
    rect.setPosition(sf::Vector2f(1360, y));
    arc::Button button(fct, rect, name, font);
    button.setHoverColor(sf::Color(50, 50, 150, 255));
    button.setColorSelect(sf::Color(50, 50, 150, 255), sf::Color(20, 150, 20, 255), sf::Color(50, 50, 150, 255));
    button.setActivate(false);
    return (button);
}

static const std::string getLibName(const std::string &path)
{
    std::string tmp = path.substr(path.find("lib_arcade_"), path.length());

    tmp = tmp.substr(11, tmp.size() - 14);
    return (tmp);
}

void arc::SceneMenu::initButtonsListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int choosen)
{
    int y = 440;
    _buttonsListLibraries.clear();

    int i = 0;
    std::for_each(libraries.begin(), libraries.end(), [this, &y, fct, &i, &choosen](const std::string &name) {
        if (i == choosen) {
            _buttonsListLibraries.push_back(initButton(getLibName(name), [this, &fct, name]() {}, y, _font));
        } else {
            _buttonsListLibraries.push_back(initButton(getLibName(name), [this, &fct, name]() {
                _eventListLibs(name);
            }, y, _font));
        }
        y += 150;
        i++;
    });

    i = 0;
    std::for_each(_buttonsListLibraries.begin(), _buttonsListLibraries.end(), [this, &i, &choosen](Button &button) {
        if (i == choosen) {
            button.setActivate(true);
            button.toggleSelect();
            button.setActivate(false);
        }
        i++;
    });
}