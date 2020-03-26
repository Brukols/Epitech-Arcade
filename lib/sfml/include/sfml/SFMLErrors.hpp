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

    class SFMLErrors : public ArcadeError {
        public:
            SFMLErrors(const std::string &message, const std::string &component = "Unknown");
            ~SFMLErrors();
    };

    class SpriteError : public ArcadeError {
        public:
            SpriteError(const std::string &message, const std::string &component = "Unknown");
            ~SpriteError();
    };

    class FontError : public ArcadeError {
        public:
            FontError(const std::string &message, const std::string &component = "Unknown");
            ~FontError();
    };
};

#endif /* !SFMLERRORS_HPP_ */