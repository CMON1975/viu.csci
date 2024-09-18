#include "Job.h"
#include "PriorityQueue.h"
#include "JobUtils.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    MinHeap<Job> jobQueue;

    Job job1 = {"system", 2.5, "root", "backup", "cpu,ram"};
    Job job2 = {"user", 5.0, "john_doe", "compile", "cpu"};
    Job job3 = {"system", 1.5, "root", "cleanup", "ram"};

    jobQueue.insert(job1);
    jobQueue.insert(job2);
    jobQueue.insert(job3);

    submitNewJob(jobQueue);

    cout << "Min job: " << jobQueue.getMin().commandName << endl;

    while (!jobQueue.isEmpty())
    {
        Job nextJob = jobQueue.extractMin();
        cout << "Executing job: " << nextJob.commandName << endl;
    }

    return 0;
}
