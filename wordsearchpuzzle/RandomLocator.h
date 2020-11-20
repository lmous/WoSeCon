/* 
 * File:   RandomLocator.h
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 *
 * Created on January 18, 2020, 10:15 AM
 */

#ifndef RANDOMLOCATOR_H
#define RANDOMLOCATOR_H
#include "DirectedLocation.h"
#include "Settings.h"
#include <vector>
using namespace std;

//A Random-Locator keeps a list of available Directed-Locations and can select randomly one of them.  
//Note that a Random-Locator shuffles the list of Directed-Locations immediately after the list creation. 
//Therefore, the random selection is achieved by selecting sequentially the Directed-Locations kept in the list of the Random-Locator. 

class RandomLocator {
public:
    RandomLocator();
    RandomLocator(const RandomLocator& orig);
    virtual ~RandomLocator();
   
    //It returns the Directed-Location at the index position represented by its integer argument. 
    //Note, when accessing Directed-Locations sequentially using the get function, we get the available 
    //locations in the game board in random order as a Random-Locator shuffles the list of Directed-Locations at its construction.
    DirectedLocation get(int idx) const;
    
    //It adds a Directed-Location to the list of available Directed-Locations.
    void add(const DirectedLocation& dL);
    
    //It removes its argument from the list of Directed-Locations and returns it to the caller. 
    void remove(const DirectedLocation& loc);
    
    //It returns a Random-Locator that considers as available Directed-Locations those that are available at the time the operation is executed, 
    //minus the Directed-Locations contained in the list that is given as argument
    RandomLocator minus(const vector<DirectedLocation>& visited);
    
    int size() const;
   
private:
    vector<DirectedLocation> store; //list of DirectedLocations
};

#endif /* RANDOMLOCATOR_H */

