#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <tuple>
using namespace std;

#ifndef PHRASE_H
#define PHRASE_H

class Phrase{
    public:

    Phrase();
    //Default constructor
    Phrase(string input);
    //Overloaded Constructor
    //and process's the string
    ~Phrase();
    //Destructor
    void Display();
    //Just displays the text.

    void Encryption();
    //Finds the symbols to use

    private:
    vector<char> textVec;
    vector<tuple<char,string>> symbols;
};

#endif