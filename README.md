# Arcade

Arcade is a gaming platform that lets the user choose a game to play. He can also change the library in order to play to his game with other graphics. :video_game:

## Description

The goal of this project is to create a core who can manage different library (games and graphics) at run time. In order to deal with this, games and graphics must be dynamic library.

At the beginning, you can launch the core with a graphic library (in libs directory). You will arrive in a gaming platform.

This platform will let you choose the game that you want to play or the graphic you want to launch.

## Compilation

```bash
make # Compile core, games and graphics
make games # Compile the games
make graphicals # Compile the graphics
```

## Usage

You must to execute arcade with a graphic library. You are free to choose any library.

```bash
./arcade lib/lib_arcade_sfml.so # Run arcade with the sfml library
```

## Implementation of your own library

And of course, you can implement your own library (games, graphics or both). :smiley: To do that, I let you see our documentation in the doc directory.

## Contribution

This project has been done with :
- [Oriane Aumoite](https://github.com/noriae)
- Celeste Bousseau

Our project is compatible with the group of [jamil.ettel@epitech.eu](https://mail.google.com/mail/u/0/?view=cm&fs=1&to=jamil.ettel@epitech.eu&su=Message%20à%20Jamil%20et%20Benjamin&body=Vou%20ète%20bo%20les%20mec&tf=1) :two_hearts:

You can see his project [here](https://github.com/jamilettel/arcade).
