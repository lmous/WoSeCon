/* 
 * File:   Board.cpp
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 * 
 * Created on January 23, 2020, 10:00 AM
 */

#include "Board.h"
#include "Settings.h"
#include "DirectedLocation.h"
#include <iostream>
using namespace std;

Board::Board(vector<WordInfo> listOfWords) {
    //creates board, a BOARDLINESxBOARDCLMNS dynamic array of characters
    //input: a list of WordInfo objects. Each WordInfo keeps information for its content placement on the Board
    // It initializes board elements with '-' character if test is on, otherwise with a random character. 
    board = new char*[wordSearchPuzzle_boardLines];
    for (int i = 0; i < wordSearchPuzzle_boardLines; i++) {
        board[i] = new char[wordSearchPuzzle_boardClmns];
        for (int j = 0; j < wordSearchPuzzle_boardClmns; j++)
            if (wordSearchPuzzle_test) board[i][j] = '-';
            else board[i][j] = 'A' + rand() % 26;
    }

    //Finds the placement of every word character and updates the board
    for (int i = 0; i < listOfWords.size(); i++) {
        WordInfo cWord = listOfWords[i];
        vector<DirectedLocation> locations = cWord.getAllLocations();
        if (locations.empty()) {
            cout << "word locations empty" << endl;
            throw exception();
        }
        string word = cWord.getContent();
        for (int j = 0; j < word.length(); j++) {
            DirectedLocation dL(locations[j]);
            int r = dL.getRow();
            int c = dL.getColumn();
            board[r][c] = word[j];
        }
    }
}

Board::Board(const Board& orig) {
    board = new char*[wordSearchPuzzle_boardLines];
    for (int i = 0; i < wordSearchPuzzle_boardLines; i++) {
        board[i] = new char[wordSearchPuzzle_boardClmns];
        for (int j = 0; j < wordSearchPuzzle_boardClmns; j++)
            board[i][j] = orig.board[i][j];
    }
}

Board::~Board() {
    for (int i = 0; i < wordSearchPuzzle_boardLines; i++)
        delete [] board[i];
    delete [] board;
}

char Board::get(int row, int column) const {
    return board[row][column];
}



void Board::print() {
    for (int i = 0; i < wordSearchPuzzle_boardLines; i++) {
        for (int j = 0; j < wordSearchPuzzle_boardClmns; j++)
            cout << " " << get(i, j) << " ";
        cout << endl;
    }
    cout << endl;
}

double Board::getPOccupied() {
    int space = wordSearchPuzzle_boardLines*wordSearchPuzzle_boardClmns;
    int validCharacters = 0;
    for (int i = 0; i < wordSearchPuzzle_boardLines; i++) {
        for (int j = 0; j < wordSearchPuzzle_boardClmns; j++)
            if (get(i, j) != '-') validCharacters++;
    }
    return (double) validCharacters / space;
}

// used for tests. It is invoked when test equals true.
void Board::printStats() {
    if (!wordSearchPuzzle_test) return;
    
    cout << "% of Board occupied " << getPOccupied() << endl;
    cout << "Board dimensions :" << wordSearchPuzzle_boardLines << 'x' << wordSearchPuzzle_boardClmns << endl;
    cout << endl;

}