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
#include "ncurses/SceneEndGame.hpp"
#include "ncurses/NcursesError.hpp"

arc::Graphical::Graphical()
{
    initscr();
    start_color();
    init_color(MAIN_COLOR_1, 544, 560, 180);
    init_color(MAIN_COLOR_2, 968, 936, 948);
    init_color(MAIN_COLOR_3, 168, 208, 348);
    init_color(MAIN_COLOR_4, 656, 656, 764);
    init_color(MAIN_COLOR_5, 652, 352, 436);
    init_color(MAIN_COLOR_6, 656, 604, 568);
    init_color(MAIN_COLOR_7, 684, 664, 764);
    init_color(MAIN_COLOR_8, 188, 228, 368);
    init_color(MAIN_COLOR_9, 200, 200, 200);
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    mouseinterval(0);
    clear();
    _scenes[MAIN_MENU] = std::unique_ptr<IScene>(new SceneMenu());
    _scenes[GAME] = std::unique_ptr<IScene>(new SceneGame());
    _scenes[END_GAME] = std::unique_ptr<IScene>(new SceneEndGame());
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setFunctionExit([this]() {
        _exit = true;
    });
    _scenes[MAIN_MENU].get()->init();
    static_cast<SceneGame *>(_scenes[GAME].get())->setFunctionBackToMenu([this]() {
        setScene(MAIN_MENU);
    });
    _sceneError.init();
    _scenes[GAME].get()->init();
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
    static_cast<SceneEndGame *>(_scenes[END_GAME].get())->setScores(scores);
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setScores(scores);
    static_cast<SceneEndGame *>(_scenes[END_GAME].get())->setUsername(getUsername());
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setUsername(getUsername());
}

void arc::Graphical::setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->setControls(controls);
}

void arc::Graphical::setFunctionPlay(const std::function<void()> &function)
{
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setFunctionPlay(function);
}

void arc::Graphical::setFunctionRestart(const std::function<void()> &function)
{
    static_cast<SceneEndGame *>(_scenes[END_GAME].get())->setFunctionRestart(function);
}

void arc::Graphical::setFunctionMenu(const std::function<void()> &function)
{
    static_cast<SceneEndGame *>(_scenes[END_GAME].get())->setFunctionMenu(function);
}

void arc::Graphical::setFunctionTogglePause(const std::function<void()> &function)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->setFunctionTogglePause(function);
}

const std::string &arc::Graphical::getUsername()
{
    return (static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->getUsername());
}

void arc::Graphical::setUsername(const std::string &username)
{
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setUsername(username);
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
    static_cast<SceneGame *>(_scenes[GAME].get())->setHowToPlay(info);
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setHowToPlay(info);
}

void arc::Graphical::setGameStats(const std::vector<std::pair<std::string, std::string>> &info)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->setGameStats(info);
}

void arc::Graphical::updateGameInfo(const std::vector<std::shared_ptr<Entity>> &gameMap)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->updateGameInfo(gameMap);
}

void arc::Graphical::setMapSize(size_t height, size_t width)
{
    try {
        static_cast<SceneGame *>(_scenes[GAME].get())->setMapSize(height, width);
    } catch (const arc::MapSizeError &e) {
        _error = true;
        setScene(MAIN_MENU);
        _sceneError.setFunctionBack([this]() {
            _error = false;
            setScene(MAIN_MENU);
        });
        _sceneError.setErrorMessage("Sorry, you can t play to this game : the map is too big :(");
    }
}

void arc::Graphical::setGameTitle(const std::string &game)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->setTitle(game);
}

arc::Event::Type arc::Graphical::getEventType() const
{
    return (_exit == true ? arc::Event::Type::QUIT : _actualEventType);
}

arc::Event::Key arc::Graphical::getKeyPressed() const
{
    return (_actualKeyPress);
}

void arc::Graphical::setGamePause(bool pause)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->setGamePause(pause);
}

extern "C" arc::IGraphical *instance_ctor()
{
    return (new arc::Graphical());
}
