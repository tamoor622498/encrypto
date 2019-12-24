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

        for (auto & symbol : symbols)
        {
            if (j == get<0>(symbol)){
                dup = true;
            }
        }

        for (char l : puncMarks) {
            if (j == l){
                special = true;
            }
        }

        if (!dup && !special){
            symbols.emplace_back(j,Encryption());
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

    for (auto & symbol : symbols)
    {
        cout << get<0>(symbol) << get<1>(symbol);
    }
    cout << endl;
}

string Phrase::Encryption() {
    unsigned int i = rand()% (characters.size()) + 0;
    string sel = characters[i];
    characters.erase(characters.begin()+i);
    return sel;
}