/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Folder
*/

#ifndef FOLDER_HPP_
#define FOLDER_HPP_

#include <vector>
#include <string>

namespace arc
{
    class Folder {
        public:
            Folder();
            ~Folder();

            const std::vector<std::string> getFilesFolder(const std::string &name);

        private:
    };
} // namespace arc

#endif /* !FOLDER_HPP_ */
