/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

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
} // namespace arc

#endif /* !ERRORS_HPP_ */
