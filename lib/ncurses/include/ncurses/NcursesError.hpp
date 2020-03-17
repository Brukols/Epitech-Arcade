/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** NcursesError
*/

#ifndef NCURSESERROR_HPP_
#define NCURSESERROR_HPP_

#include <exception>
#include <string>

namespace arc
{
    class NcursesError : public std::exception {
        public:
            NcursesError(const std::string &message, const std::string &component = "Unknown");
            ~NcursesError();

            const std::string &getComponent() const;
            const char *what() const noexcept override;

        private:
            const std::string _message;
            const std::string _component;
    };

    class MapSizeError : public NcursesError {
        public:
            MapSizeError(const std::string &message, const std::string &component = "Unknown");
            ~MapSizeError();
    };
};

#endif /* !NCURSESERROR_HPP_ */
