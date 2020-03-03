/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** dlloadee
*/

#include "DLLoader.hpp"

template<class T>
DLLoader<T>::DLLoader(T *lib) : _lib(lib)
{
}

template<class T>
DLLoader<T>::~DLLoader()
{
}

template<class T>
T *DLLoader<T>::getInstance() const noexcept
{
    return (_lib.get());
}
