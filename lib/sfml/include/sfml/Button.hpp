/*
** EPITECH PROJECT, 2020
** Button
** File description:
** Arcade
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <functional>

namespace arc
{
    class Button
    {
        public:
            Button(const std::function<void()> &event, const sf::RectangleShape &rect, const std::string &text, const sf::Font &font);
            ~Button();

            bool isMouseHover(const sf::Vector2i &pos) const;
            void clickButton();
            void displayButton(sf::RenderWindow &window);
            
            // Implement select
            void toggleSelect();
            void setColorSelect(sf::Color selectColor, sf::Color selectOutlineColor, sf::Color selectHoverColor);
            void resetSelect();
            bool isSelect() const;

            // GETTER AND SETTER
            void setPosition(const sf::Vector2f &pos);
            void setSize(const sf::Vector2f &size);
            void setColor(const sf::Color &color);
            void setHoverColor(const sf::Color &color);
            void setThicknessColor(const sf::Color &color);
            void setOutlineThickness(int lgt);
            void setEvent(const std::function<void()> &function);
            const std::function<void()> &getEvent() const;
            void setDisplay(bool display);
            const sf::Vector2f &getPosition() const;
            void setCharacterSize(size_t size);
            void setActivate(bool activate);
            bool isActivate() const;
            void setColorUnable(const sf::Color &color);

        private:
            sf::RectangleShape _rect;
            std::function<void()> _event;

            sf::Color _hoverColor;
            sf::Color _mainColor;
            sf::Color _outlineColor;

            bool _select = false;
            sf::Color _selectColor;
            sf::Color _selectOutlineColor;
            sf::Color _selectHoverColor;
            std::string _str;

            sf::Text _text;

            bool _activate = true;
            bool _display = true;

            sf::Vector2f _pos;

            sf::Color _colorUnable = sf::Color(150, 150, 150, 255);
    };
}

#endif /* !BUTTON */
