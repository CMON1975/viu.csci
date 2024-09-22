// CommandHandler.cpp

#include "CommandHandler.h"
#include "JobUtils.h"

void CommandHandler::submit()
{
    submitNewJob(jobQueue);
}

void CommandHandler::submit(const Job &newJob)
{
    submitNewJob(jobQueue, newJob); // Non-interactive version
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
