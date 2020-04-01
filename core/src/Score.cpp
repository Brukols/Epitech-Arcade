/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Score
*/

#include "Score.hpp"
#include "File.hpp"
#include <algorithm>
#include "Errors.hpp"

arc::Score::Score(const std::string &path) : _path(path)
{
}

arc::Score::~Score()
{
}

void arc::Score::sortScoreVector(vector &scoreVector) const
{
    std::sort(scoreVector.begin(), scoreVector.end(), [](const std::pair<std::string, std::string> &left, const std::pair<std::string, std::string> &right) {
        return std::stoi(left.second) > std::stoi(right.second);
    });
}

std::string arc::Score::getNextData(const std::string &line, size_t &i, int cpt) const
{
    std::string data = "";

    if (line[i] != '"')
        throw arc::FileError("Line " + std::to_string(cpt) + ": Cannot find '\"'", "getScores");
    i++;
    size_t tmp = i;
    for (; line[i] && line[i] != '"'; i++)
        data += line[i];
    if (i == tmp)
        throw arc::FileError("Line " + std::to_string(cpt) + ": There is no name", "getScores");
    i++;
    return (data);
}

const vector arc::Score::getScores() const
try {
    File file(_path, std::ios::in);

    vector scoreVector;
    std::string readLine;

    scoreVector.clear();

    for (int cpt = 0; file.getNextLine(readLine); cpt++) {
        size_t i = 0;
        std::string username = "";
        std::string score = "";

        username = getNextData(readLine, i, cpt);
        if (readLine[i] != ':')
            throw arc::FileError("Line " + std::to_string(cpt) + ": Cannot find ':'", "getScores");
        i++;
        score = getNextData(readLine, i, cpt);
        if (readLine[i] && readLine[i] != '\n')
            throw arc::FileError("Line " + std::to_string(cpt) + ": Wrong file format at the end of the line", "getScores");
        scoreVector.push_back(std::make_pair(username, score));
    }
    sortScoreVector(scoreVector);
    return (scoreVector);
} catch (const arc::FileError &e) {
    throw e;
} catch (const arc::OpenFileError &e) {
    vector scoreVector;

    std::ofstream out(_path);
    out.close();
    scoreVector.clear();
    return (scoreVector);    
}

void arc::Score::writeFile(const std::string &path, vector &scores) const
try {
    File file(path, std::ios::out);
    std::string line;

    std::for_each(scores.begin(), scores.end(), [&file](const std::pair<std::string, std::string> &score) {
        file << "\"" << score.first << "\":\"" << score.second << "\"" << std::endl;
    });
} catch (const arc::FileError &e) {
    throw e;
} catch (const arc::OpenFileError &e) {
    std::ofstream file(_path);

    std::for_each(scores.begin(), scores.end(), [&file](const std::pair<std::string, std::string> &score) {
        file << "\"" << score.first << "\":\"" << score.second << "\"" << std::endl;
    });
    file.close();
}

void arc::Score::insertScore(const std::string &name, const std::string &score) const
try {
    vector scoreVector;
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
    writeFile(_path, scoreVector);
} catch (const arc::FileError &e) {
    throw e;
}