/* 
 * File:   Words.cpp
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 * 
 * Created on January 20, 2020, 12:23 PM
 */

#include "Words.h"
#include "WordInfo.h"
#include <iostream>
#include <fstream>
#include "Settings.h"
using namespace std;

//loads words from file with fileName
Words::Words() {
    noOfWords = count(wordSearchPuzzle_fileName);
    if (wordSearchPuzzle_test) cout << "No Of Words :" << noOfWords << endl; 
    ifstream input(wordSearchPuzzle_fileName);
    words = new string[noOfWords];
    int i = 0;
    for (std::string line; getline(input, line);) {
        words[i++] = line;
    }

}

//count words in file with fileName
 int Words::count(string fName) {
    int aNumOfLines = 0;
    ifstream aInputFile(fName);

    string aLineStr;
    while (getline(aInputFile, aLineStr)) {
        if (!aLineStr.empty())
            aNumOfLines++;
    }

    return aNumOfLines;
}

 
int Words::size() {
    return noOfWords;
}

//returns word at i index
string Words::get(int idx) {
    return words[idx];
}

Words::~Words() {
   delete [] words;
}

//returns a string representation of the words to be located
// used for debugging 
string Words::toString() {
    string rVal = "";
    for (int i = 0; i < size(); i++)
        rVal += (words[i] + " ");
    return rVal;
}

