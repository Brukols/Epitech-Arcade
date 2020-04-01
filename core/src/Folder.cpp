/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Folder
*/

#include "Folder.hpp"
#include "Errors.hpp"
#include <filesystem>

arc::Folder::Folder()
{
}

arc::Folder::~Folder()
{
}

const std::vector<std::string> arc::Folder::getFilesFolder(const std::string &name)
{
    std::vector<std::string> names;

    names.clear();
    try {
        for (const auto &entry : std::filesystem::directory_iterator(name)) {
            names.push_back(entry.path());
        }
    } catch(const std::exception& e) {
        throw DirectoryError("Directory " + name + " does not exist", "getFileFolder");
    }
    return (names);
}