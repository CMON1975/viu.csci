// CHRISTOPHER NILSSEN JobUtils.cpp for ASSIGNMENT 01 CSCI 260 F2402

// this file implements utility functions for managing and processing job objects

#include "JobUtils.h"
#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::numeric_limits;
using std::streamsize;
using std::vector;

void submitNewJob(MinHeap<Job> &jobQueue)
{
    Job newJob;

    // get job type
    cout << "Enter job type (system/user): ";
    cin >> newJob.jobType;

    // basic job type validation
    while (newJob.jobType != "system" && newJob.jobType != "user")
    {
        cout << "Invalid job type. Please enter 'system' or 'user': ";
        cin >> newJob.jobType;
    }

    // get execution time
    cout << "Enter estimated execution time: ";
    while (!(cin >> newJob.executionTime) || newJob.executionTime <= 0)
    {
        cout << "Invalid input. Please enter a positive number for execution time: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // get user ID
    cout << "Enter your username: ";
    cin >> newJob.userID;

    // get command name
    cout << "Enter the command name: ";
    cin >> newJob.commandName;

    // get resource list
    cout << "Enter resource list (comma-separated): ";
    cin.ignore(); // clear buffer
    getline(cin, newJob.resourceList);

    // call the non-interactive version to insert the job
    submitNewJob(jobQueue, newJob);
}

void submitNewJob(MinHeap<Job> &jobQueue, const Job &newJob)
{
    // insert the passed-in job into the queue
    jobQueue.insert(newJob);
    cout << "Job '" << newJob.commandName << "' submitted successfully by user '" << newJob.userID << "'.\n";
}

void execute(MinHeap<Job> &jobQueue, bool suppressOutput)
{
    if (jobQueue.isEmpty())
    {
        if (!suppressOutput)
        {
            cout << "No jobs to execute.\n";
        }
        return;
    }

    // remove the highest priority job
    Job jobToExecute = jobQueue.extractMin();

    // suppress output during testing
    if (!suppressOutput)
    {
        displayJobInfo(jobToExecute, "Executing job:");
    }
}

void lottery(MinHeap<Job> &jobQueue) {
    if (jobQueue.isEmpty()) {
        std::cout << "No jobs in the queue to execute.\n";
        return;
    }

    // Seed random number generator if not seeded
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }

    // Step 1: Copy jobs into a temporary vector
    std::vector<Job> tempJobs;
    while (!jobQueue.isEmpty()) {
        tempJobs.push_back(jobQueue.extractMin());
    }

    // Step 2: Randomly select a lucky job
    size_t queueSize = tempJobs.size();
    size_t randomIndex = static_cast<size_t>(rand()) % queueSize;
    Job luckyJob = tempJobs[randomIndex];

    // Step 3: Rebuild the priority queue, excluding the lucky job
    for (size_t i = 0; i < tempJobs.size(); ++i) {
        if (i != randomIndex) {
            jobQueue.insert(tempJobs[i]);
        }
    }

    // Display lucky job information
    displayJobInfo(luckyJob, "Lucky job selected for execution:");
}

void displayJobInfo(const Job &job, const std::string &header)
{
    cout << header << "\n";
    cout << "Job Type: " << job.jobType << "\n";
    cout << "Execution Time: " << job.executionTime << "\n";
    cout << "User ID: " << job.userID << "\n";
    cout << "Command Name: " << job.commandName << "\n";
    cout << "Resource List: " << job.resourceList << "\n";
}

void quit(MinHeap<Job> &jobQueue)
{
    cout << "Terminating all remaining jobs...\n";

    while (!jobQueue.isEmpty())
    {
        Job jobToTerminate = jobQueue.extractMin();
        displayJobInfo(jobToTerminate, "Forcibly terminating job:");
    }

    cout << "All jobs have been terminated. Exiting the program.\n";

    exit(0);
}
