#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Phrase.h"
#include "Game.h"

using namespace std;

int main() {
    Game* test = new Game();
    //test->GameStart();
    test->Display();
    delete test;
    return 0;
}