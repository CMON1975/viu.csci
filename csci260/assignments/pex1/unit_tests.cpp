// CHRISTOPHER NILSSEN unit_tests.cpp for ASSIGNMENT 01 CSCI 260 F2402

// This file implements unit tests to verify the functionality of the job queue system.

#include "PriorityQueue.h"
#include "Job.h"
#include "JobUtils.h"
#include "CommandHandler.h"
#include <iostream>
#include <cassert> // For assertions in test cases

using namespace std;

// test insert and extract
void testMinHeapInsertAndExtract()
{
    MinHeap<int> heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(1);

    assert(heap.extractMin() == 1);
    assert(heap.extractMin() == 3);
    assert(heap.extractMin() == 5);
    assert(heap.extractMin() == 7);
    assert(heap.isEmpty());

    cout << "testMinHeapInsertAndExtract passed!" << endl;
}

// test priority completion
void testJobPriority()
{
    Job job1 = {"system", 5.0, "root", "update_system", "cpu,disk"};
    Job job2 = {"user", 2.0, "alice", "compile_code", "cpu"};
    Job job3 = {"system", 2.0, "root", "network_check", "network"};

    assert(job1 < job2);    // System job (higher priority) is less than user job
    assert(!(job2 < job1)); // User job is not less than system job
    assert(job3 < job1);    // Both system jobs; job3 has shorter execution time
    assert(!(job1 < job3)); // job1 has longer execution time than job3

    cout << "testJobPriority passed!" << endl;
}

// test job submission
void testSubmitNewJob()
{
    MinHeap<Job> jobQueue;

    // Create a job
    Job newJob = {"user", 3.0, "bob", "data_backup", "disk"};

    // Submit the job
    submitNewJob(jobQueue, newJob);

    // Extract and check
    Job extractedJob = jobQueue.extractMin();

    assert(extractedJob.userID == "bob");
    assert(extractedJob.executionTime == 3.0);

    cout << "testSubmitNewJob passed!" << endl;
}

void testExecuteJob()
{
    MinHeap<Job> jobQueue;

    Job job1 = {"system", 5.0, "root", "update_system", "cpu,disk"};
    Job job2 = {"user", 2.0, "alice", "compile_code", "cpu"};

    jobQueue.insert(job1);
    jobQueue.insert(job2);

    execute(jobQueue, true); // Execute without output

    // After execution, jobQueue should have one job left
    assert(jobQueue.size() == 1);

    Job remainingJob = jobQueue.extractMin();
    assert(remainingJob.userID == "alice");

    cout << "testExecuteJob passed!" << endl;
}

int main()
{
    testMinHeapInsertAndExtract();
    testJobPriority();
    testSubmitNewJob();
    testExecuteJob();

    cout << "All tests passed!" << endl;
    return 0;
}
