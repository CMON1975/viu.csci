// CHRISTOPHER NILSSEN - pex2.cpp for ASSIGNMENT 02 CSCI 260 F2402
// This program implements a customer management system with commands to subscribe, show, list, spam, 
// unsubscribe, and exit. It uses a Red-Black Tree (RBTree) to store customers by ID and a Binary Search 
// Tree (BST) for email-based operations, ensuring efficient data retrieval and updates. The system 
// includes memory management for dynamically allocated Customer instances.

#include <iostream>
#include <string>
#include "Customer.h"
#include "RBTree.h"
#include "BST.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// struct to keep track of all Customer pointers for memory management
struct CustomerNode {
    Customer* customer;
    CustomerNode* next;

    CustomerNode(Customer* cust) : customer(cust), next(nullptr) {}
};

// help display
void displayHelp() {
    cout << "Available commands:" << endl;
    cout << "  subscribe        - Subscribe a new customer" << endl;
    cout << "  show <ID>        - Show customer details by ID" << endl;
    cout << "  list             - List all customers by ID" << endl;
    cout << "  spam             - List active customers by email" << endl;
    cout << "  unsubscribe <ID> - Unsubscribe a customer by ID" << endl;
    cout << "  help             - Display this help message" << endl;
    cout << "  quit             - Exit the program" << endl;
}

int main() {
    RBTree idTree;
    BST emailTree;
    int nextCustomerID = 100001;
    CustomerNode* customerList = nullptr;

    string inputLine;

    displayHelp();

    while (true) {
        cout << "Enter command: ";
        getline(cin, inputLine);

        // remove leading and trailing whitespace
        size_t first = inputLine.find_first_not_of(' ');
        if (first == string::npos) {
            continue; // empty input
        }
        inputLine = inputLine.substr(first);

        // extract command and parameters
        string command;
        size_t pos = inputLine.find(' ');
        if (pos == string::npos) {
            command = inputLine;
            inputLine = "";
        } else {
            command = inputLine.substr(0, pos);
            inputLine = inputLine.substr(pos + 1);
        }

        if (command == "subscribe") {
            // handle subscribe command
            string email, name;

            cout << "Enter email: ";
            getline(cin, email);

            cout << "Enter name: ";
            getline(cin, name);

            // check if email already exists
            BSTNode* emailNode = emailTree.search(email);

            if (emailNode != nullptr) {
                if (!emailNode->customer->isActive) {
                    // reactivate customer
                    emailNode->customer->isActive = true;
                    cout << "Customer reactivated. Customer ID: " << emailNode->customer->customerID << endl;
                } else {
                    cout << "Error: Customer with this email already exists and is active." << endl;
                }
            } else {
                // create new customer
                Customer* newCustomer = new Customer(nextCustomerID++, email, name);

                // add to customer list for memory management
                CustomerNode* custNode = new CustomerNode(newCustomer);
                custNode->next = customerList;
                customerList = custNode;

                // insert into both trees
                idTree.insert(newCustomer);
                emailTree.insert(newCustomer);

                cout << "Subscription successful. Your customer ID is " << newCustomer->customerID << "." << endl;
            }

        } else if (command == "show") {
            // handle show command
            string customerIDStr;
            if (!inputLine.empty()) {
                customerIDStr = inputLine;
            } else {
                cout << "Enter customer ID: ";
                getline(cin, customerIDStr);
            }

            int customerID = std::atoi(customerIDStr.c_str());

            RBTreeNode* idNode = idTree.search(customerID);

            if (idNode != nullptr) {
                Customer* customer = idNode->customer;

                cout << "Customer ID: " << customer->customerID << endl;
                cout << "Email: " << customer->email << endl;
                cout << "Name: " << customer->name << endl;
                cout << "Status: " << (customer->isActive ? "Active" : "Inactive") << endl;
            } else {
                cout << "Error: Customer ID " << customerID << " not found." << endl;
            }

        } else if (command == "list") {
            // handle list command
            if (idTree.isEmpty()) {
                cout << "No customers found." << endl;
            } else {
                idTree.inOrderTraversal();
            }

        } else if (command == "spam") {
        // handle spam command
        if (emailTree.isEmpty()) {
            cout << "No active customers found." << endl;
        } else {
            int activeCount = emailTree.inOrderTraversal();
            if (activeCount == 0) {
                cout << "No active customers found." << endl;
            }
        }

        } else if (command == "unsubscribe") {
            // handle unsubscribe command
            string customerIDStr;
            if (!inputLine.empty()) {
                customerIDStr = inputLine;
            } else {
                cout << "Enter customer ID: ";
                getline(cin, customerIDStr);
            }

            int customerID = std::atoi(customerIDStr.c_str());

            RBTreeNode* idNode = idTree.search(customerID);

            if (idNode != nullptr) {
                Customer* customer = idNode->customer;

                if (customer->isActive) {
                    customer->isActive = false;
                    cout << "Customer ID " << customerID << " unsubscribed successfully." << endl;
                } else {
                    cout << "Error: Customer ID " << customerID << " is already inactive." << endl;
                }
            } else {
                cout << "Error: Customer ID " << customerID << " not found." << endl;
            }
        } else if (command == "help") {
            displayHelp();
        } else if (command == "quit") {
            // clean up and exit
            break;

        } else {
            cout << "Invalid command. Type 'help' to see the list of available commands." << endl;
        }
    }

    // clean up dynamically allocated memory
    CustomerNode* current = customerList;
    while (current != nullptr) {
        CustomerNode* temp = current;
        current = current->next;
        delete temp->customer;
        delete temp;
    }

    return 0;
}
