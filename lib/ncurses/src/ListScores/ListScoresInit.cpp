/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ListScoresInit
*/

#include "ncurses/ListScores.hpp"
#include "ncurses/ColorsMode.hpp"

static arc::Rectangle initBackgroundRect()
{
    arc::Rectangle rect(35, 120, arc::MAIN_COLOR_8, arc::MAIN_COLOR_8);

    rect.setPosition(60, 5);
    return (rect);
}

void arc::ListScores::initRects()
{
    std::vector<Rectangle (*)()> rects;

    rects.push_back(initBackgroundRect);

    _rects.clear();
    std::for_each(rects.begin(), rects.end(), [this](Rectangle (*fct)()) {
        _rects.push_back(fct());
    });
}

static arc::Text initTitle()
{
    arc::Text text("Scores", arc::MAIN_COLOR_2, arc::MAIN_COLOR_8);

    text.setPosition(117, 7);
    return (text);
}

void arc::ListScores::initTexts()
{
    std::vector<Text (*)()> texts;

    texts.push_back(initTitle);

    _texts.clear();
    std::for_each(texts.begin(), texts.end(), [this](Text (*fct)()) {
        _texts.push_back(fct());
    });
}

static arc::Button initScrollUpButton()
{
    arc::Rectangle rect(3, 120, arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);

    rect.setPosition(60, 10);
    arc::Button button("Up", rect, std::function<void()>());
    button.setColors(arc::MAIN_COLOR_1, arc::MAIN_COLOR_2);
    return (button);
}

static arc::Button initScrollDownButton()
{
    arc::Rectangle rect(3, 120, arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);

    rect.setPosition(60, 37);
    arc::Button button("Down", rect, std::function<void()>());
    button.setColors(arc::MAIN_COLOR_1, arc::MAIN_COLOR_2);
    return (button);
}

void arc::ListScores::initButtons()
{
    std::vector<arc::Button (*)()> buttons;

    buttons.push_back(initScrollUpButton);
    buttons.push_back(initScrollDownButton);

    _buttons.clear();
    std::for_each(buttons.begin(), buttons.end(), [this](arc::Button (*fct)()) {
        _buttons.push_back(fct());
    });
}

static arc::Button initLeftButton(int y, const std::string &name)
{
    arc::Rectangle rect(3, 60, arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);

    rect.setPosition(60, y);
    arc::Button button(name, rect, std::function<void()>());
    button.setColors(arc::MAIN_COLOR_1, arc::MAIN_COLOR_2);
    return (button);
}

static arc::Button initRightButton(int y, const std::string &name)
{
    arc::Rectangle rect(3, 60, arc::MAIN_COLOR_2, arc::MAIN_COLOR_2);

    rect.setPosition(120, y);
    arc::Button button(name, rect, std::function<void()>());
    button.setColors(arc::MAIN_COLOR_1, arc::MAIN_COLOR_2);
    return (button);
}

void arc::ListScores::initTextsScores()
{
    _textScores.clear();

    int i = 0;
    std::for_each(_scores.begin(), _scores.end(), [this, &i](const std::pair<std::string, std::string> &pair) {
        _textScores.push_back(std::pair<Button, Button>(initLeftButton(i * 3 + 13, pair.first), initRightButton(i * 3 + 13, pair.second)));
        if (i % 2) {
            _textScores[_textScores.size() - 1].first.setColors(MAIN_COLOR_1, MAIN_COLOR_8);
            _textScores[_textScores.size() - 1].second.setColors(MAIN_COLOR_1, MAIN_COLOR_8);
        } else {
            _textScores[_textScores.size() - 1].first.setColors(MAIN_COLOR_1, MAIN_COLOR_9);
            _textScores[_textScores.size() - 1].second.setColors(MAIN_COLOR_1, MAIN_COLOR_9);
        }
        i++;
    });
}

void arc::ListScores::init()
{
    initRects();
    initButtons();
    initTexts();
    initTextsScores();
}