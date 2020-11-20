/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Statistics.h
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 *
 * Created on May 20, 2020, 12:02 PM
 */

#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics {
public:
    Statistics();
    Statistics(const Statistics& orig);
    virtual ~Statistics();
    double TotDuration;
    double TotBoardOccupied;
    double minDuration;
    double maxDuration;
    int noOfExecutions;
};

#endif /* STATISTICS_H */

