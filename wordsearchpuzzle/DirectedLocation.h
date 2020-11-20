/* 
 * File:   DirectedLocation.h
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 *
 * Created on January 18, 2020, 9:35 AM
 */

#ifndef DIRECTEDLOCATION_H
#define DIRECTEDLOCATION_H

#include <string>
using namespace std;
/*
 * A Directed-Location is a triad consisting of a row identification number, a column identification number, 
 * and a direction identification number, which identifies the location as vertically or horizontally oriented. 
 * The placement of a word in the game board is represented by the Directed-Location, 
 * where the first letter of the word is placed.
 */

class DirectedLocation {
public:
    DirectedLocation();
    DirectedLocation(int row, int column, int direction);
    DirectedLocation(const DirectedLocation& orig);
    //virtual ~DirectedLocation();
    int getRow()const;
    int getColumn()const;
    int getDirection()const;
    bool operator==(const DirectedLocation& dL) const;
    //It is used to initialize a DirectedLocation
    const static DirectedLocation nullLocation;

private:
    int row;
    int column;
    int direction; //0 for horizontal and 1 for vertical
};

#endif /* DIRECTEDLOCATION_H */

