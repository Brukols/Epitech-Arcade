/*
** EPITECH PROJECT, 2020
** Button
** File description:
** Arcade
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

namespace arc
{
    class Button
    {
        public:
            Button(const std::function<void()> &event, const sf::RectangleShape &rect);
            ~Button();

            bool isMouseHover(const sf::Vector2i &pos) const;
            void clickButton();
            void displayButton(sf::RenderWindow &window);

            // GETTER AND SETTER
            void setPosition(const sf::Vector2f &pos);
            void setSize(const sf::Vector2f &size);
            void setColor(const sf::Color &color);
            void setHoverColor(const sf::Color &color);
            void setThicknessColor(const sf::Color &color);
            void setOutlineThickness(int lgt);
            void setEvent(const std::function<void()> &function);
            const std::function<void()> &getEvent() const;

        private:
            sf::RectangleShape _rect;
            std::function<void()> _event;

            sf::Color _hoverColor;
            sf::Color _mainColor;
    };
}

#endif /* !BUTTON */
