#include "Game.h"
#include "Phrase.h"

Game::Game(){
    auto *test = new Phrase("It is possible to commit no mistakes and still lose. That is not weakness, that is life.");
    levelsList.push_back(test);
}

Game::~Game() {
    for (auto & i : levelsList) {
        delete i;
    }

}