/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** List
*/

#include "ncurses/List.hpp"
#include "ncurses/ColorsMode.hpp"

arc::List::List(const std::vector<std::string> &list, int chosen, const std::string &nameList, const std::function<void (const std::string &)> &fct)
: _bgRect(Rectangle(30, 40, MAIN_COLOR_6, BACKGROUND_COLOR)), _title(Text(nameList, MAIN_COLOR_2, BACKGROUND_COLOR))
{
    _eventList = fct;
    _bgRect.setPosition(0, 0);
    _bgRect.setOutlineColors(MAIN_COLOR_1, MAIN_COLOR_6);

    _title.setPosition(_bgRect.getPosX() + _bgRect.getWidth() / 2 - nameList.size() / 2, 2);
    initButtons();
    initButtonsList(list, chosen, fct);
}

arc::List::~List()
{
}

void arc::List::display()
{
    _bgRect.display();
    _title.display();
    std::for_each(_buttons.begin(), _buttons.end(), [](Button &button) {
        button.display();
    });

    int i = 0;
    int max = 5;
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [this, &i, &max](Button &button) {
        if (i > max)
            return;
        if (i >= _begin) {
            button.display();
        } else
            max++;
        i++;
    });
}

void arc::List::setPosition(size_t x, size_t y)
{
    _bgRect.setPosition(_bgRect.getPosX() + x, _bgRect.getPosY() + y);
    _title.setPosition(_bgRect.getPosX() + _bgRect.getWidth() / 2 - _title.getText().size() / 2, 2 + y);
    std::for_each(_buttons.begin(), _buttons.end(), [&x, &y](Button &button) {
        button.setPosition(button.getPosX() + x, button.getPosY() + y);
    });
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [&x, &y](Button &button) {
        button.setPosition(button.getPosX() + x, button.getPosY() + y);
    });
}

void arc::List::setColors(int outlineColorRect, int bgColorList, int textColorList, int bgColorHoverList, int textColorHoverList)
{
    _bgRect.setOutlineColors(BACKGROUND_COLOR, outlineColorRect);
    std::for_each(_buttonsList.begin(), _buttonsList.end(), [&bgColorHoverList, &bgColorList, &textColorHoverList, &textColorList](Button &button) {
        button.setColors(textColorList, bgColorList);
        button.setColorsSelect(textColorHoverList, bgColorHoverList);
        button.setColorsTextSelect(textColorHoverList, bgColorHoverList);
    });
}