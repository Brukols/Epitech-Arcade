/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** Errors
*/

#include "sdl/Errors.hpp"

arc::ArcadeError::ArcadeError(const std::string &message, const std::string &component) : _message(message), _component(component)
{
}

arc::ArcadeError::~ArcadeError()
{
}

const std::string &arc::ArcadeError::getComponent() const
{
    return (_component);
}

const char *arc::ArcadeError::what() const noexcept
{
    return (_message.c_str());
}

arc::SpriteError::SpriteError(const std::string &message, const std::string &component) : ArcadeError(message, component)
{
}

arc::SpriteError::~SpriteError()
{
}

arc::FontError::FontError(const std::string &message, const std::string &component) : ArcadeError(message, component)
{
}

arc::FontError::~FontError()
{
}