/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** main
*/

#include <iostream>

void print_usage()
{
    std::cout << "Usage" << std::endl;
}

int main(int ac, char const *av[])
{
    if (ac != 2) {
        print_usage();
        return (84);
    }
    (void) av;
    return 0;
}
