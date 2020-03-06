/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Errors
*/

#ifndef ERRORS_HPP
#define ERRORS_HPP

#include "ArcadeError.hpp"

namespace arc
{

    class DlError : public ArcadeError {
        public:
            DlError(const std::string &message, const std::string &component);
            ~DlError();
    };

    class DirectoryError : public ArcadeError {
        public:
            DirectoryError(const std::string &message, const std::string &component);
            ~DirectoryError();
    };

};

#endif /* !ERRORS_HPP */
