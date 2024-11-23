#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::vector;
using std::ifstream;

// kmp algorithm
void computeLPSArray(const string &pattern, vector<int> &lps) {
    int length = 0;
    int i = 1;
    lps[0] = 0; lps[0]; // lps[0] is always 0

    int m = pattern.length();
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            ++length;
            lps[i] = length;
            ++i;
        } else {
            if (length != 0)
                length = lps[length - 1];
            else {
                lps[i] = 0;
                ++i;
            }
        }
    }
}

int KMPSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0;  // text index
    int j = 0;  // pattern index

    while (i < n) {
        if (pattern[j] == text[i]) {
            ++i;
            ++j;
        }

        if (j == m) {
            // match found at i - j
            return i - j;
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                ++i;
        }
    }

    return -1; // no match found
}

int main() {
    // load text file into a char array
    ifstream file("text.txt");
    if (!file) {
        cerr << "error opening the file 'text.txt'.\n";
        return 1;
    }
    string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    // ask for string
    string pattern;
    cout << "Enter a string of up to 20 characters: ";
    std::getline(cin, pattern);
    if (pattern.length() > 20) {
        pattern = pattern.substr(0, 20);
    }

    // search array for match
    int matchPos = KMPSearch(text, pattern);

    if (matchPos != -1) {
        int matchLength = pattern.length();

        // get preceding substring
        int prevStart = std::max(0, matchPos - matchLength);
        int prevLength = matchPos - prevStart;
        string preceding = text.substr(prevStart, prevLength);

        // matched substring
        string matched = text.substr(matchPos, matchLength);

        // get succeeding substring
        int nextStart = matchPos + matchLength;
        int nextLength = std::min(matchLength, static_cast<int>(text.length() - nextStart));
        string succeding = text.substr(nextStart, nextLength);

        // display result
        cout << preceding << matched << succeding << "\n";
    } else {
        cout << "no match found.\n";
    }

    return 0;
}