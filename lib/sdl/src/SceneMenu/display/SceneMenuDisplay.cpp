/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneMenuDisplay
*/

#include "sdl/SceneMenu.hpp"

void arc::SceneMenu::display(SDL_Renderer *window)
{
    std::for_each(_rects.begin(), _rects.end(), [&window](Rectangle &rect) {
        rect.display(window);
    });

    std::for_each(_texts.begin(), _texts.end(), [&window](std::shared_ptr<Text> &text) {
        text->display(window);
    });

    std::for_each(_buttons.begin(), _buttons.end(), [&window](std::pair<std::shared_ptr<IButton>, void (SceneMenu::*)()> &button) {
        button.first->display(window);
    });

    _listGames.display(window);
    _listGraphical.display(window);
    _inputUsername->display(window);

    if (_sceneScores->isActivate())
        _sceneScores->display(window);
    else if (_sceneHowToPlay->isActivate()) {
        _sceneHowToPlay->display(window);
    }

    SDL_RenderPresent(window);
}