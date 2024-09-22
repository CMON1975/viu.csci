// JobUtils.h

#ifndef JOBUTILS_H
#define JOBUTILS_H

#include "PriorityQueue.h"
#include "Job.h"

void submitNewJob(MinHeap<Job> &jobQueue);
void submitNewJob(MinHeap<Job> &jobQueue, const Job &newJob); // non-interactive version for unit test
void execute(MinHeap<Job> &jobQueue, bool suppressOutput = false);
void lottery(MinHeap<Job> &jobQueue);
void displayJobInfo(const Job &job, const std::string &header);
void quit(MinHeap<Job> &jobQueue);

#endif // JOBUTILS_H