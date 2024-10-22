#include <iostream>
#include <string>

// use 'using' declarations to avoid 'std::' prefix
using std::cout;
using std::cerr;
using std::endl;
using std::string;

// maximum number of child pointers per node
const int B = 4;

template<typename Key, typename Data>
struct Node {
    Key k[B - 1];            // array of keys
    Data* d[B - 1];          // array of data pointers
    Node* children[B];       // array of child pointers
    int size;                // current number of keys in the node

    Node() : size(0) {
        for (int i = 0; i < B - 1; i++) {
            d[i] = nullptr;  // initialize data pointers to nullptr
        }
        for (int i = 0; i < B; i++) {
            children[i] = nullptr; // initialize child pointers to nullptr
        }
    }

    ~Node() {
        for (int i = 0; i < B - 1; i++) {
            delete d[i]; // free memory for data pointers
        }
        for (int i = 0; i < B; i++) {
            delete children[i]; // free memory for child nodes
        }
    }
};

template<typename Key, typename Data>
Node<Key, Data>* root = nullptr;  // global root pointer

// helper function to split a leaf node
template<typename Key, typename Data>
void splitLeafNode(Node<Key, Data>* r, Key& k, Data*& dataptr, Node<Key, Data>*& newNode) {
    const int capacity = B - 1;
    // temporary arrays to hold keys and data
    Key tempKeys[B];
    Data* tempData[B];
    // copy existing keys and data to temporary arrays
    for (int i = 0; i < capacity; i++) {
        tempKeys[i] = r->k[i];
        tempData[i] = r->d[i];
    }
    // insert new key and data into temporary arrays
    int i = capacity - 1;
    while (i >= 0 && tempKeys[i] > k) {
        tempKeys[i + 1] = tempKeys[i];
        tempData[i + 1] = tempData[i];
        i--;
    }
    tempKeys[i + 1] = k;
    tempData[i + 1] = dataptr;
    // split the node into two nodes
    int mid = capacity / 2;
    r->size = mid;
    newNode = new Node<Key, Data>();
    newNode->size = capacity - mid;
    // copy the first half to the original node
    for (int i = 0; i < r->size; i++) {
        r->k[i] = tempKeys[i];
        r->d[i] = tempData[i];
    }
    // copy the second half to the new node
    for (int i = 0; i < newNode->size; i++) {
        newNode->k[i] = tempKeys[mid + i];
        newNode->d[i] = tempData[mid + i];
    }
    // promote the middle key to the parent
    k = tempKeys[mid];
    dataptr = tempData[mid];
}

// helper function to split an internal node
template<typename Key, typename Data>
void splitInternalNode(Node<Key, Data>* r, Key& k, Data*& dataptr, Node<Key, Data>* newChild, Node<Key, Data>*& newNode) {
    const int capacity = B - 1;
    // temporary arrays to hold keys, data, and child pointers
    Key tempKeys[B];
    Data* tempData[B];
    Node<Key, Data>* tempChildren[B + 1];
    // copy existing keys, data, and child pointers to temporary arrays
    for (int i = 0; i < capacity; i++) {
        tempKeys[i] = r->k[i];
        tempData[i] = r->d[i];
    }
    for (int i = 0; i <= capacity; i++) {
        tempChildren[i] = r->children[i];
    }
    // find position to insert new key
    int p = 0;
    while (p < capacity && k > tempKeys[p]) {
        p++;
    }
    // insert new key, data, and child pointer into temporary arrays
    for (int i = capacity - 1; i >= p; i--) {
        tempKeys[i + 1] = tempKeys[i];
        tempData[i + 1] = tempData[i];
    }
    for (int i = capacity; i >= p + 1; i--) {
        tempChildren[i + 1] = tempChildren[i];
    }
    tempKeys[p] = k;
    tempData[p] = dataptr;
    tempChildren[p + 1] = newChild;
    // split the node into two nodes
    int mid = capacity / 2;
    r->size = mid;
    newNode = new Node<Key, Data>();
    newNode->size = capacity - mid;
    // copy the first half to the original node
    for (int i = 0; i < r->size; i++) {
        r->k[i] = tempKeys[i];
        r->d[i] = tempData[i];
        r->children[i] = tempChildren[i];
    }
    r->children[r->size] = tempChildren[r->size];
    // copy the second half to the new node
    for (int i = 0; i < newNode->size; i++) {
        newNode->k[i] = tempKeys[mid + i];
        newNode->d[i] = tempData[mid + i];
        newNode->children[i] = tempChildren[mid + i];
    }
    newNode->children[newNode->size] = tempChildren[mid + newNode->size];
    // promote the middle key to the parent
    k = tempKeys[mid];
    dataptr = tempData[mid];
}

// insert functions
template<typename Key, typename Data>
void insert(Key k, Data element) {
    if (root<Key, Data> == nullptr) {  // empty tree
        root<Key, Data> = new Node<Key, Data>();
        // insert key and data into the root node
        root<Key, Data>->k[0] = k;
        root<Key, Data>->d[0] = new Data(element);
        root<Key, Data>->size = 1;
    } else {  // non-empty tree
        Node<Key, Data>* newNode = nullptr;
        Data* dataptr = new Data(element);
        bool split = insert(root<Key, Data>, k, dataptr, newNode);
        if (split) {  // root was split
            Node<Key, Data>* newRoot = new Node<Key, Data>();
            newRoot->size = 1;
            newRoot->k[0] = k;
            newRoot->d[0] = dataptr;
            newRoot->children[0] = root<Key, Data>;
            newRoot->children[1] = newNode;
            root<Key, Data> = newRoot;
        }
    }
}

template<typename Key, typename Data>
bool insert(Node<Key, Data>* r, Key& k, Data*& dataptr, Node<Key, Data>*& newNode) {
    if (r->children[0] == nullptr) {  // leaf node
        // check for duplicate keys
        for (int i = 0; i < r->size; i++) {
            if (r->k[i] == k) {
                cerr << "duplicate key insertion is not allowed: " << k << endl;
                return false;
            }
        }
        if (r->size < B - 1) {  // leaf node not full
            // insert key and data into the leaf node
            int i = r->size - 1;
            while (i >= 0 && r->k[i] > k) {
                r->k[i + 1] = r->k[i];
                r->d[i + 1] = r->d[i];
                i--;
            }
            r->k[i + 1] = k;
            r->d[i + 1] = dataptr;
            r->size++;
            return false;
        } else {  // leaf node full, need to split
            splitLeafNode(r, k, dataptr, newNode);
            return true;
        }
    } else {  // internal node
        // find the child to recurse on
        int p = 0;
        while (p < r->size && k > r->k[p]) {
            p++;
        }
        bool split = insert(r->children[p], k, dataptr, newNode);
        if (split) {  // child was split
            if (r->size < B - 1) {  // internal node not full
                // insert key, data, and new child pointer into the node
                for (int i = r->size - 1; i >= p; i--) {
                    r->k[i + 1] = r->k[i];
                    r->d[i + 1] = r->d[i];
                    r->children[i + 2] = r->children[i + 1];
                }
                r->k[p] = k;
                r->d[p] = dataptr;
                r->children[p + 1] = newNode;
                r->size++;
                return false;
            } else {  // internal node full, need to split
                splitInternalNode(r, k, dataptr, newNode, newNode);
                return true;
            }
        }
    }
    return false;
}

// in-order traversal to print the tree
template<typename Key, typename Data>
void inOrderTraversal(Node<Key, Data>* node) {
    if (node == nullptr) {
        return;
    }
    for (int i = 0; i < node->size; i++) {
        inOrderTraversal(node->children[i]);
        cout << node->k[i] << ": " << *(node->d[i]) << endl;
    }
    inOrderTraversal(node->children[node->size]);
}

// search function
template<typename Key, typename Data>
Data* search(Node<Key, Data>* node, Key k) {
    if (node == nullptr) {
        return nullptr;
    }
    int i = 0;
    while (i < node->size && k > node->k[i]) {
        i++;
    }
    if (i < node->size && k == node->k[i]) {
        return node->d[i];
    }
    return search(node->children[i], k);
}

int main() {
    // insert keys and data
    insert<int, string>(10, "ten");
    insert<int, string>(20, "twenty");
    insert<int, string>(5, "five");
    insert<int, string>(6, "six");
    insert<int, string>(12, "twelve");
    insert<int, string>(30, "thirty");
    insert<int, string>(7, "seven");
    insert<int, string>(17, "seventeen");

    // attempt to insert a duplicate key
    insert<int, string>(6, "duplicate six");

    // in-order traversal to print the tree
    cout << "in-order traversal of the tree:" << endl;
    inOrderTraversal<int, string>(root<int, string>);

    // search for keys
    int searchKey = 12;
    auto result = search<int, string>(root<int, string>, searchKey);
    if (result) {
        cout << "found key " << searchKey << ": " << *result << endl;
    } else {
        cout << "key " << searchKey << " not found." << endl;
    }

    return 0;
}
