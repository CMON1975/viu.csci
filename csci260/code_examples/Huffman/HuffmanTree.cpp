#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <queue>
#include <unordered_map>

// Define the Huffman Tree node
struct HuffmanNode {
    char character;         // The character (only for leaf nodes)
    int frequency;          // The frequency of the character(s)
    HuffmanNode* left;      // Left child
    HuffmanNode* right;     // Right child

    // Constructor for leaf nodes
    HuffmanNode(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}

    // Constructor for internal nodes
    HuffmanNode(int freq, HuffmanNode* l, HuffmanNode* r) : character('\0'), frequency(freq), left(l), right(r) {}
};

// Compare function for the priority queue
struct CompareNode {
    bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2) {
        // Higher frequency nodes have lower priority
        return n1->frequency > n2->frequency;
    }
};

// Function to build the Huffman tree
HuffmanNode* buildHuffmanTree(const std::unordered_map<char, int>& freq_table) {
    // Priority queue to store the nodes of the Huffman tree
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNode> minHeap;

    // Create leaf nodes for each character and add them to the priority queue
    for (const auto& pair : freq_table) {
        HuffmanNode* node = new HuffmanNode(pair.first, pair.second);
        minHeap.push(node);
    }

    // Iterate until there is only one node left in the queue (the root)
    while (minHeap.size() > 1) {
        // Extract the two nodes with the smallest frequencies
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with these two nodes as children
        int sumFrequency = left->frequency + right->frequency;
        HuffmanNode* internalNode = new HuffmanNode(sumFrequency, left, right);

        // Add the new node back to the priority queue
        minHeap.push(internalNode);
    }

    // The remaining node is the root of the Huffman tree
    return minHeap.top();
}

// Function to generate Huffman codes from the Huffman tree
void generateHuffmanCodes(HuffmanNode* root, const std::string& code,
                          std::unordered_map<char, std::string>& huffmanCodes) {
    if (!root) return;

    // If this is a leaf node, it contains a character
    if (!root->left && !root->right) {
        huffmanCodes[root->character] = code;
    }

    // Traverse the left and right children
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to delete the Huffman tree and free memory
void deleteHuffmanTree(HuffmanNode* root) {
    if (!root) return;

    deleteHuffmanTree(root->left);
    deleteHuffmanTree(root->right);
    delete root;
}

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

    // Initialize the frequency table for letters 'a' to 'z'
    std::unordered_map<char, int> freq_table;

    // Iterate over each character in the string
    for (char c : S) {
        // Convert character to lower-case if it's an upper-case letter
        if (std::isupper(static_cast<unsigned char>(c))) {
            c = std::tolower(static_cast<unsigned char>(c));
        }
        // Check if the character is a lower-case letter
        if (c >= 'a' && c <= 'z') {
            freq_table[c] += 1; // Increment the count
        }
    }

    // Build the Huffman tree
    HuffmanNode* root = buildHuffmanTree(freq_table);

    // Generate Huffman codes
    std::unordered_map<char, std::string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Output the Huffman codes
    std::cout << "Huffman Codes for each character:\n";
    for (const auto& pair : huffmanCodes) {
        std::cout << "'" << pair.first << "': " << pair.second << "\n";
    }

    // Clean up and free the Huffman tree memory
    deleteHuffmanTree(root);

    return 0;
}
