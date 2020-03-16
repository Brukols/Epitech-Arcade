/*
** EPITECH PROJECT, 2020
** Arvcade
** File description:
** GRAPHICAL
*/

#include <iostream>
#include "ncurses/Graphical.hpp"
#include "Utils.hpp"
#include <iostream>
#include "ncurses/SceneMenu.hpp"
#include "ncurses/SceneGame.hpp"

arc::Graphical::Graphical()
{
    initscr();
    start_color();
    init_color(COLOR_WHITE, 1000, 1000, 1000);
    init_color(COLOR_RED, 1000, 0, 0);
    init_color(COLOR_BLUE, 0, 0, 1000);
    init_color(COLOR_YELLOW, 1000, 1000, 0);
    init_color(COLOR_GREEN, 0, 1000, 0);
    init_color(COLOR_CYAN, 0, 1000, 1000);
    init_color(COLOR_MAGENTA, 1000, 0, 1000);
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    _scenes[MAIN_MENU] = std::unique_ptr<IScene>(new SceneMenu());
    _scenes[GAME] = std::unique_ptr<IScene>(new SceneGame());
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setFunctionExit([this]() {
        _exit = true;
    });
    _scenes[MAIN_MENU].get()->init();
    static_cast<SceneGame *>(_scenes[GAME].get())->setFunctionBackToMenu([this]() {
        setScene(MAIN_MENU);
    });
}

arc::Graphical::~Graphical()
{
    endwin();
}

void arc::Graphical::setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setListGames(games, fct, chosen);
}

void arc::Graphical::setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen)
{
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setListLibraries(libraries, fct, chosen);
}

void arc::Graphical::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    _scores = scores;
}

void arc::Graphical::setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls)
{
    _controls = controls;
}

void arc::Graphical::setFunctionPlay(const std::function<void()> &function)
{
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setFunctionPlay(function);
}

void arc::Graphical::setFunctionRestart(const std::function<void()> &function)
{
    _eventRestartButton = function;
}

void arc::Graphical::setFunctionMenu(const std::function<void()> &function)
{
    _eventMenuButton = function;
}

void arc::Graphical::setFunctionTogglePause(const std::function<void()> &function)
{
    _eventTogglePauseButton = function;
}

const std::string &arc::Graphical::getUsername() const
{
    return (_username);
}

arc::IGraphical::Scene arc::Graphical::getScene() const
{
    return (_actualScene);
}

void arc::Graphical::setScene(Scene scene)
{
    _actualScene = scene;
    _scenes[_actualScene].get()->init();
    clear();
}

void arc::Graphical::setHowToPlay(const std::vector<std::pair<std::string, std::string>> &info)
{
    _infoHowToPlay = info;
}

void arc::Graphical::setGameStatsFormatString(const std::vector<std::string> &info)
{
    _infoGameStat = info;
}

void arc::Graphical::setFont(const std::string &font)
{
    (void)font;
}

void arc::Graphical::setVisualAssets(const std::map<char, std::pair<std::string, Color>> &sprites)
{
    (void)sprites;
}

void arc::Graphical::updateGameInfo(const std::vector<std::shared_ptr<Entity>> &gameMap)
{
    _entities = gameMap;
}

void arc::Graphical::setMapSize(size_t height, size_t width)
{
    (void)height;
    (void)width;
}

void arc::Graphical::setGameTitle(const std::string &game)
{
    (void)game;
}

arc::Event::Type arc::Graphical::getEventType() const
{
    return (_exit == true ? arc::Event::Type::QUIT : _actualEventType);
}

arc::Event::Key arc::Graphical::getKeyPressed() const
{
    return (_actualKeyPress);
}

void arc::Graphical::setMusic(const std::string &music)
{
    (void)music;
}

void arc::Graphical::playSound(const std::string &sound)
{
    (void)sound;
}

extern "C" arc::IGraphical *instance_ctor()
{
    return (new arc::Graphical());
}
