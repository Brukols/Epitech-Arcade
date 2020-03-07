/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** dlloade
*/

#ifndef DLLOADER_HPP
#define DLLOADER_HPP

#include <memory>

template<typename T>
class DLLoader {
    public:
        DLLoader(const std::string &libname);
        ~DLLoader();

        T *getInstance() const;

    protected:

    private:
        void *_handle;
        std::unique_ptr<T> _lib;
        const std::string _libname;
};

#endif /* !DLLOADER_HPP */
