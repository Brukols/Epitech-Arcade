/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** SceneMEnudisplay
*/

#include "sfml/SceneMenu.hpp"

void arc::SceneMenu::display(sf::RenderWindow &window)
{
    if (_exit == true)
        return;
    std::for_each(_images.begin(), _images.end(), [this, &window](Image &image) {
        image.display(window);
    });

    // Display buttons
    std::for_each(_buttons.begin(), _buttons.end(), [this, &window](arc::Button &button) {
        button.displayButton(window);
    });

    // Displays text
    std::for_each(_texts.begin(), _texts.end(), [this, &window](arc::Text &text) {
        text.display(window);
    });

    // Display list libraries
    std::for_each(_buttonsListGames.begin(), _buttonsListGames.end(), [this, &window](Button &button) {
        button.displayButton(window);
    });

    // Display List games
    std::for_each(_buttonsListLibraries.begin(), _buttonsListLibraries.end(), [this, &window](Button &button) {
        button.displayButton(window);
    });



    // Display Rects
    std::for_each(_rects.begin(), _rects.end(), [this, &window](sf::RectangleShape &rect) {
        window.draw(rect);
    });
    // Display Input
    std::for_each(_inputs.begin(), _inputs.end(), [this, &window](Input &input) {
        input.display(window);
    });

    // Display Input
    std::for_each(_buttonEnterUsername.begin(), _buttonEnterUsername.end(), [this, &window](Button &input) {
        input.displayButton(window);
    });

    std::for_each(_textUsername.begin(), _textUsername.end(), [this, &window](Text &text) {
        text.display(window);
    });

    if (_errorMessages.size() > 0)
        _errorMessages[0].display(window);
}