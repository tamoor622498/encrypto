#include "Phrase.h"

Phrase::Phrase() {
    cout << "Default constructor" << endl;
}

Phrase::Phrase(string text) {
    char puncMarks[] = " .,:;?()[]\"'.!/-_*";
    for (char i : text) {
        textVec.push_back(tolower(i));
    }

    for (char j : textVec) {
        bool dup = false;
        bool special = false;
        for (char nondup : nondups) {
            if (j == nondup){
               dup = true;
            }
        }

        for (int l = 0; l < 17; ++l) {
            if (j == puncMarks[l]){
                special = true;
            }
        }

        if (!dup && !special){
            nondups.push_back(j);
        }
    }
}

Phrase::~Phrase() {
    cout << "Destructor" << endl;
}

void Phrase::Display() {
    for (char i : textVec) {
        cout << i;
    }
    cout << endl;
    for (unsigned int j = 0; j < nondups.size(); ++j) {
        cout << nondups[j];
    }
    cout << endl;
}