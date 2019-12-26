#include "Game.h"
#include "Phrase.h"

Game::Game() {
    //auto *test = new Phrase("It is possible to commit no mistakes and still lose. That is not weakness, that is life.");
    //levelsList.push_back(test);
    //test = nullptr;
    fstream levels;
    levels.open("../Phrases.txt");
    string text;
    string auth;
    Phrase *newPhrase;
    while (getline(levels, text, '#')) {
        getline(levels, auth);
        newPhrase = new Phrase(text, auth);
        levelsList.push_back(newPhrase);
    }
    newPhrase = nullptr;
    levels.close();
}

Game::~Game() {
    for (auto &i : levelsList) {
        delete i;
        i = nullptr;
    }
}

void Game::GameStart() {
    for (int i = 0; i < levelsList.size(); ++i) {
        cout << "Starting level " << i + 1 << ":" << endl;
        while (!(levelsList[i]->WinCheck())) {
            levelsList[i]->Display();
            tuple<int, string> change = levelsList[i]->Menu();
            levelsList[i]->Decryption(change);
        }
        cout << "You win!" << endl;
    }
}

void Game::Display() {
    for (auto &i : levelsList) {
        cout << i->GetInput() << '\n' << i->GetAuthor() << endl;
    }
}
