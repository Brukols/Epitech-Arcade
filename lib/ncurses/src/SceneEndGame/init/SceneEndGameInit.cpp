/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SceneEndGameInit
*/

#include "ncurses/SceneEndGame.hpp"

void arc::SceneEndGame::init()
{
    initButtons();
    _listScores.init();
}