
#include <stdlib.h>
#include <time.h>

#ifndef Process_H
#define Process_H

typedef struct process
{
    int  pid;
    int  priority;
    int  burstTime;
    int  arrivalTime;
    int  startTime;
    int  endTime;
    int  remainingTime;
    int  stopTime;
    char done;
} Process;

typedef struct runstats
{
    float averageTurnaroundtime;
    float averageWaittime;
} runStats;

int generateProcesses(Process ** queue, int length);

int qCopy(Process ** queue, Process ** queue2, int length);

#endif
