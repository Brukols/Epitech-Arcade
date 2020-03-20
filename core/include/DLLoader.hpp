/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** dlloade
*/

#ifndef DLLOADER_HPP
#define DLLOADER_HPP

#include <memory>
#include <dlfcn.h>
#include "DLLoader.hpp"
#include "Errors.hpp"
#include "IGraphical.hpp"
#include "IGame.hpp"
#include <iostream>

template<typename T>
class DLLoader {
    public:
        DLLoader(const std::string &libname) : _libname(libname)
        {
            _handle = dlopen(_libname.c_str(), RTLD_LAZY);
            if (!_handle) {
                throw arc::DlError(dlerror(), "DLLoader");
            }
        }

        ~DLLoader()
        {
            dlclose(_handle);
        }

        T *getInstance() const
        {
            T *(*function)();

            function = reinterpret_cast<T *(*)()>(dlsym(_handle, "instance_ctor"));
            if (function == nullptr) {
                throw arc::DlError(dlerror(), "getInstance");
            }
            return (function());
        }

    protected:

    private:
        void *_handle;
        std::unique_ptr<T> _lib;
        const std::string _libname;
};

#endif /* !DLLOADER_HPP */
