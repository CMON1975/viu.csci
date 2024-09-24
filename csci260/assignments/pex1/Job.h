// CHRISTOPHER NILSSEN Job.h for ASSIGNMENT 01 CSCI 260 F2402

// this header file declares the Job class, representing a job in the system with various attributes

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
