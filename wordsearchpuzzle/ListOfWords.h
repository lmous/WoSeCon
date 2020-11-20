/* 
 * File:   ListOfWords.h
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 *
 * Created on January 20, 2020, 11:47 AM
 */

#ifndef LISTOFWORDS_H
#define LISTOFWORDS_H
#include <vector>
#include "WordInfo.h"
using namespace std;
// Keeps the list of WordInfo objects whose contents should be placed on the board
class ListOfWords {
public:
    ListOfWords();
    ListOfWords(const ListOfWords& orig);
    virtual ~ListOfWords();
    vector<WordInfo> getList();
    
    //returns the WordInfo at index idx
    WordInfo get(int idx);
    int size() const;
private:
    vector<WordInfo> store;
};

#endif /* LISTOFWORDS_H */

