#include <iostream>
#include <time.h>
#include <string>
using namespace std;

const char puncMarks[] = ".,:;?()[]\"'.!/-_*";

int main() {
    srand(time(nullptr));
    string st =  "Hello World";

    for (int i = 0; i < 17; ++i) {
        cout << i << " " << puncMarks[i] << endl;
    }

    return 0;
}