// CHRISTOPHER NILSSEN basic test of TwoFourTree.cpp for LAB 07 CSCI 260 F2402
#include "TwoFourTree.cpp"

using std::cout;
using std::endl;

int main() {
    TwoFourTree tree;

    tree.insert(10, "Data for 10");
    tree.insert(20, "Data for 20");
    tree.insert(5, "Data for 5");
    tree.insert(6, "Data for 6");
    tree.insert(12, "Data for 12");

    std::string data;
    if (tree.lookup(6, data)) {
        std::cout << "Found key 6 with data: " << data << std::endl;
    } else {
        std::cout << "Key 6 not found." << std::endl;
    }

    if (!tree.insert(6, "Duplicate Data")) {
        std::cout << "Duplicate key 6 not inserted." << std::endl;
    }

    return 0;
}
