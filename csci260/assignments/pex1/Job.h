// Job.h

#ifndef JOB_H
#define JOB_H

#include <string>

struct Job
{
    std::string jobType; // "system" or "user"
    double executionTime;
    std::string userID;
    std::string commandName;
    std::string resourceList;

    bool operator<(const Job &other) const
    {
        // Assign priority values: lower value means higher priority
        int thisPriority = (jobType == "system") ? 0 : 1;
        int otherPriority = (other.jobType == "system") ? 0 : 1;

        if (thisPriority != otherPriority)
        {
            return thisPriority < otherPriority;
        }
        else
        {
            // Same priority level, compare execution times
            return executionTime < other.executionTime;
        }
    }
};

#endif // JOB_H
