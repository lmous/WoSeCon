/* 
 * File:   WordInfo.h
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 *
 * Created on January 20, 2020, 10:11 AM
 */

#ifndef WORDINFO_H
#define WORDINFO_H

#include <string>
#include "RandomLocator.h"
#include "DirectedLocation.h"
#include<vector>
using namespace std;

/*
 A WordInfo keeps three types of information: First is the content, which is a string that represents the word itself. 
 * Next is the placement, which is a DirectedLocation that keeps the position of the first letter of this word in the game board 
 * and the direction of the content layout. If this word has not been placed, then placement is nullLocation. 
 * Note that the content, together with the placement is sufficient to represent the placement of the content in the game board. 
 * Finally, a WordInfo keeps a list of DirectedLocations called tested locations. 
 */

class WordInfo {
public:
    WordInfo(string word);
    WordInfo(const WordInfo& orig);
    virtual ~WordInfo();
    string getContent() const;
    DirectedLocation getPlacement();
    vector<DirectedLocation> getTested() const;
    // sets the placement for the first letter of this object's content
    void setPlacement(const DirectedLocation& dL);
    //delete tested locations
    void deleteTested();
    //update tested locations and set placement to nullLocation
    void addToTested();
    //returns all DirectedLocations that this object content occupies
    vector<DirectedLocation> getAllLocations() const;
    bool operator==(const WordInfo& w) const;
    // checks if this object content is located such as it conflicts with another WordInfo
    bool conflict(const WordInfo* w) const;
    
private:
    string content;
    DirectedLocation placement;
//    when the algorithm operates in the backward mode in order to reposition word at index i-1, 
//    the tested locations of the word i should be deleted, and the tested locations of word i-1 should be updated
    vector<DirectedLocation> testedLocations;
    //used from conflict to check if overlapping characters are equal
    char charAt(DirectedLocation loc) const;
};

#endif /* WORDINFO_H */

