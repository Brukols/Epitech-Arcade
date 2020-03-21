/*
** EPITECH PROJECT, 2019
** Arcade - Pacman
** File description:
** InitPacman
*/

#include "Pacman.hpp"

void Pacman::initPacman()
{
    _start = std::chrono::system_clock::now();
    _end = std::chrono::system_clock::now();
    _title = "Pacman";
    // _height = 36;
    // _width = 48;
    _height = 11;
    _width = 11;
    _music = "";
    _sound = "";
    _score = 0;
    _nbApple = 0;
    initEntities();
    initVisualAssets();
    initControls();
    initGameControls();
    initGameStats();
}

void Pacman::initEntities()
{
    initPacpac();
    initApple();
    initMap();
    // initFruits();
    initGhostClyde();
}

void Pacman::initGhostClyde()
{
    std::shared_ptr<Entity> clydeEntity(new Entity);
    clydeEntity->type = ENEMY;
    clydeEntity->spritePath = "";
    clydeEntity->backgroundColor = Color{225, 127, 0, 255};
    clydeEntity->orientation = Orientation::RIGHT;
    clydeEntity->x = _width / 4;
    clydeEntity->y = _height / 8;
    _entities.push_back(clydeEntity);
    _clyde.push_back(clydeEntity);
}

void Pacman::initMap()
{
    std::string readLine;
    int x = 0;
    int y = 0;
    std::ifstream mapFile("./games/pacman/map.txt");  //On essaye d'ouvrir le fichier

    if(mapFile)
    {
         while(getline(mapFile, readLine)) //not end of file
        {
            x = 0;
            for (std::string::iterator it = readLine.begin(); it!=readLine.end(); ++it) {
                if (readLine[x] == '1') {
                    std::shared_ptr<Entity> mapEntity(new Entity);
                    mapEntity->type = OBSTACLE;
                    mapEntity->spritePath = "";
                    mapEntity->backgroundColor = Color{25, 25, 166, 255};
                    mapEntity->orientation = Orientation::LEFT;
                    mapEntity->x = x;
                    mapEntity->y = y;
                    _entities.push_back(mapEntity);
                    _myMap.push_back(mapEntity);
                }
                x++;
            }
            y++;
        }
        mapFile.close();
    } else {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }
}

void Pacman::initPacpac()
{
    std::shared_ptr<Entity> pacmanEntity(new Entity);
    pacmanEntity->type = PLAYER;
    pacmanEntity->spritePath = "";
    pacmanEntity->backgroundColor = Color{255, 228, 58, 255};
    pacmanEntity->orientation = Orientation::LEFT;
    pacmanEntity->x = _width / 2;
    pacmanEntity->y = _height / 2;
    _entities.push_back(pacmanEntity);
    _pacman.push_back(pacmanEntity);
}

void Pacman::initApple()
{
    float random_x = rand () % _width;
    float random_y = rand () % _height;

    while (isOnSnake(random_x, random_y) == true) {
        random_x = rand () % _width;
        random_y = rand () % _height;
    }
    std::shared_ptr<Entity> fruitEntity(new Entity);
    fruitEntity->type = CONSUMABLE;
    fruitEntity->spritePath = "";
    fruitEntity->backgroundColor = Color{227, 18, 18, 255};
    fruitEntity->orientation = Orientation::LEFT;
    fruitEntity->x = random_x;
    fruitEntity->y = random_y;
    _entities.push_back(fruitEntity);
    _apple.push_back(fruitEntity);
}

void Pacman::initVisualAssets()
{
    _visualAssets['a'] = std::pair<std::string, Color> ("", Color{227, 18, 18, 255});
}

void Pacman::initControls()
{
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::LEFT)] = [this]() -> void {
        _pacman.front()->orientation = Orientation::LEFT;
    };
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::RIGHT)] = [this]() -> void {
        _pacman.front()->orientation = Orientation::RIGHT;
    };
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::UP)] = [this]() -> void {
        _pacman.front()->orientation = Orientation::UP;
    };
    _controls[std::pair<Event::Type, Event::Key>(Event::KEY_PRESSED, Event::DOWN)] = [this]() -> void {
        _pacman.front()->orientation = Orientation::DOWN;
    };
}

void Pacman::initGameControls()
{
    _gameControls.push_back(std::pair<std::string, std::string> ("UP ARROW", "Go up"));
    _gameControls.push_back(std::pair<std::string, std::string> ("RIGHT ARROW", "Go right"));
    _gameControls.push_back(std::pair<std::string, std::string> ("DOWN ARROW", "Go down"));
    _gameControls.push_back(std::pair<std::string, std::string> ("LEFT ARROW", "Go left"));
}

void Pacman::initGameStats()
{
    _gameStats.clear();
    _gameStats.push_back("Score: " + std::to_string(_score));
    _gameStats.push_back("Apple: " + std::to_string(_nbApple));
}