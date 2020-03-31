/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** List
*/

#include "sfml/List.hpp"

arc::List::List(const std::vector<std::string> &list, int chosen, const std::string &nameList,
                const std::function<void (const std::string &)> &fct, const sf::Font &font) :
                _arrowUp(Image("resources/sfml/textures/up-arrow.png")),
                _arrowDown(Image("resources/sfml/textures/down-arrow.png")),
                _begin(0)
{
    _bgRect.setSize(sf::Vector2f(400, 600));
    _bgRect.setFillColor(sf::Color::Black);
    _bgRect.setOutlineThickness(1);
    _bgRect.setOutlineColor(sf::Color::White);

    _arrowDown.setPosition(sf::Vector2f(170, 540));
    _arrowUp.setPosition(sf::Vector2f(170, 55));

    _title.setFont(font);
    _title.setString(nameList);
    _title.setFillColor(sf::Color::White);
    _title.setPosition(sf::Vector2f(_bgRect.getPosition().x + (_bgRect.getLocalBounds().width / 2 - _title.getLocalBounds().width / 2), 10));
    _title.setCharacterSize(25);

    initButtons(font);
    initButtonsList(list, chosen, fct, font);
}

arc::List::~List()
{
}

void arc::List::display(sf::RenderWindow &window)
{
    window.draw(_bgRect);
    
    std::for_each(_buttons.begin(), _buttons.end(), [this, &window](Button &button) {
        button.displayButton(window);
    });

    int i = 0;
    int max = 6;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this, &window, &i, &max](Button &button) {
        if (i > max)
            return;
        if (i >= _begin) {
            button.displayButton(window);
        } else
            max++;
        i++;
    });
    
    _arrowDown.display(window);
    _arrowUp.display(window);
    window.draw(_title);
}

bool arc::List::hasASelectButton() const
{
    return (!(_buttonsList.end() == std::find_if(_buttonsList.begin(), _buttonsList.end(), [this](const Button &button) -> bool {
        return (button.isSelect());
    })));
}

void arc::List::setPosition(const sf::Vector2f &pos)
{
    _bgRect.setPosition(pos);
    _title.setPosition(sf::Vector2f(_bgRect.getPosition().x + (_bgRect.getLocalBounds().width / 2 - _title.getLocalBounds().width / 2), 10 + pos.y));

    std::for_each(_buttons.begin(), _buttons.end(), [this, &pos](Button &button) {
        button.setPosition(sf::Vector2f(button.getPosition().x + pos.x, button.getPosition().y + pos.y));
    });

    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this, &pos](Button &button) {
        button.setPosition(sf::Vector2f(button.getPosition().x + pos.x, button.getPosition().y + pos.y));
    });

    _arrowDown.setPosition(sf::Vector2f(_arrowDown.getPosition().x + pos.x, _arrowDown.getPosition().y + pos.y));
    _arrowUp.setPosition(sf::Vector2f(_arrowUp.getPosition().x + pos.x, _arrowUp.getPosition().y + pos.y));
}

void arc::List::resetButtonsList()
{
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this](Button &button) {
        if (button.isSelect())
            button.toggleSelect();
    });
}

void arc::List::eventMouseButtonReleased(sf::Event &event)
{
    int i = 0;
    int max = 6;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this, &i, &max](Button &button) {
        if (i > max)
            return;
        if (i >= _begin) {
            if (button.isMouseHover(sf::Mouse::getPosition())) {
                resetButtonsList();
                button.toggleSelect();
                if (button.isSelect()) {
                    button.click();
                }
            }
        } else
            max++;
        i++;
    });

    i = 0;
    std::for_each(_buttons.begin(), _buttons.end(), [this, &i](Button &button) {
        if (button.isMouseHover(sf::Mouse::getPosition())) {
            if (i == 0) {
                functionKeyDown();
            } else if (i == 1) {
                functionKeyUp();
            }
        }
        i++;
    });
    (void)event;
}

void arc::List::eventMouseWheelScrolled(sf::Event &event)
{
    sf::Vector2i pos = sf::Mouse::getPosition();

    if (pos.x > _bgRect.getPosition().x && pos.x < _bgRect.getPosition().x + _bgRect.getSize().x && pos.y > _bgRect.getPosition().y && pos.y < _bgRect.getPosition().y + _bgRect.getSize().y) {
        if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
            if (event.mouseWheelScroll.delta < 0)
                functionKeyUp();
            else
                functionKeyDown();
        }
    }
}

void arc::List::event(sf::Event &event)
{
    if (_activate == false)
        return;
    if (event.type == sf::Event::MouseWheelScrolled) {
        eventMouseWheelScrolled(event);
    }
    if (event.type == sf::Event::MouseButtonReleased) {
        eventMouseButtonReleased(event);
    }
}

void arc::List::desactivate()
{
    _activate = false;
    std::for_each(_buttons.begin(), _buttons.end(), [this](Button &button) {
        button.setActivate(false);
    });

    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this](Button &button) {
        button.setActivate(false);
    });
}

void arc::List::activate()
{
    _activate = true;
    std::for_each(_buttons.begin(), _buttons.end(), [this](Button &button) {
        button.setActivate(true);
    });

    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this](Button &button) {
        button.setActivate(true);
    });
}

void arc::List::setColor(const sf::Color &firstButtonsListColor, const sf::Color &secondButtonsListColor, const sf::Color &buttonsListHover)
{
    int i = 0;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this, &firstButtonsListColor, &buttonsListHover, &secondButtonsListColor, &i](Button &button) {
        if (i % 2)
            button.setColor(firstButtonsListColor);
        else
            button.setColor(secondButtonsListColor);
        button.setColorSelect(buttonsListHover, sf::Color::White, buttonsListHover);
        button.setHoverColor(buttonsListHover);
        i++;
    });
}