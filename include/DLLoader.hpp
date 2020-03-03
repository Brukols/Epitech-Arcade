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
        DLLoader(T *lib);
        ~DLLoader();

        T *getInstance() const noexcept;

    protected:

    private:
        std::unique_ptr<T *> _lib;
};

#endif /* !DLLOADER_HPP */
