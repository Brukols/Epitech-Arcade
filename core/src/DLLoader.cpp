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
#include "IGame.hpp"
#include <iostream>

template<class T>
DLLoader<T>::DLLoader(const std::string &libname) : _libname(libname)
{
    _handle = dlopen(_libname.c_str(), RTLD_LAZY);
    if (!_handle) {
        throw arc::DlError(dlerror(), "DLLoader");
    }
}

template<class T>
DLLoader<T>::~DLLoader()
{
    // dlclose(_handle);
}

template<class T>
T *DLLoader<T>::getInstance() const
{
    T *(*function)();

    function = reinterpret_cast<T *(*)()>(dlsym(_handle, "instance_ctor"));
    if (dlerror()) {
        throw arc::DlError(dlerror(), "getInstance");
    }
    return (function());
}

template DLLoader<arc::IGraphical>::DLLoader(const std::string &libname);
template DLLoader<arc::IGraphical>::~DLLoader();
template arc::IGraphical *DLLoader<arc::IGraphical>::getInstance() const;

template DLLoader<arc::IGame>::DLLoader(const std::string &libname);
template DLLoader<arc::IGame>::~DLLoader();
template arc::IGame *DLLoader<arc::IGame>::getInstance() const;