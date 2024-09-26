# Hash Table Implementation
Implement a hash table class with the following interface:
```
class HashTable
{
    public:
        HashTable();
        ~HashTable();
        void insert(int k, string e);
        string lookup(int k);
    private:
      ...
};
```
To simplify the implementation, you can assume that the keys of the elements are integewrs in the range of [0, 1000], the elements themselves are strings, and the capacity of the hash table is 79.

If you need a prime number between 1000 and 2000, here are some to pick from: 1009, 1163, 1231, 1373, 1471, 1567, 1693, 1789, 1801, 1993.

You can pick one of the two methods to solve the collision problem:
- Open addressing (linear probing, quadratic probing, or double hashing)
- Separate Chaining

Submit using the name `Lab3`.