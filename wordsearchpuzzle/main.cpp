/* 
 * File:   main.cpp
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 *
 * Created on January 18, 2020, 9:34 AM
 */

#include <iostream>
#include "RandomLocator.h"
#include "WordInfo.h"
#include "ListOfWords.h"
#include "Words.h"
#include "WoSeCon.h"
#include "Settings.h"
#include "Statistics.h"
using namespace std;

/*
 * 
 */

const int wordSearchPuzzle_Directions::wordSearchPuzzle_HORIZONTAL = 1;
const int wordSearchPuzzle_Directions::wordSearchPuzzle_VERTICAL = 2;

const DirectedLocation DirectedLocation::nullLocation(0, 0, 0);
//RandomLocator WoSeCon::globalLocator;

int main(int argc, char** argv) {
    int repeat=1;
    if (wordSearchPuzzle_test) repeat=wordSearchPuzzle_repetitions;
    Statistics stats;
    for (int i = 0; i < repeat; i++) {
        WoSeCon wosecon;
        Board board = wosecon.construct(stats);
        stats.TotBoardOccupied+=board.getPOccupied();
        if (wordSearchPuzzle_test) cout << i << endl;
        board.printStats();
        board.print();
    }
    if (wordSearchPuzzle_test) {
        cout << "Average % of Board Occupied " << stats.TotBoardOccupied/repeat << endl;
        cout << "Average execution time " << stats.TotDuration/repeat << endl;
        cout << "Min execution duration " << stats.minDuration<< endl;
        cout << "Max execution duration " << stats.maxDuration << endl;
        cout << "repeat = " << repeat << endl;
        cout << "Lines " << wordSearchPuzzle_boardLines << endl;
        cout << "Clmns " << wordSearchPuzzle_boardClmns << endl;
        
    }
    return 0;
}

