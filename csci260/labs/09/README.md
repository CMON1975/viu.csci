CHRISTOPHER NILSSEN README.md for LAB 09 CSCI 260 F2402
# String Match Implementation

## Overview
This project implements a string matching algorithm using the Knuth-Morris-Pratt (KMP) algorithm in C++. The program reads text from a file and allows the user to search for a pattern within the text, efficiently finding matches with O(n + m) time complexity, where *n* is the text length and *m* is the pattern length.

## Files
- **StringMatch.cpp**: Contains the implementation of the KMP algorithm and the main program logic.
- **Makefile**: Builds the `StringMatch` executable.

## Usage
To compile and run the program:
```bash
make
./StringMatch
```

The program will prompt you to enter a pattern of up to 20 characters to search for in the text loaded from the file text.txt.

## Notes
Ensure that the file `text.txt` is present in the same directory as the executable, and contains the text you want to search through.