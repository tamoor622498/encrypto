#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "Phrase.h"
using namespace std;

//const char puncMarks[] = " .,:;?()[]\"'.!/-_*";
string characters[] = {"\u00A2", "\u00A3", "\u00A5", "\u00A7", "\u00B5",\
"\u00C2", "\u00C6", "\u00D0", "\u00D8", "\u00DF", "\u00E6", "\u0152", "\u0190",\
"\u0192", "\u019B", "\u019E", "\u01A2", "\u01A9", "\u01B1", "\u01B5", "\u01B8",\
"\u023D", "\u024E", "\u0278", "\u03A0", "\u03A8", "\u03B1", "\u03E0", "\u03DF",\
"\u0460", "\u0468", "\u0488", "\u058D", "\u06DE", "\u06E9", "\u07D0", "\u07F7",\
"\u09CB", "\u0BF5", "\u0CF1", "\u0DF4", "\u0FCA", "\u1029", "\u1109", "\u1112",\
"\u113D", "\u1360", "\u1368", "\u13C9", "\u13EB", "\u1408", "\u14EC", "\u15D2",\
"\u15DC", "\u168F", "\u16E4" };

int main() {
    //srand(time(nullptr));

    Phrase* test = new Phrase("This is a Test!");
    test->Display();
    delete test;

        for (const auto & character : characters) {
            cout << character;
        }
    return 0;
}