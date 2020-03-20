/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreScores
*/

#include "Core.hpp"
#include <fstream>
#include "Errors.hpp"

using myVector = std::vector<std::pair<std::string, std::string>>;

static void sortScoreVector(myVector &scoreVector)
{
    std::sort(scoreVector.begin(), scoreVector.end(), [](const std::pair<std::string, std::string> &left, const std::pair<std::string, std::string> &right) {
            return std::stoi(left.second) > std::stoi(right.second);
    });
}

const myVector arc::Core::getScores() const
{
    std::ifstream file(SCORE_FILENAME, std::ios::in | std::ios::out);
    myVector scoreVector;
    std::size_t pos;
    std::string readUsername = "";
    std::string readScore = "";
    std::string readLine;
    int cpt = 0;

    scoreVector.clear();
    if (!file)
        throw arc::FileError("Cannot open the file, your register will not be register", "getScores");
    while (getline(file, readLine)) {
        size_t i = 0;

        readUsername = "";
        // read the username
        if (readLine[0] != '"')
            throw arc::FileError("Line " + std::to_string(cpt) + ": Cannot find '\"'", "getScores");
        for (i = 1; readLine[i] && readLine[i] != '"'; i++)
            readUsername += readLine[i];
        if (i == 1)
            throw arc::FileError("Line " + std::to_string(cpt) + ": There is no name", "getScores");
        i++;
        if (readLine[i] != ':')
            throw arc::FileError("Line " + std::to_string(cpt) + ": Cannot find ':'", "getScores");


        readScore = "";
        // Read the score
        i++;
        if (readLine[i] != '"')
            throw arc::FileError("Line " + std::to_string(cpt) + ": Cannot find '\"'", "getScores");
        i++;
        for (; readLine[i] && readLine[i] != '"'; i++)
            readScore += readLine[i];
        if (readLine[i] != '"')
            throw arc::FileError("Line " + std::to_string(cpt) + ": Cannot find '\"'", "getScores");
        i++;

        if (readLine[i] && readLine[i] != '\n')
            throw arc::FileError("Line " + std::to_string(cpt) + ": Wrong file format at the end of the line", "getScores");

        scoreVector.push_back(std::make_pair(readUsername, readScore));
        cpt++;
    }
    file.close();
    sortScoreVector(scoreVector);
    return (scoreVector);
}

static void writeFile(myVector &score_vector)
{
    std::ofstream file(SCORE_FILENAME, std::ios::out);
    std::string line;
    myVector::iterator it = score_vector.begin();

    if (file) {
        while (it != score_vector.end()) {
            file << "\"" << it->first << "\":\"" << it->second << "\"" << std::endl;
            it++;
        }
        file.close();
    } else {
        throw arc::FileError("Cannot open the file, your register will not be register", "writeFile");
    }
}

void arc::Core::insertScore(const std::string &name, const std::string &score)
{
    myVector scoreVector;
    bool exist = false;

    scoreVector = getScores();

    std::for_each(scoreVector.begin(), scoreVector.end(), [&name, &score, &exist](std::pair<std::string, std::string> &pair) {
        if (pair.first == name) {
            if (std::stoi(pair.second) < std::stoi(score))
                pair.second = score;
            exist = true;
        }
    });

    if (!exist)
        scoreVector.push_back(std::make_pair(name, score));
    sortScoreVector(scoreVector);
    writeFile(scoreVector);
}