/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLErrors
*/

#include "sfml/SFMLErrors.hpp"

arc::SFMLErrors::SFMLErrors(const std::string &message, const std::string &component) : _message(message), _component(component)
{
}

arc::SFMLErrors::~SFMLErrors()
{
}

const std::string &arc::SFMLErrors::getComponent() const
{
    return (_component);
}

const char *arc::SFMLErrors::what() const noexcept
{
    return (_message.c_str());
}

arc::SpriteError::SpriteError(const std::string &message, const std::string &component) : SFMLErrors(message, component)
{
}

arc::SpriteError::~SpriteError()
{
}