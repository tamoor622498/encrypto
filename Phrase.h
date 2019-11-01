#include <string>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

#ifndef PHRASE_H
#define PHRASE_H

class Phrase{
    public:

    Phrase();
    //Default constructor
    Phrase(string input);
    //Overloaded Constructor
    ~Phrase();
    //Destructor
    void Display();
    //Just displays the text.

    private:

    vector<char> textVec;
    vector<char> nondups;
};

#endif