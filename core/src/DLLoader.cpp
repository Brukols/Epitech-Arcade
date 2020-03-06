/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Dlloeader
*/

#include <dlfcn.h>
#include "DLLoader.hpp"
#include "Errors.hpp"
#include "IGraphical.hpp"
#include <iostream>

template<class T>
DLLoader<T>::DLLoader(const std::string &libname) : _libname(libname)
{
    handle = dlopen(_libname.c_str(), RTLD_LAZY);
    if (!handle)
        throw arc::DlError(dlerror(), "DLLoader");
}

template<class T>
DLLoader<T>::~DLLoader()
{
    dlclose(handle);
}

template<class T>
T *DLLoader<T>::getInstance() const noexcept
{
    return (_lib.get());
}

template DLLoader<arc::IGraphical>::DLLoader(const std::string &libname);
template DLLoader<arc::IGraphical>::~DLLoader();
template arc::IGraphical *DLLoader<arc::IGraphical>::getInstance() const noexcept;