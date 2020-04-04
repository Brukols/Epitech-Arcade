/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include <string>
#include "ArcadeError.hpp"

namespace arc
{
    class FileError : public ArcadeError {
        public:
            FileError(const std::string &message, const std::string &component = "Unknown");
            ~FileError();
    };
} // namespace arc

#endif /* !ERRORS_HPP_ */
