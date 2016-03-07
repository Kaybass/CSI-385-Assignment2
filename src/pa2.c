#include "Process.h"
#include "algorithms/FIFO.h"
#include "algorithms/STF.h"
#include "algorithms/RR.h"
#include "algorithms/Priority.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define ABITRARYQUEUELENGTH 10
#define QUEUEAMOUNT         5


int main(){

    Process * Queue1[ABITRARYQUEUELENGTH],
            * Queue2[ABITRARYQUEUELENGTH],
            * Queue3[ABITRARYQUEUELENGTH],
            * Queue4[ABITRARYQUEUELENGTH],
            * Queue5[ABITRARYQUEUELENGTH];

    generateProcesses(Queue1,ABITRARYQUEUELENGTH);
    qCopy(Queue2,Queue1,ABITRARYQUEUELENGTH);
    qCopy(Queue3,Queue1,ABITRARYQUEUELENGTH);
    qCopy(Queue4,Queue1,ABITRARYQUEUELENGTH);
    qCopy(Queue5,Queue1,ABITRARYQUEUELENGTH);

    printf("QUEUE\n");
    for(int i = 0; i < ABITRARYQUEUELENGTH; i++){
        printf("PID = %2d; PRIORITY = %d; BURSTTIME = %2d; ARRIVALTIME = %d;\n", Queue3[i]->pid,
                                                                            Queue3[i]->priority,
                                                                            Queue3[i]->burstTime,
                                                                            Queue3[i]->arrivalTime);
    }

    runStats * stats[QUEUEAMOUNT];

    stats[0] = FIFOscheduler(Queue1,ABITRARYQUEUELENGTH);
    stats[1] = STFscheduler(Queue2,ABITRARYQUEUELENGTH);
    stats[2] = PRIscheduler(Queue3,ABITRARYQUEUELENGTH);
    stats[3] = RRscheduler(Queue4,ABITRARYQUEUELENGTH);
    stats[4] = RRPscheduler(Queue5,ABITRARYQUEUELENGTH);

    printf("\nFIFO\n");
    for(int i = 0; i < ABITRARYQUEUELENGTH; i++){
        printf("PID = %2d; START = %3d; END = %3d;\n", Queue1[i]->pid, Queue1[i]->startTime, Queue1[i]->endTime);
    }
    printf("Average Turn Around:%2f; Average Wait:%2f;\n", stats[0]->averageTurnaroundtime, stats[0]->averageWaittime);

    printf("\nSTF\n");
    for(int i = 0; i < ABITRARYQUEUELENGTH; i++){
        printf("PID = %2d; START = %3d; END = %3d;\n", Queue2[i]->pid, Queue2[i]->startTime, Queue2[i]->endTime);
    }
    printf("Average Turn Around:%2f; Average Wait:%2f;\n", stats[1]->averageTurnaroundtime, stats[1]->averageWaittime);

    printf("\nPRI\n");
    for(int i = 0; i < ABITRARYQUEUELENGTH; i++){
        printf("PID = %2d; START = %3d; END = %3d;\n", Queue3[i]->pid, Queue3[i]->startTime, Queue3[i]->endTime);
    }
    printf("Average Turn Around:%2f; Average Wait:%2f;\n", stats[2]->averageTurnaroundtime, stats[2]->averageWaittime);

    printf("\nRR\n");
    for(int i = 0; i < ABITRARYQUEUELENGTH; i++){
        printf("PID = %2d; START = %3d; END = %3d;\n", Queue4[i]->pid, Queue4[i]->startTime, Queue4[i]->endTime);
    }
    printf("Average Turn Around:%2f; Average Wait:%2f;\n", stats[3]->averageTurnaroundtime, stats[3]->averageWaittime);

    printf("\nRR with priority\n");
    for(int i = 0; i < ABITRARYQUEUELENGTH; i++){
        printf("PID = %2d; START = %3d; END = %3d;\n", Queue5[i]->pid, Queue5[i]->startTime, Queue5[i]->endTime);
    }
    printf("Average Turn Around:%2f; Average Wait:%2f;\n", stats[4]->averageTurnaroundtime, stats[4]->averageWaittime);

    for(int i = 0; i < ABITRARYQUEUELENGTH; i++){
        if (Queue1[i])
        {
            free(Queue1[i]);
        }
        if (Queue2[i])
        {
            free(Queue2[i]);
        }
        if (Queue3[i])
        {
            free(Queue3[i]);
        }
        if (Queue4[i])
        {
            free(Queue4[i]);
        }
        if (Queue5[i])
        {
            free(Queue5[i]);
        }
    }
    for(int i = 0; i < QUEUEAMOUNT; i++){
        if(stats[i])
            free(stats[i]);
    }

    return 0;
}
