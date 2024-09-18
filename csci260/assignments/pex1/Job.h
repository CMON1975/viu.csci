#ifndef JOB_H
#define JOB_H

#include <string>

using std::string;

struct Job
{
    string jobType; // "system" or "user"
    double executionTime;
    string userID; // linux format
    string commandName;
    string resourceList;

    // comparison operator for priority based on job type and execution time
    bool operator<(const Job &other) const
    {
        if (jobType == "system" && other.jobType == "user")
        {
            return false; // system jobs take priority
        }
        else if (jobType == "user" && other.jobType == "system")
        {
            return true;
        }
        else
        {
            // jobs are the same type, go to execution time
            return executionTime > other.executionTime;
        }
    }
};

#endif // JOB_H