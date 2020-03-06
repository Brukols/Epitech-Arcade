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
            DlError(const std::string &component, const std::string &message);
            ~DlError();
    };

};

#endif /* !ERRORS_HPP */
