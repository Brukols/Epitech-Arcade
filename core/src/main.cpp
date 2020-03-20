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
    std::ifstream scores_file("C:/Scores/scores.txt");

   if(scores_file)
   {
      std::string ligne; //Une variable pour stocker les lignes lues

      while(std::getline(scores_file, ligne)) //Tant qu'on n'est pas à la fin, on lit
      {
         std::cout << ligne << std::endl;
         //Et on l'affiche dans la console
         //Ou alors on fait quelque chose avec cette ligne
         //À vous de voir
      }
   }
   else
   {
      std::cout << "ERREUR: Impossible d'ouvrir le scores_file en lecture." << std::endl;
   }

   return 0;
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
