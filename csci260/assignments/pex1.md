# Assignment 1 Due 1600 240927
## Objectives
* practice modular design;
* get proficient with the ADT Stack, Queue, Heap/Priority Queue
This assignment is worth 5% of final grade.
## Problem Description
The task is to develop a C++ program that simulates a computer job queue (a.k.a. batch queue).
There are two types of jobs in a computer system: system jobs and user jobs.
When a program starts and waits to be executed, a job is created and inserted into the job queue for processing. Each job would contain the following information:
* its job type which is either system or user;
* an estimated execution time that is a positive floating point number;
* a user id (in the format of a Linux username) that indicates who started this job; (note: system jobs are usually started by root, but not necessarily so)
* a command name (a string starts with a letter, consists of only letters and digits) used to start this job; and
* a resource list (a one line string of printable characters) that describes the resources this job requires (an empty string means that this list is empty)

When the computer is ready to process the next job in the job queue, it always processes system jobs ahead of any user jobs. Among the same typed jobs, the shortest job will be processed first. (Hint: a job's type and its estimated execution time determines the job's priority.)

The program should interactively accept and handle the following commands:
* *submit*: to submit a new job request. Your program should ask for the job's time, its estimated execution time, its user id, its command name and a line to describe the resources the job requires. Then your program should insert the job into the job queue. The program can give the job queue a pre-defined capacity. If the job queue is full when a new job request is submitted, the new submission should be denied its service with an explanation.
* *execute*: to remove the job with the **highest priority** from the job queue to be executed. To simulate the execution of a job, your program simply displays the job's information. If the job queue is empty when this command is entered, your program should show an appropriate message.
* *lottery*: to randomly remove a lucky job from the job queue to be executed. This command is designed to give the long and/or user jobs a chance to be executed earlier than its priority warrants.
* *quit*: to terminat the program. Before termination, the program should empty the job queue by removing them one by one as a simulation of forcibly killing all uncompleted jobs.
This is an interactive program and it should shut down only when the *quit* command is entered.
The program can safely assume that the user will enter numbers for the estimated execution time. However, the appropriate error checking needs to be done to make sure the numbers fall in the right range.
If the job type entered for the job is neither "system" nor "user", or any other invalid data is entered for the job's information (such as a negative number entered for the estimated execution time), then this job request is discarded with a proper explanation message.
A custom Priority Queue ADT **must** be designed and implemented for this assignment. The expected performance of the operations `insert` and `removeMin` must be $O (\log n)$, where $n$ indicates the number of jobs in the job queue.
## Design and Documentation
The source code file should have the proper documentation, such as the header comment for each file, description of the functionality for each fucntion/method unless the name of the function/method is self-explanatory, and some proper in-line comments to improve the readability of the implementation.
Include a `README` file with the solution. It should contain the following sections:
* `Specification`: briefly describes the requirements of the application.
* `Design`: briefly describes the modules in the application design and why the current design was chosen.
* `Implementation`: briefly describes the concrete data structures used in each module. Lists the advantages and disadvantages of using these data structures. Explains whether there are alternative ways to implement the modules.
* `Analysis`: for each of the of the commands (`submit`, `execute`, and `lottery`, give a rough analysis about the time effeciency of their implementations).
* `Accomplishment`: clearly state which parts of the assignment have been completed.
* `Testing`: list the test cases covered to test the program. For each test case, describe the data used and the result shown by the program. Alternatively, if a script was used to capture the sample run of the program, describe the test cases and refer to the typescript file for the test run result.
* `Known Bugs`
* `Note`: any additional details the evaluator should be aware of.
Create a Makefile to automate the program build. Typing `make` should generate an executable named `pex1`.
If the program contains compile time errors, all execution correction marks (~70% of total marks) are lost.
## Submission
To submit the solution, `cd` to the solution directory and run the following command:
`~liuh/bin/submit 260 Pex1 .`
The submit script currently accepts `Makefile`, `README`, `typescript`, `*cpp`, `*.h`, `src/*.cpp` and `include/*.h` files.
If this command is successfully executed, it should show you a list of the files that were submitted to the instructor's directory. If you submit more than once, all but the last submission is discarded. Take advantage of this feature: submit early and submit often. Your assignment must be submitted before the due date and time.
`~liuh/bin/checksubmit 260 Pex1` checks the submission status.