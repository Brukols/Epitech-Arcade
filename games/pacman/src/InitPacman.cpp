/*
** EPITECH PROJECT, 2019
** Arcade - Pacman
** File description:
** InitPacman
*/

#include "Pacman.hpp"

// BLEU CLARE : 11 112 231
// ROSE : 244 158 280

void Pacman::initPacman()
{
    _start = std::chrono::system_clock::now();
    _end = std::chrono::system_clock::now();
    _title = "Pacman";
    _height = 11;
    _width = 20;
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
    initGhostBlinky();
    initGhostPinky();
    initGhostInky();
    initGhostClyde();
}

void Pacman::initGhostBlinky()
{
    std::shared_ptr<Entity> blinkyEntity(new Entity);
    blinkyEntity->type = ENEMY;
    blinkyEntity->spritePath = "./assets/pacman/blinky.png";
    // blinkyEntity->backgroundColor = Color{255, 4, 5, 255}; //Red
    blinkyEntity->orientation = Orientation::RIGHT;
    blinkyEntity->x = 8;
    blinkyEntity->y = 5;
    _entities.push_back(blinkyEntity);
    _blinky.push_back(blinkyEntity);
}

void Pacman::initGhostPinky()
{
    std::shared_ptr<Entity> pinkyEntity(new Entity);
    pinkyEntity->type = ENEMY;
    pinkyEntity->spritePath = "./assets/pacman/pinky.png";
    // pinkyEntity->backgroundColor = Color{244, 158, 250, 255}; //Pink
    pinkyEntity->orientation = Orientation::UP;
    pinkyEntity->x = 9;
    pinkyEntity->y = 5;
    _entities.push_back(pinkyEntity);
    _pinky.push_back(pinkyEntity);
}

void Pacman::initGhostInky()
{
    std::shared_ptr<Entity> inkyEntity(new Entity);
    inkyEntity->type = ENEMY;
    inkyEntity->spritePath = "./assets/pacman/inky.png";
    // inkyEntity->backgroundColor = Color{11, 12, 231, 255}; //Blue
    inkyEntity->orientation = Orientation::UP;
    inkyEntity->x = 10;
    inkyEntity->y = 5;
    _entities.push_back(inkyEntity);
    _inky.push_back(inkyEntity);
}

void Pacman::initGhostClyde()
{
    std::shared_ptr<Entity> clydeEntity(new Entity);
    clydeEntity->type = ENEMY;
    clydeEntity->spritePath = "./assets/pacman/clyde.png";
    // clydeEntity->backgroundColor = Color{243, 130, 2, 255}; //Orange
    clydeEntity->orientation = Orientation::LEFT;
    clydeEntity->x = 11;
    clydeEntity->y = 5;
    _entities.push_back(clydeEntity);
    _clyde.push_back(clydeEntity);
}

void Pacman::initMap()
{
    std::string readLine;
    int x = 0;
    int y = 0;
    std::ifstream mapFile("./games/pacman/map2.txt");  //On essaye d'ouvrir le fichier

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
                    mapEntity->backgroundColor = Color{30, 17, 149, 255};
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
    pacmanEntity->spritePath = "./assets/pacman/pacpacLeft.png";
    // pacmanEntity->backgroundColor = Color{250, 255, 1, 255};
    pacmanEntity->orientation = Orientation::LEFT;
    pacmanEntity->x = 9;
    pacmanEntity->y = 7;
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
    fruitEntity->spritePath = "./assets/pacman/cherry.png";
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