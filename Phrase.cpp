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
            symbols.emplace_back(j, SymSel());
            userEdit.emplace_back(" ", SymSel());
        }
    }
    SymSel();
    Encryption();
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

string Phrase::SymSel() {
    unsigned int i = rand() % (characters.size()) + 0;
    string sel = characters[i];
    characters.erase(characters.begin() + i);
    return sel;
}

void Phrase::Encryption() {
    for (auto &t : textVec) {
        for (auto &symbol : symbols) {
            if (t == get<0>(symbol)) {
                t = get<1>(symbol);
            }
        }
    }
}

bool Phrase::WinCheck() {
    bool win = true;
    for (int i = 0; i < symbols.size(); ++i) {
        if (get<0>(symbols[i]) != get<0>(userEdit[i])){
            win = false;
        }
    }
    return win;
}

tuple<int,string> Phrase::Menu() {
    tuple <int, string> cPick;
    char cSel;
    make_tuple(0," ");
    do{
        cout << "Select character to replace:" <<endl;
        for (int i = 0; i < symbols.size(); ++i) {
            cout << i+1 << '\t' << get<1>(symbols[i]) << endl;
        }
        cin >> get<0>(cPick);
    } while ((get<0>(cPick) < 1) || (get<0>(cPick) > symbols.size()));
    get<0>(cPick)--;
    cout << "Enter replacement character:" << endl;
    cin >> cSel;
    cSel = _tolower(cSel);
    get<1>(cPick) = string(1,cSel);
    return cPick;
}

void Phrase::Decryption(tuple<int,string> userSel) {
    get<0>(userEdit[get<0>(userSel)]) = get<1>(userSel);
    for (auto &t : textVec) {
        for (auto &change : userEdit) {
            if (t == get<0>(change)) {
                t = get<1>(change);
            }
        }
    }
}