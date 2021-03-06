/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#include "sdl/Text.hpp"
#include "sdl/Errors.hpp"

arc::Text::Text()
{
}

arc::Text::~Text()
{
    if (_font)
        TTF_CloseFont(_font);
    if (_surface)
        SDL_FreeSurface(_surface);
    if (_texture)
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
    if (_font) {
        TTF_CloseFont(_font);
        if (_surface)
            SDL_FreeSurface(_surface);
        if (_texture)
            SDL_DestroyTexture(_texture);
        _surface = nullptr;
        _texture = nullptr;
    }
    _font = TTF_OpenFont(path.c_str(), size);
    if (_font == nullptr) {
        throw FontError("Unable to load this font " + path, "setFont");
    }
}

void arc::Text::setText(const std::string &text)
{
    _text = text;
    if (_texture) {
        SDL_DestroyTexture(_texture);
        _texture = nullptr;
    }
    if (_surface)
        SDL_FreeSurface(_surface);
    _surface = nullptr;
}

void arc::Text::display(SDL_Renderer *window)
{
    int width = 0;
    int height = 0;

    if (_surface == nullptr)
        _surface = TTF_RenderText_Solid(_font, _text.c_str(), _color);
    if (_texture == nullptr)
        _texture = SDL_CreateTextureFromSurface(window, _surface);
    SDL_QueryTexture(_texture, NULL, NULL, &width, &height);

    SDL_Rect rect = {static_cast<int>(_x), static_cast<int>(_y), width, height};
    SDL_RenderCopy(window, _texture, NULL, &rect);
}

size_t arc::Text::getHeight() const
{
    int w;
    int h;

    TTF_SizeText(_font, _text.c_str(), &w, &h);
    return (h);
}

size_t arc::Text::getWidth() const
{
    int w;
    int h;

    TTF_SizeText(_font, _text.c_str(), &w, &h);
    return (w);
}

int arc::Text::getPosX() const
{
    return (_x);
}

int arc::Text::getPosY() const
{
    return (_y);
}

const std::string &arc::Text::getString() const
{
    return (_text);
}

int arc::Text::getWidthFont(const std::string &str)
{
    int w;
    int h;

    TTF_SizeText(_font, str.c_str(), &w, &h);
    return (w);
}