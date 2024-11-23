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