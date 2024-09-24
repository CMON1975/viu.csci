// CHRISTOPHER NILSSEN CommandHandler.h for ASSIGNMENT 01 CSCI 260 F2402

// this header file declares the CommandHandler class and its methods, used to manage job commands

#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "PriorityQueue.h"
#include "Job.h"

class CommandHandler
{
private:
    MinHeap<Job> jobQueue;

public:
    void submit();
    void submit(const Job &newJob); // for non-interactive testing
    void execute();
    void lottery();
    void quit();
};

#endif // COMMANDHANDLER_H
