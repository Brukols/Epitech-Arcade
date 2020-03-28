/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphical
*/

#include "sdl/Graphical.hpp"
#include "sdl/SceneMenu.hpp"
#include "sdl/SceneGame.hpp"
#include "sdl/SceneEndGame.hpp"
#include "sdl/Utility.hpp"
#include "sdl/Errors.hpp"

arc::Graphical::Graphical()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw ArcadeError("Unable to init the lib", "Grapical");
    }
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    _window = SDL_CreateWindow("Arcade", 0, 0, 1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    _scenes[MAIN_MENU] = std::unique_ptr<IScene>(new SceneMenu());
    _scenes[GAME] = std::unique_ptr<IScene>(new SceneGame());
    _scenes[END_GAME] = std::unique_ptr<IScene>(new SceneEndGame());
    _scenes[MAIN_MENU]->init();
}

arc::Graphical::~Graphical()
{
    _scenes.clear();
    IMG_Quit();
    TTF_Quit();
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void arc::Graphical::display()
{
    Utility::changeCursor(SDL_SYSTEM_CURSOR_ARROW);
    SDL_SetRenderDrawColor(_renderer, Utility::getColor(Utility::BACKGROUND_COLOR).r, Utility::getColor(Utility::BACKGROUND_COLOR).g, Utility::getColor(Utility::BACKGROUND_COLOR).b, Utility::getColor(Utility::BACKGROUND_COLOR).a);
    SDL_RenderClear(_renderer);
    _scenes[_actualScene]->display(_renderer);
    _scenes[_actualScene]->event(_actualEventType, _actualKeyPress);
    Utility::changeCursor(SDL_SYSTEM_CURSOR_ARROW, true);
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
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setListGames(games, fct, chosen);
}

/*
For the menu
*/
void arc::Graphical::setListLibraries(const std::vector<std::string> &libraries, const std::function<void (const std::string &)> &fct, int chosen)
{
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setListLibraries(libraries, fct, chosen);
}

/*
For the menu
*/
void arc::Graphical::setScores(const std::vector<std::pair<std::string, std::string>> &scores)
{
    static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->setScores(scores);
    static_cast<SceneEndGame *>(_scenes[END_GAME].get())->setScores(scores);
}

void arc::Graphical::setControls(const std::map<std::pair<Event::Type, Event::Key>, std::function<void ()>> &controls)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->setControls(controls);
}

/*
For the menu
*/
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
    static_cast<SceneGame *>(_scenes[GAME].get())->setFunctionMenu(function);
    static_cast<SceneEndGame *>(_scenes[END_GAME].get())->setFunctionMenu(function);
}

void arc::Graphical::setFunctionTogglePause(const std::function<void()> &function)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->setFunctionTogglePause(function);
}

void arc::Graphical::setGamePause(bool pause)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->setGamePause(pause);
}

/*
For the menu
*/
const std::string &arc::Graphical::getUsername()
{
    return (static_cast<SceneMenu *>(_scenes[MAIN_MENU].get())->getUsername());
}

/*
For the menu
*/
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
    _scenes[_actualScene]->init();
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
    static_cast<SceneGame *>(_scenes[GAME].get())->setMapSize(height, width);
}

void arc::Graphical::setGameTitle(const std::string &game)
{
    static_cast<SceneGame *>(_scenes[GAME].get())->setGameTitle(game);
}

extern "C" arc::IGraphical *instance_ctor()
{
    return (new arc::Graphical());
}