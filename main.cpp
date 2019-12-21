#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Phrase.h"
using namespace std;

const char puncMarks[] = " .,:;?()[]\"'.!/-_*";

int main() {
    //srand(time(nullptr));

    Phrase* test = new Phrase("This is a Test!");
    test->Display();
    delete test;

    cout << "\u0444";

    for (int i=0; i<100; i++){
        char p = (char)rand()%100+900;
        string q = &"\\u" [ p];
        cout << q;
    }

    return 0;
}