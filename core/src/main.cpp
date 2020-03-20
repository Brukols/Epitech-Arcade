/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Core.hpp"

void print_usage()
{
    std::cout << "Usage" << std::endl;
}

int main(int ac, const char **av)
{
    if (ac != 2) {
        print_usage();
        return (84);
    }
    try {
        arc::Core core(av[1]);
        core.playArcade();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return (84);
    }
    return (0);
}
