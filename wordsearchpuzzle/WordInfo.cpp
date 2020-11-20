/* 
 * File:   WordInfo.cpp
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 * 
 * Created on January 20, 2020, 10:11 AM
 */
#include "WordInfo.h"
#include "Settings.h"
#include "RandomLocator.h"

WordInfo::WordInfo(string word) {
    content = word;
    testedLocations={};
}

WordInfo::WordInfo(const WordInfo& orig) {
    content = orig.content;
    placement = orig.placement;
    testedLocations = orig.testedLocations;
}

WordInfo::~WordInfo() {
    testedLocations.clear();
}

string WordInfo::getContent() const {
    return content;
}

DirectedLocation WordInfo::getPlacement() {
    return placement;
}

vector<DirectedLocation> WordInfo::getTested() const {
    return testedLocations;
}

void WordInfo::setPlacement(const DirectedLocation& dL) {
    placement = dL;
}

void WordInfo::deleteTested() {
    testedLocations.clear();
}

void WordInfo::addToTested() {
    testedLocations.push_back(placement);
    placement=DirectedLocation::nullLocation;
}

vector<DirectedLocation> WordInfo::getAllLocations() const {
    vector<DirectedLocation> rVal;
    if (placement == DirectedLocation::nullLocation) return {};
    
    int line = placement.getRow();
    int clmn = placement.getColumn();
    if (placement.getDirection() == wordSearchPuzzle_Directions::wordSearchPuzzle_HORIZONTAL) {
        for (int i = 0; i < content.length(); i++) {
            DirectedLocation d(line, clmn+i, wordSearchPuzzle_Directions::wordSearchPuzzle_HORIZONTAL);
            rVal.push_back(d);
        }
    } else {
        for (int i = 0; i < content.length(); i++) {
            DirectedLocation d(line + i, clmn, wordSearchPuzzle_Directions::wordSearchPuzzle_VERTICAL);
            rVal.push_back(d);
        }
    }
    return rVal;
}

bool WordInfo::operator==(const WordInfo& w) const {
    return this->content == w.content;
}

char WordInfo::charAt(DirectedLocation loc) const {
        if (this->placement.getDirection() == wordSearchPuzzle_Directions::wordSearchPuzzle_HORIZONTAL) {
            return content[loc.getColumn() - placement.getColumn()];
        } else {
            return content[loc.getRow() - placement.getRow()];
        }
    }


bool WordInfo::conflict(const WordInfo* w) const {
    vector<DirectedLocation> w1Ls = getAllLocations();
    vector <DirectedLocation> w2Ls = w->getAllLocations();
    if (w2Ls.empty())
        return false;
    for (const DirectedLocation& l1 : w1Ls) {
        for (const DirectedLocation& l2 : w2Ls) {
            if (l1==l2)                 
                    return true;
            if (l1.getRow()==l2.getRow() && l1.getColumn()==l2.getColumn() && l1.getDirection()!=l2.getDirection())
                if (charAt(l2) != w->charAt(l2)) return true;
            }
        }
    return false;
}