#include "Phrase.h"
#include <utility>

Phrase::Phrase() {
    cout << "Default constructor" << endl;
}

Phrase::Phrase(const string &text, const string &auth) {
    author = auth;
    input = text;
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
            string sym = SymSel();
            symbols.emplace_back(j, sym);
            userEdit.emplace_back(sym, sym);
        }
    }
    SymSel();
    Encryption();
}

Phrase::~Phrase() {
    //cout << "Destructor" << endl;
}

void Phrase::Display() {
    for (const string &i : textVec) {
        cout << i;
    }
    cout << " -" << GetAuthor() << endl;

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
        if (get<0>(symbols[i]) != get<0>(userEdit[i])) {
            win = false;
        }
    }
    return win;
}

tuple<int, string> Phrase::Menu() {
    tuple<int, string> cPick;
    char cSel;
    make_tuple(0, " ");
    do {
        cout << "Select character to replace:" << endl;
        for (int i = 0; i < userEdit.size(); ++i) {
            cout << i + 1 << '\t' << get<1>(userEdit[i]) << endl;
        }
        cin >> get<0>(cPick);
    } while ((get<0>(cPick) < 1) || (get<0>(cPick) > symbols.size()));
    get<0>(cPick)--;
    cout << "Enter replacement character:" << endl;
    cin >> cSel;
    cSel = _tolower(cSel);
    get<1>(cPick) = string(1, cSel);
    return cPick;
}

void Phrase::Decryption(tuple<int, string> userSel) {
    get<0>(userEdit[get<0>(userSel)]) = get<1>(userSel);
    for (auto &i : textVec) {
        if (i == get<1>(userEdit[get<0>(userSel)])) {
            i = get<1>(userSel);
        }
    }
    get<1>(userEdit[get<0>(userSel)]) = get<1>(userSel);
}

void Phrase::SetAuthor(string auth) {
    author = move(auth);
}

string Phrase::GetAuthor() {
    return author;
}

string Phrase::GetInput() {
    return input;
}
