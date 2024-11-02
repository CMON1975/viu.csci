// CHRISTOPHER NILSSEN Customer.cpp for ASSIGNMENT 02 CSCI 260 F2402

// formerly individually implemented in tree code, refactored here for
// better management
#include "Customer.h"

// implementation of the Customer constructor
Customer::Customer(int id, const string& em, const string& nm)
    : customerID(id), email(em), name(nm), isActive(true) {
    // constructor body is empty since initialization is done above
}
