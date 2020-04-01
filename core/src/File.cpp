/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** File
*/

#include "File.hpp"
#include "Errors.hpp"
#include <iostream>

arc::File::File(const std::string &path, std::ios_base::openmode mode) : _path(path)
{
    _fileStream.open(path, mode);
    if (!_fileStream.is_open()) {
        _fileStream.clear();
        throw OpenFileError("Can't find the file", "File");
    }
}

arc::File::~File()
{
    _fileStream.close();
    _fileStream.clear();
}

bool arc::File::getNextLine(std::string &line)
{
    if (std::getline(_fileStream, line))
        return (true);
    return (false);
}

arc::File &arc::File::operator<<(const std::string &name)
{
    _fileStream << name;
    return (*this);
}

arc::File &arc::File::operator<<(std::ostream& (*os)(std::ostream&))
{
    _fileStream << os;
    return (*this);
}