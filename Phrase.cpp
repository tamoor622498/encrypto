#include "Phrase.h"

Phrase::Phrase() {
    cout << "Default constructor" << endl;
}

Phrase::Phrase(string text) {
    for (unsigned int i = 0; i < text.length(); ++i) {
        textVec.push_back(tolower(text[i]));
    }

    for (unsigned int j = 0; j < textVec.size(); ++j) {
        bool dup = false;
        for (unsigned int k = 0; k < nondups.size(); ++k) {
            if (textVec[j] == nondups[k]){
               dup = true;
            }

        }
        if (!dup){
            nondups.push_back(textVec[j]);
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