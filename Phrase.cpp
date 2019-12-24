#include "Phrase.h"

Phrase::Phrase() {
    cout << "Default constructor" << endl;
}

Phrase::Phrase(string text) {
    char puncMarks[] = " .,:;?()[]\"'.!/-_*";
    for (char i : text) {
        char c = tolower(i);
        textVec.emplace_back(1,c);
        //stirtextVec.emplace_back(1,c);
    }

    for (string j : textVec) {
        bool dup = false;
        bool special = false;

        for (auto & symbol : symbols)
        {
            if (j == get<0>(symbol)){
                dup = true;
            }
        }

        for (char l : puncMarks) {
            if (j == string(1,l)){
                special = true;
            }
        }

        if (!dup && !special){
            symbols.emplace_back(j,Encryption());
        }
    }
    Replacement();
}

Phrase::~Phrase() {
    cout << "Destructor" << endl;
}

void Phrase::Display() {
    for (string i : textVec) {
        cout << i;
    }
    cout << endl;

    for (auto & symbol : symbols)
    {
        cout << get<0>(symbol)<< get<1>(symbol);
    }
    cout << endl;

}

string Phrase::Encryption() {
    unsigned int i = rand()% (characters.size()) + 0;
    string sel = characters[i];
    characters.erase(characters.begin()+i);
    return sel;
}

void Phrase::Replacement() {
    for (int i = 0; i < textVec.size(); ++i) {

    }
}