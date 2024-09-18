#include "JobUtils.h"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::getline;
using std::numeric_limits;
using std::streamsize;

const int MAX_QUEUE_SIZE = 5; // TODO refactor to use growing array/vector?

void submitNewJob(MinHeap<Job> &jobQueue)
{
    if (jobQueue.size() >= MAX_QUEUE_SIZE)
    {
        cout << "Job queue full. Submission denied.\n";
        return;
    }

    Job newJob;

    cout << "Enter job type (system/user)";
    cin >> newJob.jobType;

    cout << "Enter estimated execution time: ";
    while (!(cin >> newJob.executionTime))
    {
        cout << "Invalid input. Please enter a numeric execution time: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter a user ID: ";
    cin >> newJob.commandName;

    cout << "Enter resource list (comma separated): ";
    cin.ignore();
    getline(cin, newJob.resourceList);

    jobQueue.insert(newJob);
    cout << "Job submitted successfully.\n";
}