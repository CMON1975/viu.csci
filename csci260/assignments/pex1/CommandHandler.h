// CommandHandler.h

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
