#include "Game.h"

#include <random>
#include "Phrase.h"

Game::Game() {
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
    shuffle(levelsList.begin(), levelsList.end(), std::mt19937(std::random_device()()));
}

Game::~Game() {
    for (auto &i : levelsList) {
        delete i;
        i = nullptr;
    }
}

void Game::GameStart() {
    tuple<int, string> change;
    get<0>(change) = 0;
    for (int i = 0; i < levelsList.size(); ++i) {
        cout << "Starting level " << i + 1 << ":" << endl;
        while ((!levelsList[i]->WinCheck()) && (get<0>(change) != 1000)) {
            levelsList[i]->Display();
            change = levelsList[i]->Menu();
            if (get<0>(change) != 1000){
                if (get<1>(change) == "ʭ"){
                    cout << "You can't repeat characters" << endl;
                } else {
                    levelsList[i]->Decryption(change);
                }
            }
        }
        if (get<0>(change) != 1000){
            cout << levelsList[i]->GetInput() << endl;
            cout << "You win!" << endl;
        } else {
            cout << "Thank you for playing!" << endl;
            break;
        }
    }
}

void Game::Display() {
    for (auto &i : levelsList) {
        cout << i->GetInput() << '\n' << i->GetAuthor() << endl;
    }
}
