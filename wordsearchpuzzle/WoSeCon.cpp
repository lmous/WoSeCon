/* 
 * File:   WoSeCon.cpp
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 * 
 * Created on January 21, 2020, 6:35 AM
 */

#include "WoSeCon.h"
#include "ListOfWords.h"
#include "RandomLocator.h"
#include <iostream>
#include "Settings.h"
#include "Board.h"
#include "Statistics.h"
#include <chrono>
#include <ctime>  
using namespace std;

WoSeCon::WoSeCon() {
    listOfWords = ListOfWords().getList();
}

WoSeCon::WoSeCon(const WoSeCon& orig) {
    for (int i=0; i<orig.listOfWords.size(); i++)
        listOfWords.push_back(orig.listOfWords[i]);
}

WoSeCon::~WoSeCon() {
    listOfWords.clear();
}

Board WoSeCon::construct(Statistics& stats) {
    auto start = chrono::system_clock::now();
    // Some computation here


    int cWordIndex = 0;
    WordInfo* cWord = &listOfWords[cWordIndex];
    operationMode = wordSearchPuzzle_FORWARD;
    while (true) {
        if (locateOne(cWord)) {
            if (cWordIndex == listOfWords.size() - 1) break;
            cWord = &listOfWords[++cWordIndex];
            operationMode = wordSearchPuzzle_FORWARD;
            
        } else {
            if (cWordIndex == 0) fail();
            cWord->deleteTested();
            cWord = &listOfWords[--cWordIndex];
            operationMode = wordSearchPuzzle_BACKWARD;
        }
    }
    if (wordSearchPuzzle_test) {
        auto end = chrono::system_clock::now();

        chrono::duration<double> elapsed_seconds = end - start;
        time_t end_time = chrono::system_clock::to_time_t(end);
        time_t start_time = chrono::system_clock::to_time_t(start);
        double duration=elapsed_seconds.count();
        std::cout << "start computation at " << std::ctime(&start_time)
                << "finished computation at " << std::ctime(&end_time)
                << "elapsed time: " << duration << "s\n";
        stats.TotDuration+=duration;
        stats.noOfExecutions++;
        if (duration > stats.maxDuration) stats.maxDuration=duration;
        if (duration < stats.minDuration) stats.minDuration=duration;
    }
    return Board(listOfWords);
}

bool WoSeCon::locateOne(WordInfo* cWord) {
    vector<DirectedLocation> tested = cWord->getTested();
    RandomLocator l = globalLocator.minus(tested);
    RandomLocator *localLocator;

    if (operationMode == wordSearchPuzzle_BACKWARD) {
        DirectedLocation dL = cWord->getPlacement();
        globalLocator.add(dL);
        cWord->addToTested();
        localLocator = &l;
    } else
        localLocator = &globalLocator;

    int locationIndex = 0;
    while (locationIndex < localLocator->size()) {
        DirectedLocation suitableLocation = localLocator->get(locationIndex);
        if (validPlacement(cWord, suitableLocation)) {
            globalLocator.remove(suitableLocation);
            return true;
        }
        locationIndex++;
    }
    return false;
}

bool WoSeCon::validPlacement(WordInfo* cWord, DirectedLocation dL) {
    cWord->setPlacement(dL);
    vector<DirectedLocation> wordLocations = cWord->getAllLocations();
    for (const DirectedLocation& l : wordLocations) {
        if (l.getRow() > wordSearchPuzzle_boardLines - 1 || l.getColumn() > wordSearchPuzzle_boardClmns - 1) {
            cWord->setPlacement(DirectedLocation::nullLocation);
            return false;
        }
    }

    for (int i = 0; i < listOfWords.size(); i++) {
        WordInfo *wToCheck = &listOfWords[i];
        if (!(*cWord == *wToCheck)) {
            if (cWord->conflict(wToCheck)) {
                cWord->setPlacement(DirectedLocation::nullLocation);
                return false;
            }
        }
    }

    return true;
}

void WoSeCon::fail() {
    cout << "Word Search Puzzle cannot be constructed" << endl;
    cout << "Change board dimensions or list of words" << endl;
    exit(EXIT_FAILURE);
}

