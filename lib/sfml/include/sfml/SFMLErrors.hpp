/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLErrors
*/

#ifndef SFMLERRORS_HPP_
#define SFMLERRORS_HPP_

#include <exception>
#include <string>

namespace arc
{
    class SFMLErrors : public std::exception {
        public:
            SFMLErrors(const std::string &message, const std::string &component = "Unknown");
            ~SFMLErrors();

            const std::string &getComponent() const;
            const char *what() const noexcept override;

        private:
            const std::string _message;
            const std::string _component;
    };

    class SpriteError : public SFMLErrors {
        public:
            SpriteError(const std::string &message, const std::string &component = "Unknown");
            ~SpriteError();
    };
};

#endif /* !SFMLERRORS_HPP_ */