/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WoSeCon.h
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 *
 * Created on January 21, 2020, 6:35 AM
 */

#ifndef WOSECON_H
#define WOSECON_H
#include <vector>
#include "WordInfo.h"
#include "Settings.h"
#include "RandomLocator.h"
#include "ListOfWords.h"
#include "Board.h"
#include "Statistics.h"

using namespace std;

class WoSeCon {
    //This class implements algorithm WoSeCon. 
public:
    WoSeCon();
    WoSeCon(const WoSeCon& orig);
    virtual ~WoSeCon();
    
    // This method constructs the word search puzzle and returns the board with the words located
    // This method is explained in detail in the paper
    Board construct(Statistics& stats);
    
    // checks if cWord can be located successfully. It is explained in detail in the paper
    bool locateOne(WordInfo* cWord);
    
    //Runs if construction with the given set of words and dimensions of the board is impossible
    void fail();
    
    //It considers as valid a placement if the content is placed such that it does not exceed the limits of the game board 
    //and does not overlap with any other word or it overlaps on a joint letter. 
    //Besides, the validPlacement updates the placement information of the current cWord
    bool validPlacement(WordInfo* cWord, DirectedLocation dL);
private:
    vector<WordInfo> listOfWords;
    wordSearchPuzzle_OperationMode operationMode;
    //static RandomLocator globalLocator;
    RandomLocator globalLocator;
};

#endif /* WOSECON_H */

