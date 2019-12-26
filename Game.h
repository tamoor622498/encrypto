#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <tuple>
#include "Phrase.h"

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game();
    //Constructor

    ~Game();
    //Destructor

    void GameStart();
    //Starts game;

    void Display();
    //displays list

private:
    vector<Phrase *> levelsList;
};

#endif