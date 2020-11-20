/* 
 * File:   RandomLocator.cpp
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 * 
 * Created on January 18, 2020, 10:15 AM
 */

#include "RandomLocator.h"
#include "DirectedLocation.h"
#include "Settings.h"
#include <iostream>
#include <algorithm>


using namespace std;

RandomLocator::RandomLocator() {

    for (int d = wordSearchPuzzle_Directions::wordSearchPuzzle_HORIZONTAL; d <= wordSearchPuzzle_Directions::wordSearchPuzzle_VERTICAL; d++)
        for (int c = 0; c < wordSearchPuzzle_boardClmns; c++)
            for (int l = 0; l < wordSearchPuzzle_boardLines; l++)
                if (!((d == wordSearchPuzzle_Directions::wordSearchPuzzle_HORIZONTAL && c == wordSearchPuzzle_boardClmns - 1)
                        || (d == wordSearchPuzzle_Directions::wordSearchPuzzle_VERTICAL && l == wordSearchPuzzle_boardLines - 1))) {
                    DirectedLocation dL(l, c, d);
                    add(dL);
                }

    random_shuffle(store.begin(), store.end());
}

RandomLocator::RandomLocator(const RandomLocator& orig) {
    for (int i=0; i<orig.size(); i++)
    store.push_back(orig.store[i]);
}

RandomLocator::~RandomLocator() {
    store.clear();
}


DirectedLocation RandomLocator::get(int idx) const {
    return store[idx];
}


void RandomLocator::add(const DirectedLocation& dL) {
    store.push_back(dL);
}


void RandomLocator::remove(const DirectedLocation& loc) {
    for (vector<DirectedLocation>::iterator iter = store.begin(); iter != store.end(); ++iter) {
        if (*iter == loc) {
            store.erase(iter);
            return;
        }
    }
}

int RandomLocator::size() const {
    return store.size();
}


RandomLocator RandomLocator::minus(const vector<DirectedLocation>& visited) {
    RandomLocator rVal;
    for (int i = 0; i < visited.size(); i++)
        rVal.remove(visited[i]);
    return rVal;
}


