#include "Phrase.h"

Phrase::Phrase() {
    cout << "Default constructor" << endl;
}

Phrase::Phrase(string text) {
    for (unsigned int i = 0; i < text.length(); ++i) {
        textVec.push_back(text[i]);
    }

    for (int j = 0; j < text.length(); ++j) {
        cout << j << endl;
        bool dup = false;
        for (unsigned int k = 0; k < nondups.size(); ++k) {
            if (text[j] == nondups[k]){
               dup = true;
            }

        }
        if (!dup){
            nondups.push_back(text[j]);
        }
    }
}

Phrase::~Phrase() {
    cout << "Destructor" << endl;
}

void Phrase::Display() {
    for (unsigned int i = 0; i < textVec.size(); ++i) {
        cout << textVec[i];
    }
    cout << endl;
    for (unsigned int j = 0; j < nondups.size(); ++j) {
        cout << nondups[j];
    }
}