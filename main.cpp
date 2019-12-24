#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Phrase.h"

using namespace std;

int main() {

    Phrase* test = new Phrase("This is a Test!");
    test->Display();
    test->Encryption();
    delete test;

    return 0;
}