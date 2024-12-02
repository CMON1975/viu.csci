#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::ifstream;
using std::stringstream;
using std::string;
using std::cout;
using std::endl;

// initialize the dictionary
void initializeDictionary(string dictionary[64], int& dictSize) {
    dictionary[0] = " ";  // whitespace as the first entry
    for (int i = 0; i < 26; ++i) {
        dictionary[i + 1] = string(1, 'a' + i);  // a-z
    }
    dictSize = 27;  // initial dictionary size
}

// convert a binary string to an integer
int binaryToInt(const string& binary) {
    int value = 0;
    for (char c : binary) {
        value = value * 2 + (c - '0');  // convert each bit to int
    }
    return value;
}

// decode function
string decode(const string& binaryString, string dictionary[64], int& dictSize) {
    stringstream ss(binaryString);  // use stringstream to process codes
    string code;                    // for storing each 6-bit code
    string decodedMessage;
    string preWord, curWord;

    // read the first code
    if (ss >> code) {
        int codeInt = binaryToInt(code);
        curWord = dictionary[codeInt];
        decodedMessage += curWord;
        preWord = curWord;
    }

    // process remaining codes
    while (ss >> code) {
        int codeInt = binaryToInt(code);
        curWord = dictionary[codeInt];
        decodedMessage += curWord;

        // create new dictionary entry
        if (dictSize < 64) {
            string codeWord = preWord + curWord[0];
            dictionary[dictSize++] = codeWord;
        }

        preWord = curWord;
    }

    return decodedMessage;
}

int main() {
    // open the input file
    ifstream inputFile("code.txt");
    if (!inputFile) {
        cout << "Error: Unable to open file code.txt." << endl;
        return 1;
    }

    // read the binary string
    string binaryString, temp;
    while (getline(inputFile, temp)) {
        binaryString += temp + " ";  // concatenate lines with a space
    }
    inputFile.close();

    // initialize dictionary
    string dictionary[64];
    int dictSize = 0;
    initializeDictionary(dictionary, dictSize);

    // decode the binary string
    string decodedMessage = decode(binaryString, dictionary, dictSize);

    // output the decoded message
    cout << "Decoded message: " << decodedMessage << endl;

    return 0;
}
