/* 
 * File:   Settings.h
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 *
 * Created on January 18, 2020, 9:51 AM
 */

#ifndef SETTINGS_H
#define SETTINGS_H

//const static int BOARDLINES = 8; 
//const static int BOARDCLMNS = 9;

//const static int BOARDLINES = 23; 
//const static int BOARDCLMNS = 23;

const static int wordSearchPuzzle_boardLines = 8; 
const static int wordSearchPuzzle_boardClmns = 9;



/* This is the name of the  text file with the words to be allocated.
 * It contains one word per line. The file must contained in the same folder as code sources */

const static string wordSearchPuzzle_fileName="test3.txt";

/* true if you want to run the test version*/
const static bool wordSearchPuzzle_test=true;

/* controls the number of repetitions when in test mode*/
const static int wordSearchPuzzle_repetitions=100;

// The two operation modes of WoSeCon
enum wordSearchPuzzle_OperationMode {wordSearchPuzzle_FORWARD, wordSearchPuzzle_BACKWARD};

//Defines directions where words may be located to 
class wordSearchPuzzle_Directions {
public:
    const static int wordSearchPuzzle_HORIZONTAL;
    const static int wordSearchPuzzle_VERTICAL;
};



#endif /* SETTINGS_H */

