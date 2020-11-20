/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Statistics.cpp
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 * 
 * Created on May 20, 2020, 12:02 PM
 */

#include "Statistics.h"
#include <limits>

Statistics::Statistics() {
    this->TotBoardOccupied=0;
    this->TotDuration=0;
    this->maxDuration=0;
    this->minDuration=std::numeric_limits<double>::max();
    this->noOfExecutions=0;
}

Statistics::Statistics(const Statistics& orig) {
}

Statistics::~Statistics() {
}

