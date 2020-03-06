/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Core
*/

#include "Core.hpp"
#include "DLLoader.hpp"
#include "IGraphical.hpp"
#include "Errors.hpp"
#include <iostream>

arc::Core::Core(const std::string &libname)
try {
    DLLoader<IGraphical> loader(libname);

    _lib = std::unique_ptr<IGraphical>(loader.getInstance());
} catch(const DlError &e) {
    throw e;
}

arc::Core::~Core()
{
}

void arc::Core::playArcade()
{
}