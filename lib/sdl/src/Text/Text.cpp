/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#include "sdl/Text.hpp"

arc::Text::Text()
{
}

arc::Text::~Text()
{
    // TTF_CloseFont(_font);
    SDL_FreeSurface(_surface);
    SDL_DestroyTexture(_texture);
}

void arc::Text::setPosition(size_t x, size_t y)
{
    _x = x;
    _y = y;
}

void arc::Text::setColor(const SDL_Color &color)
{
    _color = color;
}

void arc::Text::setFont(const std::string &path, int size)
{
    _font = TTF_OpenFont(path.c_str(), size);
}

void arc::Text::display(SDL_Renderer *window)
{
    int texW = 0;
    int texH = 0;
    if (_surface == nullptr)
        _surface = TTF_RenderText_Solid(_font, _text.c_str(), _color);
    if (_texture == nullptr)
        _texture = SDL_CreateTextureFromSurface(window, _surface);
    SDL_QueryTexture(_texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 0, 0, texW, texH };
    SDL_RenderCopy(window, _texture, NULL, &dstrect);
    // SDL_DestroyTexture(_texture);
}