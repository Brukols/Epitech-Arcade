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

std::vector<std::pair<std::string, std::string>> getScores()
{
    /*
    ** 1 - Ouvre le fichier
    ** 2 - Si tu n'y arrives pas -> on va throw une exception mais pour l'instant return juste un vector avec rien de dedans
    ** 3 - Si il n'existe pas, tu le créé
    ** 4 - Tu lis tout le fichier et tu mets dans un vector (on s'en fout pour le moment de l'ordre)
    ** 5 - Tu trie le vector que tu as lu avec la fonction sort (Recherche comment elle se fait, tu vas surement devoir faire un overload d'opérateur mais je ne suis pas sûr)
    ** 6 - Tu le renvoie... logique ^^
    */
}

void insertScore(const std::string &name, const std::string &score)
{
    /*
    ** 1 - Appelle la fonction getScores pour récupérer les scores
    ** 2 - Une fois les scores récupérer (ils sont triés), tu insert le nouveau score
    **     1 - Si le vector est plus grand que 10 tu supprimes le dernier et tu rajoutes le score au vector (on s'en fout de l'ordre)
    **     2 - Si le vecotr est moins grand que 10, tu rajoutes juste le score au dernier
    ** 3 - Tu écris le vector dans ton fichier en écrasant la données qui sont déjà insérées
    */
}

/*
** Pour le fichier la convention est simple: "nom":"score" (n'oublies pas de rajouter les quotes)
** Si le fichier est mauvais, n'oublies pas de faire une gestion d'erreur en gros si tu lis: "nom":"score ce n'est pas bon
*/

/*
** Pour le nommage des variables et des fonctions, tout en camelCase ! Pas de snake_case et la PascalCase est pour le nom des classes
*/

/*
** Autres choses, force toi à utilisez les fonctions de la librairies <alogrithm>, pour l'opti est c'est mieux
** Par exemple, pour parcourir un vector tu vas faire un :
** std::for_each(myVector.begin(), myVector.end(), [](std::pair<std::string, std::string) &pair) {
** 
** });
*/

//sauvgarde vector dans le fichier.
int main(int ac, char **av)
{
    myVector score_vector;
    int cpt = 0;

    score_vector = load_score();
    print_score(score_vector);
    return (0);
}