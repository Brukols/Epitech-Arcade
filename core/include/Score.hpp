/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include <string>
#include <vector>

using vector = std::vector<std::pair<std::string, std::string>>;

namespace arc
{
    class Score {
        public:
            Score(const std::string &path);
            ~Score();

            const vector getScores() const;
            void insertScore(const std::string &name, const std::string &score) const;

        private:
            void writeFile(const std::string &path, vector &score_vector) const;
            void sortScoreVector(vector &scoreVector) const;
            std::string getNextData(const std::string &line, size_t &i, int cpt) const;

        private:
            std::string _path;
    };
} // namespace arc

#endif /* !SCORE_HPP_ */
