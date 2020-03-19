/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** List
*/

#ifndef LIST_HPP_
#define LIST_HPP_

#include "Button.hpp"
#include "Text.hpp"
#include "Image.hpp"
#include <vector>

namespace arc
{
    class List {
        public:
            List(const std::vector<std::string> &list, int chosen, const std::string &nameList, 
                const std::function<void (const std::string &)> &fct, const sf::Font &font);
            ~List();

            void display(sf::RenderWindow &window);

            void setPosition(const sf::Vector2f &pos);
            void event(sf::Event &event);

            void desactivate();
            void activate();

            bool hasASelectButton() const;

            void setColor(const sf::Color &firstButtonsListColor, const sf::Color &secondButtonsListColor, const sf::Color &buttonsListHover);

        private:

            void initButtonsList(const std::vector<std::string> &list, int chosen,
                                const std::function<void (const std::string &)> &fct, const sf::Font &font);
            void initButtons(const sf::Font &font);

            void resetButtonsList();

            void functionKeyDown();
            void functionKeyUp();

            void eventMouseWheelScrolled(sf::Event &event);
            void eventMouseButtonReleased(sf::Event &event);

        private:
            Image _arrowUp;
            Image _arrowDown;
            sf::RectangleShape _bgRect;
            std::vector<Button> _buttons;
            std::vector<Button> _buttonsList;
            sf::Text _title;
            int _begin;

            std::function<void()> _event;

            bool _activate = true;
    };
} // namespace arc

#endif /* !LIST_HPP_ */
