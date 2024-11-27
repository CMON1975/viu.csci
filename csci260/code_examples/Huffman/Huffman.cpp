#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

int main() {
    // Open the file string.txt for reading
    std::ifstream infile("string.txt");
    if (!infile) {
        std::cerr << "Error: Unable to open file 'string.txt'." << std::endl;
        return 1;
    }

    // Read the contents of the file into a string
    std::string S((std::istreambuf_iterator<char>(infile)),
                   std::istreambuf_iterator<char>());
    infile.close();

    // Initialize the frequency array for letters 'a' to 'z'
    int F[26] = {0};

    // Iterate over each character in the string
    for (char c : S) {
        // Convert character to lower-case if it's an upper-case letter
        if (std::isupper(static_cast<unsigned char>(c))) {
            c = std::tolower(static_cast<unsigned char>(c));
        }
        // Check if the character is a lower-case letter
        if (c >= 'a' && c <= 'z') {
            int index = c - 'a'; // Find the index corresponding to the letter
            F[index] += 1;       // Increment the count
        }
    }

    // Create a vector to hold the letter and frequency pairs
    std::vector<std::pair<int, char>> freqVec;

    // Populate the vector with letters that have non-zero frequency
    for (int i = 0; i < 26; ++i) {
        if (F[i] > 0) {
            freqVec.push_back(std::make_pair(F[i], 'a' + i));
        }
    }

    // Sort the vector in decreasing order of frequency
    std::sort(freqVec.begin(), freqVec.end(),
              [](const std::pair<int, char>& a, const std::pair<int, char>& b) {
                  if (a.first != b.first)
                      return a.first > b.first; // Higher frequency comes first
                  else
                      return a.second < b.second; // Tie-breaker: lower letter comes first
              });

    // Output the frequency table
    std::cout << "Letter Frequency Table (sorted by frequency):\n";
    for (const auto& p : freqVec) {
        std::cout << "| " << p.second << " | " << p.first << "\n";
    }

    return 0;
}
