// CHRISTOPHER NILSSEN CommandHandler.cpp for ASSIGNMENT 01 CSCI 260 F2402

// this file implements functionalities for handling various commands in the job management system

#include "CommandHandler.h"
#include "JobUtils.h"

void CommandHandler::submit()
{
    submitNewJob(jobQueue);
}

void CommandHandler::submit(const Job &newJob)
{
    submitNewJob(jobQueue, newJob); // non-interactive version
}

void CommandHandler::execute()
{
    ::execute(jobQueue);
}

void CommandHandler::lottery()
{
    ::lottery(jobQueue);
}

void CommandHandler::quit()
{
    ::quit(jobQueue);
}
