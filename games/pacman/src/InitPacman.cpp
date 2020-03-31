/*
** EPITECH PROJECT, 2019
** Arcade - Pacman
** File description:
** InitPacman
*/

#include "Pacman.hpp"

void Pacman::initPacman()
{
    srand (time(NULL));
    _start = std::chrono::system_clock::now();
    _end = std::chrono::system_clock::now();
    _title = "Pacman";
    // _height = 11;
    // _width = 20;
    _height = 30;
    _width = 40;
    _music = "";
    _sound = "";
    _score = 0;
    _nbCherry = 0;
    _nbPacGum = 0;
    initEntities();
    initVisualAssets();
    initControls();
    initGameControls();
    initGameStats();
}

void Pacman::initEntities()
{
    initMap();
    initPacpac();
    initCherry();
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
    blinkyEntity->backgroundColor = Color{255, 4, 5, 255}; //Red
    blinkyEntity->orientation = Orientation::UP;
    _blinkyDirection = Orientation::UP;
    blinkyEntity->x = 17;
    blinkyEntity->y = 14;
    _entities.push_back(blinkyEntity);
    _blinky.push_back(blinkyEntity);
}

void Pacman::initGhostPinky()
{
    std::shared_ptr<Entity> pinkyEntity(new Entity);
    pinkyEntity->type = ENEMY;
    pinkyEntity->spritePath = "./assets/pacman/pinky.png";
    pinkyEntity->backgroundColor = Color{244, 158, 250, 255}; //Pink
    pinkyEntity->orientation = Orientation::UP;
    _pinkyDirection = Orientation::UP;
    pinkyEntity->x = 18;
    pinkyEntity->y = 14;
    _entities.push_back(pinkyEntity);
    _pinky.push_back(pinkyEntity);
}

void Pacman::initGhostInky()
{
    std::shared_ptr<Entity> inkyEntity(new Entity);
    inkyEntity->type = ENEMY;
    inkyEntity->spritePath = "./assets/pacman/inky.png";
    inkyEntity->backgroundColor = Color{11, 12, 231, 255}; //Blue
    inkyEntity->orientation = Orientation::UP;
    _inkyDirection = Orientation::UP;
    inkyEntity->x = 19;
    inkyEntity->y = 14;
    _entities.push_back(inkyEntity);
    _inky.push_back(inkyEntity);
}

void Pacman::initGhostClyde()
{
    std::shared_ptr<Entity> clydeEntity(new Entity);
    clydeEntity->type = ENEMY;
    clydeEntity->spritePath = "./assets/pacman/clyde.png";
    clydeEntity->backgroundColor = Color{243, 130, 2, 255}; //Orange
    clydeEntity->orientation = Orientation::UP;
    _clydeDirection = Orientation::UP;
    clydeEntity->x = 20;
    clydeEntity->y = 14;
    _entities.push_back(clydeEntity);
    _clyde.push_back(clydeEntity);
}

void Pacman::initMap() //init _myMap and _pacGum
{
    std::ifstream mapFile("./games/pacman/map3.txt");
    std::string readLine;
    int x = 0;
    int y = 0;

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
                if (readLine[x] == '0') {
                    std::shared_ptr<Entity> pacGumEntity(new Entity);
                    pacGumEntity->type = CONSUMABLE;
                    pacGumEntity->spritePath = "./assets/pacman/pacGum.png";
                    pacGumEntity->backgroundColor = Color{30, 17, 149, 255};
                    pacGumEntity->orientation = Orientation::LEFT;
                    pacGumEntity->x = x;
                    pacGumEntity->y = y;
                    _entities.push_back(pacGumEntity);
                    _pacGum.push_back(pacGumEntity);
                }
                if (readLine[x] == '*') {
                    std::shared_ptr<Entity> SpecialPacGumEntity(new Entity);
                    SpecialPacGumEntity->type = CONSUMABLE;
                    SpecialPacGumEntity->spritePath = "./assets/pacman/SpecialPacGum.png";
                    SpecialPacGumEntity->backgroundColor = Color{30, 17, 149, 255};
                    SpecialPacGumEntity->orientation = Orientation::LEFT;
                    SpecialPacGumEntity->x = x;
                    SpecialPacGumEntity->y = y;
                    _entities.push_back(SpecialPacGumEntity);
                    _SpecialPacGum.push_back(SpecialPacGumEntity);
                }
                x++;
            }
            y++;
        }
        mapFile.close();
    } else {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }
    _myMap.size();
    // std::cout << _myMap.size() << std::endl;
}

void Pacman::initPacpac()
{
    std::shared_ptr<Entity> pacmanEntity(new Entity);
    pacmanEntity->type = PLAYER;
    pacmanEntity->spritePath = "./assets/pacman/pacpacUp.png";
    pacmanEntity->backgroundColor = Color{250, 255, 1, 255};
    pacmanEntity->orientation = Orientation::LEFT;
    pacmanEntity->x = 20;
    pacmanEntity->y = 16;
    _entities.push_back(pacmanEntity);
    _pacman.push_back(pacmanEntity);
}

void Pacman::initCherry()
{
    // std::cout << "r" << std::endl;
    int r = rand () % _pacGum.size();
    // std::cout << "r" << r << std::endl;

    std::shared_ptr<Entity> fruitEntity(new Entity);
    fruitEntity->type = CONSUMABLE;
    fruitEntity->spritePath = "./assets/pacman/cherry.png";
    fruitEntity->backgroundColor = Color{227, 18, 18, 255};
    fruitEntity->orientation = Orientation::LEFT;

    fruitEntity->x = _pacGum[r - 1]->x;
    fruitEntity->y = _pacGum[r - 1]->y;
    
    _entities.push_back(fruitEntity);
    _cherry.push_back(fruitEntity);
}

void Pacman::initVisualAssets()
{
    // _visualAssets['a'] = std::pair<std::string, Color> ("", Color{227, 18, 18, 255});
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
    _gameControls.clear();
    _gameControls.push_back(std::pair<std::string, std::string> ("UP ARROW", "Go up"));
    _gameControls.push_back(std::pair<std::string, std::string> ("RIGHT ARROW", "Go right"));
    _gameControls.push_back(std::pair<std::string, std::string> ("DOWN ARROW", "Go down"));
    _gameControls.push_back(std::pair<std::string, std::string> ("LEFT ARROW", "Go left"));
}

void Pacman::initGameStats()
{
    _gameStats.clear();
    _gameStats.push_back(std::pair<std::string, std::string> ("Score", std::to_string(_score)));
    _gameStats.push_back(std::pair<std::string, std::string> ("Cherry", std::to_string(_nbCherry)));
}