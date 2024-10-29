# Programming Assignment 2
## Objectives
- Practice modular design.
- Get proficient with binary search and red-black trees (search, traversal, and insertion only).

This assignment is worth 5% of the final grade. It will be marked based on the correctness, efficiency (data structures, algorithms, and memory usage), readability (including documentation) and maintainability (modular design) of the program.

## Problem Description
A hypothetical company would like ot have a program to manage thier customer subscription and service. To simplify the business logic, each customer is associated with an internally-used unique customer ID, a unique email address, a name, and an interally-used status.

As such, the program should accept the following commands (with sample parameters).

| Command | Sample Parameter(s) | Explanation | Error Handling
| :- | :- | :- | :- 
| subscribe | jsmith@abc.ca<br>James Smith | A new customer subscription with given customer email<br>and name. The program should assign a unique ID to<br>this new customer; the ID starts from 100001 and the<br>new status is set to active. | If the customer email and name already exist and the customer's status is inactive<br>update the customer's status to active.<br>Any other situation if the customer's email already exists, decline the customer's subscription<br>with an error message.
| show | 123456 | Display ALL information about the customer with the given parameter customer ID 123456 | If the given customer ID doesn't exist, display an error message.
| list | | List the customer ID and name ONLY of ALL customers in ascending order of ID | Display a message if there is no customer at all.
| spam | | List the email and name ONLY of ALL customers whose status is active in ascending order<br>of the customer email. | Display a message if there is no active customer at all.
| unsubscribe | 123456 | Change the status of the customer with the given parameter customer ID 123456<br>from active to inactive. | If the given customer ID doesn't exist, or the customer's status is already inactive,<br>display an error message.
| quit | | Quot the program and abandon all the information stored in your program.<br>**Remember to clean up the dynamically allocated memory space.** | None.

You are required to build two indices about the customer records using two trees. One uses the customer ID as the search keys and the other uses their emails as search keys. The customer ID tree must be implemented as a **red-black tree**, and the email tree must be a **binary search tree**.

Remember that this is an interactive program. Your program should prompt for user input, and display output in some reasonably understandable way with appropriate lables and white spaces. Your program should not crash if an incorrect key is pressed (e.g., the user entered an invalid comment, etc). You may safely assume that if a customer ID needs to be entered, it is always entered as an integer number. You may assume that the emails entered are always a word without spaces, and you don't need to check whether the emails are in the correct format. You can also assume that the emails are case sensitive. That is, the comparison result of the two emails are the same as the comparison result of the two corresponding strings.

When a truly new customer subscription happens, the customer ID is generated by your program and assigned to the new customer. Therefore, it should be guaranteed that the customer ID of the new customer must be unique. However, the email string is provided by the customer and is entered manually. Therefore, your program must perform a check and handle the possible errors caused by duplicate emails. You can treat the email as a simple format-less case sensitive string when performing the check.

If there is an error in the user input, show a message describing the error and go on to process the next command.

## Design and Documentation
With the solution, include a `readme` file (similar to the one required in programming assignment 1) that clearly explains your main design decision. Modularize the code properly. And the source code file(s) should have the usual proper header documentation/comments and necessary in-line comments.

Create a Makefile to automate the building of the program. Upon typing `make`, an executable file named `pex2` should be generatated.

## Submission
To submit the soluction, change working directory to where the solution is located and run the following command:

`~liuh/bin/submit 260 Pex2 .`

The submit script currently accepts Makefile, README, typescript, \*.md, \*.cpp, \*.h, src/\*.cpp and include /\*.h files.

If this command is successfully executed, it should show a list of the files that just got submitted to the instructor's director. If the you submit the assignment more than once, all but the last one will be discarded. Take advantage of this feature, submit early and submit often. Your assignment must be submitted before the due date and time.

You can check what you have submitted for this assignment by running the following command:

`~liuh/bin/checksubmit 260 Pex2`