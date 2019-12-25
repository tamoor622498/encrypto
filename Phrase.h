#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <tuple>

using namespace std;

#ifndef PHRASE_H
#define PHRASE_H

class Phrase {
public:
    Phrase();
    //Default constructor
    explicit Phrase(const string &input);
    //Overloaded Constructor
    //and process's the string
    ~Phrase();
    //Destructor
    void Display();
    //Just displays the text.
    string SymSel();
    //Finds the symbols to use
    void Encryption();
    //Replaces characters with symbols
    bool WinCheck();
    //Checks if the player won;
    tuple<int,string> Menu();
    //Menu for user selection
    void Decryption(tuple<int,string>);


private:
    vector<string> textVec;
    vector<tuple<string, string>> userEdit;
    vector<tuple<string, string>> symbols;
    vector<string> characters = {"\u00A2", "\u00A3", "\u00A5", "\u00A7", "\u00B5", \
"\u00C2", "\u00C6", "\u00D0", "\u00D8", "\u00DF", "\u00E6", "\u0152", "\u0190", \
"\u0192", "\u019B", "\u019E", "\u01A2", "\u01A9", "\u01B1", "\u01B5", "\u01B8", \
"\u023D", "\u024E", "\u0278", "\u03A0", "\u03A8", "\u03B1", "\u03E0", "\u03DF", \
"\u0460", "\u0468", "\u0488", "\u058D", "\u06DE", "\u06E9", "\u07D0", "\u07F7", \
"\u09CB", "\u0BF5", "\u0CF1", "\u0DF4", "\u0FCA", "\u1029", "\u1109", "\u1112", \
"\u113D", "\u1360", "\u1368", "\u13C9", "\u13EB", "\u1408", "\u14EC", "\u15D2", \
"\u15DC", "\u168F", "\u16E4", "\u15D5", "\u15D6", "\u15D7", "\u16DE", "\u1C6F", \
"\u1C6A", "\u2029", "\u20E0", "\u2182", "\u21B9", "\u21BA", "\u21BB", \
"\u21CB", "\u21EF", "\u21F6", "\u2230", "\u22A1", "\u2317", "\u2318", "\u231A", \
"\u2658", "\u269C", "\u26C9", "\u27DB", "\u2995", "\uA087", "\uA154", "\uA51E"}; //page 165
};

#endif