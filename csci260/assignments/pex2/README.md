# README for Assignment 02 - Customer Subscription Management System
CHRISTOPHER NILSSEN CSCI 260 F2402

## Specification
This application is a **Customer Subscription Management System** designed to manage customer subscriptions through a command-line interface. The system allows users to:

- **subscribe:** Add a new customer or reactivate an existing inactive customer.
- **show:** Display details of a customer using their unique customer ID.
- **list:** List all customers by their customer ID in ascending order.
- **spam:** List all active customers by their email in lexicographical order.
- **unsubscribe:** Deactivate a customer's subscription using their customer ID.
- **help:** Display a list of available commands.
- **quit:** Exit the application.

Unlike Assignment 01, this application is implemented using basic concrete data structures without relying on advanced C++ libraries, to deepen understanding of computer science and avoid "computer application" work.

## Design
The application is modularized into the following components:

1. **Customer Module (`Customer.h`, `Customer.cpp`):**
    - Defines the `Customer` class, encapsulating customer details such as ID, email, name, and active status.
2. **Red-Black Tree Module (`RBTree.h`, `RBTree.cpp`):**
    - Manages customers by their unique customer IDs.
    - Ensures efficient search, insertion, and deletion with self-balancing properties.
3. **Binary Search Tree Module (`BST.h`, `BST.cpp)`:**
    - Manages customers by their email addresses.
    - Facilitates efficient search and ordered traversal based on emails.
4. **Main Program Module (`pex2.cpp`):**
    - Handles user input and command processing.
    - Integrates all modules to provide the required functionalities.

**Design Rationale:**
- **Separation of Concerns:** Each module handles a specific aspect of the application, improving maintainability and readability.
- **Efficiency:** Using appropriate data structures (Red-Black Tree and BST) optimizes performance for various operations.
- **Simplicity:** Avoiding advanced libraries keeps the implementation straightforward and educational.

## Implementation
### Data Structures
1. **Red-Black Tree (RBTree):**
    - **Purpose:** Stores and manages customers based on their unique customer IDs.
    - **Implementation:** Custom red-black tree using pointers.
    - **Advantages:**
        - Self-balancing ensures O(log n) time complexity for search, insertion, and deletion.
        - Efficient for handling large datasets with frequent updates.
    - **Disadvantages:**
        - Complexity in implementation due to balancing algorithms.
        - Requires careful handling of pointers and memory management.
    - **Alternatives:**
        - **AVL Tree:** Offers slightly faster lookups but more complex rotations.
        - **Hash Table:** Provides faster average-case lookups but doesn't maintain order.
2. **Binary Search Tree (BST):**
    - **Purpose:** Stores and manages customers based on their email addresses.
    - **Implementation:** Custom binary search tree using pointers.
    - **Advantages:**
        - Simple to implement.
        - In-order traversal naturally lists emails in lexicographical order.
    - **Disadvantages:**
        - Can become unbalanced, degrading performance to O(n) in the worst case.
    - **Alternatives:**
        - **Balanced BST:** Such as an AVL tree or red-black tree to maintain O(log n) operations.

### Memory Management
- **Customer Objects:** Managed by the main program, which keeps track of all customer instances for proper deallocation.
- **Trees:** Nodes store pointers to customer objects but do not own them, preventing double deletion.

## Analysis
### Command Time Efficiency
1. **subscribe:**
    - **Operations:**
        - Search BST for email: O(h) where h is the height of the tree.
        - Insert into RBTree: O(log n).
        - Insert into BST: O(h).
    - **Time Complexity:** O(log n) average, O(n) worst-case due to BST unbalancing.
2. **show:**
    - **Operations:**
        - Search RBTree by customer ID: O(log n).
    - **Time Complexity:** O(log n).
3. **list:**
    - **Operations:**
        - In-order traversal of RBTree: O(n).
    - **Time Complexity:** O(n).
4. **spam:**
    - **Operations:**
        - In-order traversal of BST, filtering active customers: O(n).
    - **Time Complexity: O(n).**
5. **unsubscribe:**
    - **Operations:**
        - Search RBTree by customer ID: O(log n).
    - **Time Complexity:** O(log n).
6. **help:**
    - **Operations:**
        - Display static help message: O(1).
    - **Time Complexity:** O(1).
7. **quit:**
    - **Operations:**
        - Deallocate all customer objects and tree nodes: O(n).
    - **Time Complexity:** O(n).

## Accomplishment
- Implemented all required functionalities:
    - `subscribe`, `show`, `list`, `spam`, `unsubscribe`, `help`, and `quit` commands.
    - Developed custom red-black tree and binary search tree without advanced libraries.
    - Ensured proper memory management and program stability.
    - Enhanced user experience with helpful messages and a `help` command.

## Testing
The program was rigorously tested with the following cases:

1. **Help Command:**
    -Verified that the help command displays all available commands.
2. **Subscribing New Customers:**
    - Added multiple customers with unique emails.
    - Confirmed they received unique customer IDs.
    - Ensured they appeared in list and spam outputs.
3. **Duplicate Email Subscription:**
    - Attempted to subscribe a customer with an existing active email.
    - Confirmed the program displayed an appropriate error message.
4. **Reactivating Inactive Customers:**
    - Unsubscribed a customer.
    - Subscribed again with the same email.
    - Confirmed the customer was reactivated and maintained the same customer ID.
5. **Show Command:**
    - Queried existing customer IDs.
    - Confirmed correct customer details were displayed.
    - Tested with non-existent IDs to ensure error handling.
6. **List Command:**
    - Verified that all customers were listed in ascending order of customer IDs.
    - Checked consistency after adding and removing customers.
7. **Spam Command:**
    - Ensured only active customers were listed.
    - Tested with no active customers to verify the appropriate message was displayed.
8. **Unsubscribe Command:**
    - Unsubscribed active customers.
    - Verified their status changed to inactive.
    - Attempted to unsubscribe already inactive customers and checked for correct error messages.
9. **Edge Cases and Invalid Inputs:**
    - Entered invalid commands and parameters.
    - Confirmed the program prompted with error messages and guidance.
    - Tested behavior with empty inputs and whitespace variations.
10. **Program Exit:**
    - Used the quit command.
    - Verified that all resources were properly released and no memory leaks occurred.

Refer to the `typescript` file for details on the tests run and results.

## Known Bugs
There are currently **no known bugs** in the application.

## Note
- **Memory Management:** All dynamically allocated memory is properly managed to prevent leaks, with customer objects being deleted upon program termination.
- The Makefile has been provided to automate the build process. Running `make` will generate the executable named `pex2`.
- Ensure all source files are present in the correct directory before building.
