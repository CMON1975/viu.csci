#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::vector;
using std::lower_bound;
using std::greater;
using std::runtime_error;
using std::cout;

class PriorityQueueArray {
private:
    vector<int> array;  // sorted in decreasing order

public:
    void insert(int value) {
        auto it = lower_bound(array.begin(), array.end(), value, greater<int>());
        array.insert(it, value);
    }

    int extractMax() {
        if (array.empty())
            throw runtime_error("Priority queue is empty");
        int maxValue = array.front();
        array.erase(array.begin());
        return maxValue;
    }

    bool isEmpty() const {
        return array.empty();
    }
};

