#include "Process.h"

//Generate processes for testing
int generateProcesses(Process ** queue, int length){

    srand(time(NULL));

    for(int i = 0; i < length; i++){
        queue[i] = (Process*)malloc(sizeof(Process));

        queue[i]->pid           = i + 1;
        queue[i]->priority      = rand() % 3  + 1;
        queue[i]->burstTime     = rand() % 15 + 1;
        queue[i]->arrivalTime   = rand() % 5  + 1;
        queue[i]->startTime     = 0;
        queue[i]->endTime       = 0;
        queue[i]->remainingTime = queue[i]->burstTime;
        queue[i]->stopTime      = 0;
        queue[i]->done          = 'f';
    }

    return 0;
}

int qCopy(Process ** queue, Process ** queue2, int length){ //copy existing queue

    for(int i = 0; i < length; i++){
        queue[i] = (Process*)malloc(sizeof(Process));

        queue[i]->pid           = queue2[i]->pid;
        queue[i]->priority      = queue2[i]->priority;
        queue[i]->burstTime     = queue2[i]->burstTime;
        queue[i]->arrivalTime   = queue2[i]->arrivalTime;
        queue[i]->startTime     = queue2[i]->startTime;
        queue[i]->endTime       = queue2[i]->endTime;
        queue[i]->remainingTime = queue2[i]->remainingTime;
        queue[i]->stopTime      = queue2[i]->stopTime;
        queue[i]->done          = queue2[i]->done;
    }

    return 0;
}
