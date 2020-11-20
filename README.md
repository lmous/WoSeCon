# WoSeCon
 Word Search puzzle - Construction Algorithm
 
 Guidelines to run the software
This software is a NetBeans 8.2 project, developed with C ++ 11 on Windows 10. However, it has also been compiled and tested on Linux.
Changing the parameters in Settings.h changes the behavior at runtime.
More specifically:
Set
wordSearchPuzzle_test = true, to run the test version
wordSearchPuzzle_boardLines = 11, wordSearchPuzzle_boardClmns = 11, wordSearchPuzzle_fileName = ”test1.txt” to run the first test 
wordSearchPuzzle_boardLines = 23, wordSearchPuzzle_boardClmns = 23, wordSearchPuzzle_fileName = ”test2.txt” to run the second test 
wordSearchPuzzle_boardLines = 8, wordSearchPuzzle_boardClmns = 9, wordSearchPuzzle_fileName = ”test3.txt” to run the third test 
Add a text file containing one word per line in the project root and set suitable values to variables  wordSearchPuzzle_boardLines, wordSearchPuzzle_boardClmns, and wordSearchPuzzle_fileName to run a custom test.
When running in test mode, the software repeatedly builds a puzzle as many times as the variable wordSearchPuzzle_repetitions indicates and extracts relevant statistics.
test = false if you want to produce a complete word search puzzle.

Please, contact me for any clarification in lmous@cs.ihu.gr.

Lefteris Moussiades



