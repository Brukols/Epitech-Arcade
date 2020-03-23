/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphical
*/

#include "sdl/Graphical.hpp"
#include "sdl/SceneMenu.hpp"

arc::Graphical::Graphical()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        // Throw exception
        return;
    }
    TTF_Init();
    _window = SDL_CreateWindow("Arcade", 0, 0, 1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    _scenes[MAIN_MENU] = std::unique_ptr<IScene>(new SceneMenu());
    _scenes[MAIN_MENU]->init();
}

arc::Graphical::~Graphical()
{
    TTF_Quit();
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void arc::Graphical::display()
{
    SDL_SetRenderDrawColor(_renderer, 3, 53, 62, 255);
    SDL_RenderClear(_renderer);
    _scenes[_actualScene]->display(_renderer);
    _scenes[_actualScene]->event(_actualEventType, _actualKeyPress);
}

arc::Event::Type arc::Graphical::getEventType() const
{
    return (_actualEventType);
}

arc::Event::Key arc::Graphical::getKeyPressed() const
{
    return (_actualKeyPress);
}

/*
For the menu
*/
void arc::Graphical::setListGames(const std::vector<std::string> &games, const std::function<void (const std::string &)> &fct, int chosen)
{
    (void)games;
    (void)fct;
    (void)chosen;
}

/*
For the menu
*/
void arc::Graphical::setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen)
{
    (void)libraries;
    (void)fct;
    (void)chosen;
}

/*
For the menu
*/
void arc::Graphical::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    (void)scores;
}

void arc::Graphical::setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls)
{
    (void)controls;
}

/*
For the menu
*/
void arc::Graphical::setFunctionPlay(const std::function<void()> &function)
{
    (void)function;
}

void arc::Graphical::setFunctionRestart(const std::function<void()> &function)
{
    (void)function;
}

void arc::Graphical::setFunctionMenu(const std::function<void()> &function)
{
    (void)function;
}

void arc::Graphical::setFunctionTogglePause(const std::function<void()> &function)
{
    (void)function;
}

/*
For the menu
*/
const std::string &arc::Graphical::getUsername()
{
    return (_username);
}

/*
For the menu
*/
void arc::Graphical::setUsername(const std::string &username)
{
    (void)username;
}

arc::IGraphical::Scene arc::Graphical::getScene() const
{
    return (_actualScene);
}

void arc::Graphical::setScene(Scene scene)
{
    _actualScene = scene;
    _scenes[_actualScene]->init();
}

void arc::Graphical::setHowToPlay(const std::vector<std::pair<std::string, std::string>> &info)
{
    (void)info;
}

void arc::Graphical::setGameStats(const std::vector<std::pair<std::string, std::string>> &info)
{
    (void)info;
}

void arc::Graphical::updateGameInfo(const std::vector<std::shared_ptr<Entity>> &gameMap)
{
    (void)gameMap;
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

extern "C" arc::IGraphical *instance_ctor()
{
    return (new arc::Graphical());
}