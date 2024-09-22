// JobUtils.cpp

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

    // Get job type
    cout << "Enter job type (system/user): ";
    cin >> newJob.jobType;

    // Basic job type validation
    while (newJob.jobType != "system" && newJob.jobType != "user")
    {
        cout << "Invalid job type. Please enter 'system' or 'user': ";
        cin >> newJob.jobType;
    }

    // Get execution time
    cout << "Enter estimated execution time: ";
    while (!(cin >> newJob.executionTime) || newJob.executionTime <= 0)
    {
        cout << "Invalid input. Please enter a positive number for execution time: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Get user ID
    cout << "Enter your username: ";
    cin >> newJob.userID;

    // Get command name
    cout << "Enter the command name: ";
    cin >> newJob.commandName;

    // Get resource list
    cout << "Enter resource list (comma-separated): ";
    cin.ignore(); // Clear buffer
    getline(cin, newJob.resourceList);

    // Call the non-interactive version to insert the job
    submitNewJob(jobQueue, newJob);
}

void submitNewJob(MinHeap<Job> &jobQueue, const Job &newJob)
{
    // Insert the passed-in Job into the queue
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

void lottery(MinHeap<Job> &jobQueue)
{
    if (jobQueue.isEmpty())
    {
        cout << "No jobs in the queue to execute.\n";
        return;
    }

    // random number seed
    static bool seeded = false;
    if (!seeded)
    {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }

    size_t queueSize = jobQueue.size();
    size_t randomIndex = static_cast<size_t>(rand()) % queueSize; // range 0 to queueSize - 1

    vector<Job> tempJobs;

    // remove jobs until selected job
    for (size_t i = 0; i < randomIndex; ++i)
    {
        Job tempJob = jobQueue.extractMin();
        tempJobs.push_back(tempJob);
    }

    // extract the random joob
    Job luckyJob = jobQueue.extractMin();

    // re-insert the temp removed jobs
    for (size_t i = 0; i < tempJobs.size(); ++i)
    {
        jobQueue.insert(tempJobs[i]);
    }
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
