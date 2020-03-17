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
#include <algorithm>
#include "score.hpp"

void print_score(myVector score_vector)
{
    myVector::iterator it = score_vector.begin();

    while(it != score_vector.end()) {
        std::cout << it->first << ":" << it->second << std::endl;
        it++;
    }
}

int verifLineFormat(std::string line)
{
    int length = line.size();

    // recherche premier char ' " '
    std::size_t pos = line.find_first_of('"');

    // recherche premier '"'
    if (pos != 0) {
        std::cerr << "Format line not ok : recherche premier :" << line << std::endl;
        return 0;
    }
    
    // rechercher deuxieme '"'
    pos = line.find_first_of('"', pos + 1);
    if (pos == std::string::npos) {
        std::cerr << "Format line not ok : rechercher deuxieme : " << line << std::endl;
        return 0;
    }

    //recherche si la chaine est assez longue ("xx":"xx")
    if (length <= pos + 4) {
        std::cerr << "Format line not ok : line too small after the second (\"xx\":\"xx\") \n" << std::endl;
        return 0;
    }

    //rechercher ":"
    if (line[pos + 1] != ':') {
        std::cerr << "Format line not ok : recherche :" << line << std::endl;
        return 0;
    }
    //std::cout << "pos + 1 : " << pos + 1 << std::endl;

    if (line[pos + 2] != '"') {
        std::cerr << "Format line not ok : recherche " << line << std::endl;
        return 0;
    }

    //recherche si il y a autre chose que des chiffres
    pos = pos + 3;
    while (line[pos] != line[length - 1]) {
        if (line[pos] < '0' || line[pos] > '9') {
            std::cerr << "Format line not ok : score is an int " << std::endl;
            return 0;
        }
        pos++;
    }

    // cherche derniere '"'
    if (line[length - 1] != '"') {
        std::cerr << "Format line not ok : " << line << std::endl;
        return 0;
    }
    return 1;
}

myVector sortScoreVector(myVector scoreVector)
{
    std::sort(scoreVector.begin(), scoreVector.end(), 
        [](const std::pair<std::string, std::string> &left, 
           const std::pair<std::string, std::string> &right)
        {return std::stoi(left.second) > std::stol(right.second);});
    return(scoreVector);
}

/*
** 1 - Ouvre le fichier
** 2 - Si tu n'y arrives pas -> on va throw une exception mais pour l'instant return juste un vector avec rien de dedans
** 3 - Si il n'existe pas, tu le créé (--> ca ne sert à rien de le créer il n'y aura rien dedans)
** 4 - Tu lis tout le fichier et tu mets dans un vector (on s'en fout pour le moment de l'ordre)
** 5 - Tu trie le vector que tu as lu avec la fonction sort (Recherche comment elle se fait, tu vas surement devoir faire un overload d'opérateur mais je ne suis pas sûr)
** 6 - Tu le renvoie... logique ^^
*/
myVector getScores()
{
    std::ifstream file(SCORE_FILENAME, std::ios::in);
    myVector scoreVector;
    std::size_t  pos;
    std::string readSurname;
    std::string readScore;
    std::string readLine;
    int cpt = 0;

    if(file)
    {
         while(!file.eof() && (cpt < NB_SCORE)) //not end of file
        {
            getline(file, readLine);
            if (verifLineFormat(readLine)) {

                pos = readLine.find_first_of('"', 1);
                readSurname = readLine.substr(1, pos - 1);
                readScore = readLine.substr(pos + 3, readLine.size() - (pos + 4));
                scoreVector.push_back(std::make_pair(readSurname, readScore));
            } else {
                std::cerr << "Format line not ok : " << readLine << std::endl;
            }
            cpt++;
        }
        file.close();
    } else {
        // throw une exception
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }
    sortScoreVector(scoreVector);
    return (scoreVector);
    
}

void writeFile(myVector score_vector)
{
    std::ofstream file(SCORE_FILENAME, std::ios::out);
    std::string line;
    myVector::iterator it = score_vector.begin();

    if(file){
         while(it != score_vector.end())
        {
            file << "\"" << it->first << "\":\"" << it->second << "\"" << std::endl;
            it++;
        }
        file.close();
    } else {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }
}

/*
** 1 - Appelle la fonction getScores pour récupérer les scores
** 2 - Une fois les scores récupérer (ils sont triés), tu insert le nouveau score
**     1 - Si le vector est plus grand que 10 tu supprimes le dernier et tu rajoutes le score au vector (on s'en fout de l'ordre)
**     2 - Si le vecotr est moins grand que 10, tu rajoutes juste le score au dernier
** 3 - Tu écris le vector dans ton fichier en écrasant la données qui sont déjà insérées
*/
void insertScore(const std::string name, const std::string score)
{
    myVector scoreVector;

    scoreVector = getScores();
    scoreVector.push_back(std::make_pair(name, score));
    scoreVector = sortScoreVector(scoreVector);
    scoreVector.resize(NB_SCORE);
    scoreVector.shrink_to_fit();
    writeFile(scoreVector);
}

//sauvgarde vector dans le fichier.
int main(int ac, char **av)
{
    myVector score_vector;
    std::string name = "UUUo";
    std::string score = "4000";

    insertScore(name, score);
    return (0);
}