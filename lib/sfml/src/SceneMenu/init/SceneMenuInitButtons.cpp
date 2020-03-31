/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Init button
*/

#include "sfml/SceneMenu.hpp"

static arc::Button initButtonPlay(sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(89, 87, 117, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 320));
    arc::Button button(std::function<void()>(), rect, "Play", font);
    button.setHoverColor(sf::Color(109, 107, 137, 255));
    button.setActivate(false);
    return (button);
}

static arc::Button initButtonExit(sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(89, 87, 117, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 820));
    arc::Button button(std::function<void()>(), rect, "Exit", font);
    button.setHoverColor(sf::Color(109, 107, 137, 255));
    button.setActivate(false);
    button.setColorUnable(sf::Color(150, 150, 150, 255));
    return (button);
}

static arc::Button initButtonEnterUsername(sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 80));

    rect.setFillColor(sf::Color(89, 87, 117, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 700));
    arc::Button button(std::function<void()>(), rect, "Validate", font);
    button.setHoverColor(sf::Color(109, 107, 137, 255));
    return (button);
}

static arc::Button initButtonWatchScores(sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(89, 87, 117, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 490));
    arc::Button button(std::function<void()>(), rect, "Watch scores", font);
    button.setHoverColor(sf::Color(109, 107, 137, 255));
    button.setActivate(false);
    return (button);
}

static arc::Button initButtonHowToPlay(sf::Font &font)
{
    sf::RectangleShape rect(sf::Vector2f(220, 100));

    rect.setFillColor(sf::Color(89, 87, 117, 255));
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(1);
    rect.setPosition(sf::Vector2f(830, 660));
    arc::Button button(std::function<void()>(), rect, "How to play", font);
    button.setHoverColor(sf::Color(109, 107, 137, 255));
    button.setActivate(false);
    button.setColorUnable(sf::Color(150, 150, 150, 255));
    return (button);
}

void arc::SceneMenu::initButtons()
{
    _buttons.clear();
    _buttons.push_back(std::pair<Button, void (SceneMenu::*)()>(initButtonPlay(_font), &SceneMenu::eventButtonPlay));
    _buttons.push_back(std::pair<Button, void (SceneMenu::*)()>(initButtonExit(_font), &SceneMenu::eventButtonExit));
    _buttons.push_back(std::pair<Button, void (SceneMenu::*)()>(initButtonWatchScores(_font), &SceneMenu::eventWatchScores));
    _buttons.push_back(std::pair<Button, void (SceneMenu::*)()>(initButtonHowToPlay(_font), &SceneMenu::eventHowToPlay));

    _buttonEnterUsername.clear();

    _buttonEnterUsername.push_back(std::pair<Button, void (SceneMenu::*)()>(initButtonEnterUsername(_font), &SceneMenu::eventValidateUsername));
}