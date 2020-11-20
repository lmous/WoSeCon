/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: Lefteris Moussiades <lmous@teiemt.gr>
 *
 * Created on January 19, 2020, 1:32 PM
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
        std::cout << "%TEST_FAILED% time=0 testname=testRandomLocator (newsimpletest) message=error message sample" << std::endl;
    }
}

void testRandomLocator2() {
    const RandomLocator orig;
    RandomLocator randomLocator(orig);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testRandomLocator2 (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testRandomLocator (newsimpletest)" << std::endl;
    testRandomLocator();
    std::cout << "%TEST_FINISHED% time=0 testRandomLocator (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testRandomLocator2 (newsimpletest)" << std::endl;
    testRandomLocator2();
    std::cout << "%TEST_FINISHED% time=0 testRandomLocator2 (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

