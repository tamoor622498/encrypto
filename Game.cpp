#include "Game.h"
#include "Phrase.h"

Game::Game(){
    auto *test = new Phrase("It is possible to commit no mistakes and still lose. That is not weakness, that is life.");
    levelsList.push_back(test);
    test = nullptr;
}

Game::~Game() {
    for (auto & i : levelsList) {
        delete i;
        i = nullptr;
    }
}

void Game::GameStart() {
    for (int i = 0; i < levelsList.size(); ++i) {
        cout << "Starting level " << i++ << ":" << endl;
        while (!(levelsList[i]->WinCheck())){

        }
    }
}