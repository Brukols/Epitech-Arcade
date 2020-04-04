/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Errors
*/

#include "Errors.hpp"

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

arc::FileError::FileError(const std::string &message, const std::string &component) : ArcadeError(message, component)
{
}

arc::FileError::~FileError()
{
}