/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** ArcadeError
*/

#include "ArcadeError.hpp"
#include "Errors.hpp"


// ARCADE ERROR

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


// DLERROR

arc::DlError::DlError(const std::string &message, const std::string &component) : ArcadeError(message, component)
{
}

arc::DlError::~DlError()
{
}


// DIRECTORY ERROR

arc::DirectoryError::DirectoryError(const std::string &message, const std::string &component) : ArcadeError(message, component)
{
}

arc::DirectoryError::~DirectoryError()
{
}


arc::FileError::FileError(const std::string &message, const std::string &component) : ArcadeError(message, component)
{
}

arc::FileError::~FileError()
{
}



arc::OpenFileError::OpenFileError(const std::string &message, const std::string &component) : ArcadeError(message, component)
{
}

arc::OpenFileError::~OpenFileError()
{
}