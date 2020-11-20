/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 *
 * Created on January 23, 2020, 10:00 AM
 */

#ifndef BOARD_H
#define BOARD_H
#include "WordInfo.h"
// An Object of this class is returned as the result of WoSeCon
// It represents the board of a word search puzzle after all words have been located

class Board {
public:
    Board(vector<WordInfo> listOfWords);
    Board(const Board& orig);
    virtual ~Board();
    
    //return character at position row,column
    char get(int row, int column) const;
       
    //prints the Board
    void print();
    
    //print statistics relative to the construction.
    //It is invoked when test equals true
    void printStats();
    
    // returns word characters in the board divided by board dimension
    double getPOccupied();
private:
    char** board;
};

#endif /* BOARD_H */

