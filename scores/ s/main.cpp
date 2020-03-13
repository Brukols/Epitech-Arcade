/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ios>

#include "score.hpp"

void insert_score_file(myVector score_vector)
{
    std::ofstream file(SCORE_FILENAME, std::ios::out);
    std::string line;
    myVector::iterator it = score_vector.begin();

    std::cout << "insert_score_file\n" << std::endl;
    if(file){
         while(it != score_vector.end())
        {
            file << it->first << ":" << it->second << std::endl;
            it++;
        }
        file.close();
    } else {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }
}

//insert data dans vector
myVector save_score(const std::string surname, std::string score, myVector score_vector)
{
    myVector::iterator it = score_vector.begin();

    while(it != score_vector.end() && (std::stoi(score) <= std::stoi(it->second))) {
        it++;
    }
    score_vector.insert(it, std::make_pair(surname, score));

    score_vector.resize(NB_SCORE);
    score_vector.shrink_to_fit();

    std::cout << "call insert_score_file\n" << std::endl;
    insert_score_file(score_vector);

    return score_vector;
}

//met les données de score_filenema et les met dans
myVector load_score() {
    std::ifstream file(SCORE_FILENAME, std::ios::in);
    std::string line;
    myVector score_vector;
    int cpt = 0;


    std::string read_surname;
    std::string read_score;

    if(file)
    {
         while(!file.eof() && (cpt < NB_SCORE)) //not end of file
        {
            getline(file,read_surname,':');
            getline(file,read_score,'\n');
            score_vector.push_back(std::make_pair(read_surname, read_score));
            cpt++;
        }
        file.close();
    } else {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }
    return(score_vector);
}

void print_score(myVector score_vector)
{
    myVector::iterator it = score_vector.begin();

    while(it != score_vector.end()) {
        std::cout << it->first << ":" << it->second << std::endl;
        it++;
    }
}

//sauvgarde vector dans le fichier.
int main(int ac, char **av)
{
    myVector score_vector;
    int cpt = 0;

    std::string surname = "Luke";
    std::string score = "700";
    score_vector = load_score();
    print_score(score_vector);

    score_vector = save_score(surname, score, score_vector);

    print_score(score_vector);
    return (0);
}