#ifndef JOBUTILS_H
#define JOBUTILS_H

#include "PriorityQueue.h"
#include "Job.h"

void submitNewJob(MinHeap<Job> &jobQueue);

#endif // JOBUTILS_H