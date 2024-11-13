# Lecture 24
## Tries (continued)
1. standard Trie
2. compressed Trie with auxiliary structure
    - primary structure is the set of strings

**Example:**
S[0]: data
S[1]: database
S[2]: datum
index, S[i..j] substring

```
        root
         |
        0,0,2
        /   \
    0,3,3   2,3,4
    /   \
   \0   1,4,7
```

3. Suffix Trie
    - one string S set = { S[i..n - 1] | 0 <= i <= n - 1}
    - e.g., S = "minimize"
    -draw the tree:
    ```
            root
            / | \
           i  m  n
           |  |  |
           n  i  i
           |  |  |
           i  n  m
           |  |  |
           m  i  i
           |  |  |
           i  m  z
           |  |  |
           z  i  e
           |  |  
           e  z
              |
              e
    ```
    (the above is an incomplete drawing)
    - then draw axiliary tree, nodes containing substrings indicated by start and end index (i, j) of substring.
    - storage is O(n) because we are only storing two indices
    - time efficiency is O(m) where m is the number of characters in a string
    - build a suffix Trie for exact pattern matching