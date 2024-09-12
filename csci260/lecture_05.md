# Lecture 5: Set and Dictionary
**prof's notes**
* Set: a collection of unique objects; Multi-set (Bag): a collection of objects.
* Operations on a set:
    - Membership check
    - Math operations: set union, set intersection, set difference
    - Set equivalency check
    - insert a new object into a set
    - remove an object from a set
    - Assistant functionalities: isEmpty, getSize, etc.
* Dictionary: A set of objects where each object can be uniquely identified by its key.
* Dictionary operations:
    - lookup
    - insert
    - remove
    - assistant operations
* Variations of Dictionary operations:
    - get all keys
    - get all objects
    - get all objects with a given key (for multi-set typed dictionary)
    - closest key before/after a given key
    - closest object before/after a given key/object
## Basic Implementation of Dictionary
### Basic common interface:
```
class Dictionary {
    public:
        Dictionary();
        Dictionary(int cap);
        ~Dictionary();
        Data &lookup(Key) throw (NotFound);
        Data &remove(Key) throw (NotFound);
        void insert(Key, Data &) throw (DuplicateKey, Full);
    // START unordered array:
    private:
        int capacity;
        int size;
        Key *keys;
        Data **data;
        int find(Key);
};

Dictionary::Dictionary()
{
    capacity = DEFAULTCAPACITY;
    size = 0;
    keys = new Key[capacity];
    data = new Data*[capacity];
}

Dictionary::Dictionary(int cap)
{
    if (cap <= 0)
        cap = DEFAULTCAPACITY;
    capacity = cap;
    size = 0;
    keys = new Key[capacity];
    data = new Data*[capacity];
}

Dictionary::~Dictionary()
{
    delete [] keys;
    delete [] data;
}

int Dictionary::find(Key k)
{
    for (int i = 0; i < size; ++i)
        if (keys[i] == k)
            return i;
    return -1;
}

Data &Dictionary::lookup(Key k) throw (NotFound)
{
    int index = find(k);
    if (index == -1)
        throw NotFound();
    return *(data[index]);
}

void Dictionary::insert(Key k, Data &d) throw (DuplicateKey, Full)
{
    if (size >= capacity)
        throw Full();
    int index = find(k);
    if (index != -1)
        throw DuplicateKey();

    keys[size] = k;
    data[size] = &d;
    ++size;
}

Data &Dictionary::remove(Key k) throw (NotFound)
{
    int index = find(k);
    if (index == -1)
        throw NotFound();
    
    Data &markedData = *(data[index]);
    --size;
    if (index < size) {
        keys[index] = keys[size];
        data[index] = data[size];
    }
    return markedData;
}
// END: unordered array
    // START: ordered array
        private: int capacity;
        int size;
        Key *keys;
        Data **data;
        int find(Key);
    };

Dictionary::Dictionary()
{
    capacity = DEFAULTCAPACITY;
    size = 0;
    keys = new Key[capacity];
    data = new Data*[capacity];
}

Dictionary::Dictionary(int cap)
{
    if (cap <= 0)
        cap = DEFAULTCAPACITY;
    capacity = cap;
    size = 0;
    keys = new Key[capacity];
    data = new Data*[capacity];
}

Dictionary::~Dictionary()
{
    delete [] keys;
    delete [] data;
}

int Dictionary::find(Key k)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (keys[mid] == k)
            return mid;
        else if (keys[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

Data &Dictionary::lookup(Key k) throw (NotFound)
{
    int index = find(k);
    if (index >= size || keys[index] !=k)
        throw NotFound();
    return *(data[index]);
}

void Dictionary::insert(Key k, Data &d) throw (DuplicateKey, Full) {
    if (size >= capacity)
        throw Full();
    int index = find(k);
    if (index < size && keys[index] == k)
        throw DuplicateKey();

    // Shift elements to the right to make space
    for (int i = size; i > index; --i) {
        keys[i] = keys[i - 1];
        data[i] = data[i - 1];
    }
    keys[index] = k;
    data[index] = &d;
    ++size;
}

Data &Dictionary::remove(Key k) throw (NotFound)
{
    int index = find(k);
    if (index >= size || keys[index] !=k )
        throw NotFound();

    Data &markedData = *(data[index]);
    --size;
    for( ; index < size; ++index) {
        keys[index] = keys[index + 1];
        data[index] = data[index + 1];
    }
    return markedData;
}
// END: ordered array
    // START: pointer-based list
    private:
        int capacity;
        int size;
        struct Node {
            Key key;
            Data *data;
            Node *prev;
            Node *next;
        };
        Node *find(Key);
        Node *list;
    };

Dictionary::Dictionary()
{
    capacity = 0;
    size = 0;
    list = new Node;
    list->prev = list->next = list;
}

Dictionary::Dictionary(int cap)
{
    capacity = cap;
    size = 0;
    list = new Node;
    list->prev = list->next = list;
}

Dictionary::~Dictionary()
{
    Node *ptr = list->next;
    while (ptr != list) {
        Node *temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    delete list;
}

Dictionary::Node *Dictionary::find(Key k)
{
    Node *ptr = list->next;
    while (ptr != list && ptr->key != k)
        ptr = ptr->next;
    
    return ptr;
}

Data &Dictionary::lookup(Key k) throw (NotFound)
{
    Node *index = find(k);
    if (index == list)
        throw NotFound();
    return *(index->data);
}

void Dictionary::insert(Key k, Data &d) throw (DuplicateKey, Full)
{
    if (capacity > 0 && size >= capacity)
        throw Full();
    
    Node *index = find(k);
    if (index != list)
        throw DuplicateKey();

    Node *ptr = new Node;
    ptr->key = k;
    ptr->data = &d;
    ptr->next = list;
    ptr->prev = list->prev;
    list->prev->next = ptr;
    list->prev = ptr;
    ++size;
}

Data &Dictionary::remove(Key k) throw (NotFound)
{
    Node *index = find(k);
    if (index == list)
        throw NotFound();

    index->next->prev = index->prev;
    index->prev->next = index->next;
    Data &markedData = *(index->data);
    delete index;
    --size;
    return markedData;
}
// END: pointer-based list
class NotFound : public std::exception {
    const char *what() const noexcept override {
        return "Key not found in dictionary.";
    }
};

class DuplicateKey : public std::exception {
    const char *what() const noexcept override {
        return "Duplicate key insertion attempted.";
    }
};

class Full : public std::exception {
    const char *what() const noexcept override {
        return "Dictionary is full.";
    }
};

```
### Performance:
| &sp; | loopup | insert | remove |
| --- | --- | --- | --- |
| unordered array | $O(n)$ | $O(1)$ | $O(1)$ |
| ordered array | $O(\log n)$ | $O(n)$ | $O(n)$ |
| linked list | $O(n)$ | $O(1)$ | $O(1)$ |