/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** NcursesError
*/

#include "ncurses/NcursesError.hpp"

arc::NcursesError::NcursesError(const std::string &message, const std::string &component) : _message(message), _component(component)
{
}

arc::NcursesError::~NcursesError()
{
}

const std::string &arc::NcursesError::getComponent() const
{
    return (_component);
}

const char *arc::NcursesError::what() const noexcept
{
    return (_message.c_str());
}

arc::MapSizeError::MapSizeError(const std::string &message, const std::string &component) : NcursesError(message, component)
{

}

arc::MapSizeError::~MapSizeError()
{

}