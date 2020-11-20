/* 
 * File:   ListOfWords.cpp
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 * 
 * Created on January 20, 2020, 11:47 AM
 */

#include "ListOfWords.h"
#include "Words.h"
#include <iostream>
using namespace std;

ListOfWords::ListOfWords() {
    Words words;

    for (int i = 0; i < words.size(); i++) {
        WordInfo wI(words.get(i));
        store.push_back(wI);
    }
}

ListOfWords::ListOfWords(const ListOfWords& orig) {
    for (int i = 0; i < orig.store.size(); i++)
        store.push_back(orig.store[i]); 
}

ListOfWords::~ListOfWords() {
    store.clear();
}


int ListOfWords::size() const {
    return store.size();
}
vector<WordInfo> ListOfWords::getList() {
    return store;
}

WordInfo ListOfWords::get(int idx) {
    return store[idx];
}