// CHRISTOPHER NILSSEN - SkipList.cpp for LAB 08 CSCI 260 F2402
//
// This skip list provides efficient insertion and lookup for key-value pairs
// by maintaining multiple levels of nodes, where each higher level skips 
// over nodes in the level directly below. This probabilistic structure 
// supports average-case O(log n) time complexity for insertion and lookup.
//
// Key components:
// - SkipListNode: Defines a node with pointers to neighboring nodes in each direction
// - SkipList: Manages the layered structure of nodes and provides insertion and lookup
//   methods with randomized level growth to maintain balanced layers.
//
// Public Interface:
// - lookup(key, result): Searches for a node with the specified key and sets result to its value
// - insert(key, value): Inserts a new key-value pair, adding layers probabilistically

#include <iostream>
#include <cstdlib> // for rand()

using std::cout;
using std::endl;

// node structure for skip list
template <typename KeyType, typename ValueType>
struct SkipListNode {
    KeyType key;
    ValueType value;
    SkipListNode* next;
    SkipListNode* prev;
    SkipListNode* up;
    SkipListNode* down;

    // node constructor
    SkipListNode(KeyType k = KeyType{}, ValueType v = ValueType{}) 
        : key(k), value(v), next(nullptr), prev(nullptr), up(nullptr), down(nullptr) {}
};

// skip list class definition
template <typename KeyType, typename ValueType>
class SkipList {
private:
    int maxHeight;
    float probability;
    SkipListNode<KeyType, ValueType>* head; // head of top layer
    
    // randomly decide node growth
    bool shouldGrow() const {
        return rand() % 2 == 0;  // 50/50 chance using rand()
    }

    SkipListNode<KeyType, ValueType>* find(const KeyType& key) const;

public:
    SkipList(int maxH = 16, float prob = 0.5)
        : maxHeight(maxH), probability(prob), head(new SkipListNode<KeyType, ValueType>) {}

    bool lookup(const KeyType& key, ValueType& result) const;
    void insert(const KeyType& key, const ValueType& value);

    // destructor to deallocate all nodes
    ~SkipList() {
        SkipListNode<KeyType, ValueType>* level = head;
        while (level) {
            SkipListNode<KeyType, ValueType>* node = level;
            level = level->down;
            while (node) {
                SkipListNode<KeyType, ValueType>* next = node->next;
                delete node;
                node = next;
            }
        }
    }
};

// skip list find 
template <typename KeyType, typename ValueType>
SkipListNode<KeyType, ValueType>* SkipList<KeyType, ValueType>::find(const KeyType& key) const {
    SkipListNode<KeyType, ValueType>* node = head;
    while (node) {
        while (node->next && node->next->key < key) {
            node = node->next;
        }
        if (node->down) {
             node = node->down;
        } else {
            break;
        }
    }
    return node;
}

// skip list lookup
template <typename KeyType, typename ValueType>
bool SkipList<KeyType, ValueType>::lookup(const KeyType& key, ValueType& result) const {
    SkipListNode<KeyType, ValueType>* node = find(key);
    if (node->next && node->next->key == key) {
        result = node->next->value;
        return true;
    }
    return false;
}

// skip list insert
template <typename KeyType, typename ValueType>
void SkipList<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
    SkipListNode<KeyType, ValueType>* node = find(key);
    if (node->next && node->next->key == key) {
        // key already exists, so we update the value
        node->next->value = value;
        return;
    }

    SkipListNode<KeyType, ValueType>* newNode = new SkipListNode<KeyType, ValueType>(key, value);

    // insert into bottom layer
    newNode->next = node->next;
    if (node->next) {
        node->next->prev = newNode;
    }
    node->next = newNode;
    newNode->prev = node;

    // grow upwards with probability
    int currentHeight = 1;
    while (shouldGrow() && currentHeight < maxHeight) {
        SkipListNode<KeyType, ValueType>* upperNode = new SkipListNode<KeyType, ValueType>(key, value);
        upperNode->down = newNode;
        newNode->up = upperNode;

        // move left to find a node with an upper level link
        while (node->up == nullptr && node->prev) {
            node = node->prev;
        }
        if (!node->up) {
            // add a new layer if no upper node is found
            SkipListNode<KeyType, ValueType>* newHead = new SkipListNode<KeyType, ValueType>();
            newHead->down = head;
            head->up = newHead;
            head = newHead;
        }
        node = node->up;

        upperNode->next = node->next;
        if (node->next) {
            node->next->prev = upperNode;
        }
        node->next = upperNode;
        upperNode->prev = node;

        newNode = upperNode;
        ++currentHeight;        
    }
}
