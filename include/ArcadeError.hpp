/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Errors
*/

#ifndef ARCADE_ERROR_HPP
#define ARCADE_ERROR_HPP

#include <string>

namespace arc {

    class ArcadeError : public std::exception {

        public:
            ArcadeError(const std::string &message, const std::string &component = "Unknown");
            ~ArcadeError();

            const std::string &getComponent() const;
            const char *what() const noexcept override;

        private:
            const std::string _message;
            const std::string _component;
    };

};

#endif /* !ERRORS_HPP */