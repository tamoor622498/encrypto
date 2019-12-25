#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Phrase.h"

using namespace std;

int main() {

    auto *test = new Phrase("It is possible to commit no mistakes and still lose. That is not weakness, that is life.");
    //test->Display();
    tuple<int,string> t = test->Menu();
    cout<< "input: " << get<0>(t)+1 << get<1>(t) << endl;
    delete test;

    return 0;
}