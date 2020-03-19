/*
** EPITECH PROJECT, 2020
** Arvcade
** File description:
** eventValidateuseraneù
*/

#include "sfml/SceneMenu.hpp"

void arc::SceneMenu::eventValidateUsername()
{
    _username = _inputs[0].getInput();
    _textUsername.clear();
    _inputs.clear();
    _rects.clear();
    _buttonEnterUsername.clear();
    std::for_each(_buttons.begin(), _buttons.end(), [this](Button &button) {
        button.setActivate(true);
    });
    _texts.push_back([this]() -> Text {
        sf::Text text;

        text.setFont(_font);
        text.setString("Username : " + _username);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::White);
        text.setPosition(sf::Vector2f(10, 10));
        text.setOutlineThickness(2);
        text.setOutlineColor(sf::Color::Black);
        arc::Text _text(_font, text);
        _text.setDisplay(true);
        return (_text);
    }());

    std::for_each(_lists.begin(), _lists.end(), [this](List &list) {
        list.activate();
    });
}