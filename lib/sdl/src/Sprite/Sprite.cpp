/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sprite
*/

#include "sdl/Sprite.hpp"
#include "sdl/Errors.hpp"

arc::Sprite::Sprite(const std::string &path)
{
    _image = IMG_Load(path.c_str());
    if (!_image)
        throw SpriteError("Unable to load the image", "Sprite");
}

arc::Sprite::~Sprite()
{
    if (_texture)
        SDL_DestroyTexture(_texture);
    if (_image) {
        SDL_FreeSurface(_image);
    }
}

void arc::Sprite::display(SDL_Renderer *window)
{
    if (_texture == nullptr) {
        _texture = SDL_CreateTextureFromSurface(window, _image);
    }
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    SDL_Point center = {_rect.w / 2, _rect.h / 2};

    SDL_RenderCopyEx(window, _texture, NULL, &_rect, _angle, &center, flip);
}

void arc::Sprite::setScale(int width, int height)
{
    _rect.w = width;
    _rect.h = height;
}

void arc::Sprite::setPosition(int x, int y)
{
    _rect.x = x;
    _rect.y = y;
}

int arc::Sprite::getHeight() const
{
    return (_image->h);
}

int arc::Sprite::getWidth() const
{
    return (_image->w);
}

void arc::Sprite::setRotation(float angle)
{
    _angle = angle;
}