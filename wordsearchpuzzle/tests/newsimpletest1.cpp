/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest1.cpp
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 *
 * Created on January 19, 2020, 7:56 PM
 */

#include <stdlib.h>
#include <iostream>
#include "RandomLocator.h"

/*
 * Simple C++ Test Suite
 */

void testRandomLocator() {
    RandomLocator randomLocator();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testRandomLocator (newsimpletest1) message=error message sample" << std::endl;
    }
}

void testRandomLocator2() {
    const RandomLocator& orig;
    RandomLocator randomLocator(orig);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testRandomLocator2 (newsimpletest1) message=error message sample" << std::endl;
    }
}

void testGet() {
    int idx;
    RandomLocator randomLocator;
    DirectedLocation result = randomLocator.get(idx);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGet (newsimpletest1) message=error message sample" << std::endl;
    }
}

void testSet() {
    int idx;
    const DirectedLocation& dL;
    RandomLocator randomLocator;
    randomLocator.set(idx, dL);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSet (newsimpletest1) message=error message sample" << std::endl;
    }
}

void testAdd() {
    const DirectedLocation& dL;
    RandomLocator randomLocator;
    randomLocator.add(dL);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testAdd (newsimpletest1) message=error message sample" << std::endl;
    }
}

void testRemove() {
    const DirectedLocation& loc;
    RandomLocator randomLocator;
    randomLocator.remove(loc);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testRemove (newsimpletest1) message=error message sample" << std::endl;
    }
}

void testMinus() {
    const vector<DirectedLocation>& visited;
    RandomLocator randomLocator;
    RandomLocator result = randomLocator.minus(visited);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testMinus (newsimpletest1) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest1" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testRandomLocator (newsimpletest1)" << std::endl;
    testRandomLocator();
    std::cout << "%TEST_FINISHED% time=0 testRandomLocator (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testRandomLocator2 (newsimpletest1)" << std::endl;
    testRandomLocator2();
    std::cout << "%TEST_FINISHED% time=0 testRandomLocator2 (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testGet (newsimpletest1)" << std::endl;
    testGet();
    std::cout << "%TEST_FINISHED% time=0 testGet (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testSet (newsimpletest1)" << std::endl;
    testSet();
    std::cout << "%TEST_FINISHED% time=0 testSet (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testAdd (newsimpletest1)" << std::endl;
    testAdd();
    std::cout << "%TEST_FINISHED% time=0 testAdd (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testRemove (newsimpletest1)" << std::endl;
    testRemove();
    std::cout << "%TEST_FINISHED% time=0 testRemove (newsimpletest1)" << std::endl;

    std::cout << "%TEST_STARTED% testMinus (newsimpletest1)" << std::endl;
    testMinus();
    std::cout << "%TEST_FINISHED% time=0 testMinus (newsimpletest1)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

