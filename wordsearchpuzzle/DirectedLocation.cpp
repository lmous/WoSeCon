/* 
 * File:   DirectedLocation.cpp
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 * 
 * Created on January 18, 2020, 9:35 AM
 */

#include "DirectedLocation.h"


DirectedLocation::DirectedLocation(int row, int column, int direction) {
    this->row = row;
    this->column = column;
    this->direction = direction;
}

DirectedLocation::DirectedLocation() {
    row=0;
    column=0;
    direction=0;
}

DirectedLocation::DirectedLocation(const DirectedLocation& orig) {
    row = orig.row;
    column = orig.column;
    direction = orig.direction;
}

int DirectedLocation::getRow() const {
    return row;
}

int DirectedLocation::getColumn() const {
    return column;
}

int DirectedLocation::getDirection() const {
    return direction;
}

bool DirectedLocation::operator ==(const DirectedLocation& dL) const {
        return (this->row==dL.row && this->column==dL.column && this->direction==dL.direction);
    
}

