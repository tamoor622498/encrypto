#include "Phrase.h"

Phrase::Phrase() {
    cout << "Default constructor" << endl;
}

Phrase::Phrase(const string &text) {
    char puncMarks[] = " .,:;?()[]\"'.!/-_*#";
    for (char i : text) {
        char c = tolower(i);
        textVec.emplace_back(1, c);
    }

    for (const string &j : textVec) {
        bool dup = false;
        bool special = false;

        for (auto &symbol : symbols) {
            if (j == get<0>(symbol)) {
                dup = true;
            }
        }

        for (char l : puncMarks) {
            if (j == string(1, l)) {
                special = true;
            }
        }

        if (!dup && !special) {
            symbols.emplace_back(j, Encryption());
        }
    }
    Encryption();
    Replacement();
}

Phrase::~Phrase() {
    cout << "Destructor" << endl;
}

void Phrase::Display() {
    for (const string &i : textVec) {
        cout << i;
    }
    cout << endl;

    for (auto &symbol : symbols) {
        cout << get<0>(symbol)<< '\t' << get<1>(symbol);
        cout << endl;
    }
    //cout << endl;

}

string Phrase::Encryption() {
    unsigned int i = rand() % (characters.size()) + 0;
    string sel = characters[i];
    characters.erase(characters.begin() + i);
    return sel;
}

void Phrase::Replacement() {
    for (auto &t : textVec) {
        for (auto &symbol : symbols) {
            if (t == get<0>(symbol)) {
                t = get<1>(symbol);
            }
        }
    }
}