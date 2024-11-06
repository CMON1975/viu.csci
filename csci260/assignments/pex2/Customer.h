// CHRISTOPHER NILSSEN - Customer.h for ASSIGNMENT 02 CSCI 260 F2402
// Declares the Customer class, storing a customer's ID, email, name, and active status. 
// Provides a constructor for initializing Customer instances with these attributes.

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using std::string;

class Customer {
public:
    int customerID;
    string email;
    string name;
    bool isActive;

    // constructor
    Customer(int id, const string& em, const string& nm);
};

#endif // CUSTOMER_H