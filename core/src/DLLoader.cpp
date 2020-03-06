/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Dlloeader
*/

#include <dlfcn.h>
#include "DLLoader.hpp"
#include "Errors.hpp"

template<class T>
DLLoader<T>::DLLoader(const std::string &libname) : _libname(libname)
{
    handle = dlopen("./libfoo.so", RTLD_LAZY);
    if (!handle)
        throw new arc::DlError(dlerror(), "DLLoader");
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