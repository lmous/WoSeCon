/* 
 * File:   Words.h
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 *
 * Created on January 20, 2020, 12:23 PM
 */

#ifndef WORDS_H
#define WORDS_H
#include <string>
using namespace std;
/* Class Words load the words from file with name fileName.
   fileName is declared in Settings.h */

class Words {
public:
    Words();
    virtual ~Words();
    int size();
    string get(int idx);
    string toString();
private:
    string *words;
    int noOfWords;
    int count(string fName);

};

#endif /* WORDS_H */

