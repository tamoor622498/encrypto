#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Phrase.h"
using namespace std;

const char puncMarks[] = " .,:;?()[]\"'.!/-_*";

int main() {
    srand(time(nullptr));

    Phrase* test = new Phrase("This is a Test!");

    test->Display();
    return 0;
}