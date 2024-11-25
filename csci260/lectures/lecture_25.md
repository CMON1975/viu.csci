# Lecture 25
## Lempel-Ziv-Welch Algorithm
### Encoding
"alphalpha"
- length of binary string in "codebook" dictionary
- how to determine?

| binary | index | char
| :- | :- | :-
| 000 | 0 | a
| 001 | 1 | h
| 010 | 2 | l
| 011 | 3 | p
| 100 | 4 | al
| 101 | 5 | lp
| 110 | 6 | ph
| 111 | 7 | ha

- alphalpha = 100110100110000
- when codebook fills, reject new entries

### Decoding
- receive the bitstring
- know the number of bits
- use Trie for encode/decode
- insert nodes

1. **Receive the Bitstring**
    - The decoder takes in the compressed binary bitstring as input.
    - It's crucial to know the initial bit-length used and any changes in bit-length as the dictionary grows (if variable-length encoding is used).
2. **Know the Number of Bits**
    - The decoder must know how many bits to interpret for each codeword:
        - Start with the initial bit-length (e.g., 3 bits).
        - Adjust the bit-length dynamically as the dictionary expands.
3. **Initialize the Dictionary**
    - The decoder starts with a dictionary identical to the encoder's initial dictionary (typically containing single characters, e.g., `a`, `b`, `c`).
4. **Decoding with a Trie**
    - While a Trie can be used for encoding, it is less common for decoding because decoding LZW relies more on maintaining and expanding a linear dictionary.
    - However, a Trie could be used if a more complex implementation aims to optimize lookup and management.
5. **Insert Nodes**
    - As the decoder processes the input bitstring it:
        - Retrieves codes (e.g., `010`, `011`).
        - Uses the dictionary to translate each code into its corresponding string.
        - Adds new entries to the dictionary based on the output sequence (mirroring how the encoder updates its dictionary).
---

### Revised Decoding Notes
1. **Receive the Bitrstring:**
    - Input: Compressed bitstring from the encoder.
    - Example `000 001 010 011 100 010` (from encoding "alphalpha").
2. **Know the Number of Bits:**
    - Track the bit-length for interpreting codes.
    - Example: Start with 3 bits (if dictionary size ≤ 8).
3. **Initialize the Dictionary:**
    - Start with a dictionary of single characters:

        | Index | Entry
        | :- | :-
        | 0 | a
        | 1 | l
        | 2 | p
        | 3 | h

4. **Decode Using the Dictionary:**
    - Process each code in the bitstring:
        - If the code exists in the dictionary, output its corresponding string.
        - If the code doesn't exist (this happens during dictionary updates), use the previous output plus the first character of the previous output to determine the string.
5. **Insert Nodes (Update Dictionary):**
    - Add new entries to the dictionary by combining the previous output and the first character of the current output.
---

## Graph ADT
- a set of vertices (no duplicates) {$V$}
- a set of edges (or arcs). Intuitively, an edge connects 2 nodes { $<V_i, V_j>$ | $V_i, V_j \in V$}
```
    V_0
   / | 
V_1-----V_3
     |  /
     V_2   
```
- method for relating connectivity information (weights)

### Edges
- directed (use arrow &rarr; to show)
- undirected
    - either state <$V_0,V_1$> = <$V_1,V_2$> or enable <$V_0,V_1$>, <$V_1,V_0$>
- can have mixed (directed + undirected)
- weighted: the edge has some value associated with it
- unweighted
- can contain data or be a simple index

## Data Encoding/Compressing Algorithms
Given an alphabet $\sum$ (typically ASCII or Unicode) and a string X over this alphabet, we want to encode X into a small binary string Y (using only 0 and 1), and guarantee Y is lossless encoding and as small as possible.

In general, there are three different encoding schemes:
- using fixed length binary string to encode fixed length (1) character, such as ASCII or Unicode systems. Usually, these kind of schemes don't compress data and are considered lossless.
- using a variable length binaryh string to encode fixed length (1) character, such as Huffman encoding.
- using fixed length binary string to encode variable length characters, such as Lempel-Ziv encoding.

The Huffman encoding algorithm uses optimized variable length bit strings to encode characters in a given string X over some alphabet $\sum$. The optimization is based on the frequencies of the characters used in string X. The basic idea of the optimization is to use fewer digits to represent the characters with high frequencies. It is a greedy algorithm.

It must be guaranteed that any Huffman code generated is NOT the prefix of any other Huffman code. We use a tree to satisfy this requirement.

Algorithm to generate a Huffman code tree:
```
1. Assign a weighgt to each character inthe alphabet. The more often 
the character appears in the target string X, the heavier the weight 
should be.
2. Create a node for each character and store the weight of the character
in the node. Put all the nodes into a set S.
3. Repeat until there is only one node left in S:
    3.1 Remove two nodes with the smallest weights from S;
    3.2 Create a new node, take the previously removed two nodes
        as the new node's two children; the weight of the new node
        is the sum of the weights of its children nodes;
    3.3 Put the new node into set S.
```

Theorem: Huffman's algorithm always produces optimal code trees.

Assuming that the symbols in a message string X have independent probability to appear, then Huffman encoding is the optimal one. But the above assumption is rarely true in natural languages.

Huffman encoding always requires apriori knowledge about the frequenceies of the character appearance in a message. Sometimes, we don't have this knowledge.

In natural languages, many words and phrases are repeated sometimes. Lempel-Ziv algorithm tries to take advantage of this feature.

### Lempel-Ziv Encoding Algorithm:
```
1. Initialize the dictionary to contain all blocks of length one character
    in the alphabet;
2. Create an empty code string Y;
3. curWord = longest block W which has appeared in the dictionary;
4. Y = Y + curWord's index in the dictionary;
5. preWord = curWord;
6. Repeat until reaching the end of the string X:
    6.1 curWord = longest block W which has appeared in the dictionary;
    6.2 Y = Y + curWord's index in the dictionary;
    6.3 Encode curWord by W's index in the dictionary;
    6.4 codeWord = preWord + first symbol of curWord;
    6.5 If the dictionary is not full and codeWord is not in the dictionary,
        then Add codeWord into the dictionary;
    6.6 preWord = curWord;
```

### Lempel-Ziv Decoding Algorithm:
```
1. Initialize the dictionary to contain all blocks of length one character
    in the alphabet;
2. Create an empty message string X;
3. Read the first code C;
4. curWord = Dictionary[C];
5. X = X + curWord;
6. preWord = curWord;
7. Repeat until reaching the end of the code string Y:
    7.1 read the next code C;
    7.2 curWord = Dictionary[C];
    7.3 X = X + curWord;
    7.4 codeWord = preWord + first symbol of curWord;
    7.5 If the dictionary is not full and codeWord is not in the dictionary, 
        then Add codeWord into the dictionary;
    7.6 preWord = curWord;