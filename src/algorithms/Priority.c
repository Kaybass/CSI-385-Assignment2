#include "Priority.h"


runStats * PRIscheduler(Process ** queue, int length){

    int i, s = 1;
    Process * t;

    while (s) {

        s = 0;

        for (i = 1; i < length; i++) {

            if (queue[i]->priority < queue[i - 1]->priority) {

                t = queue[i];
                queue[i] = queue[i - 1];
                queue[i - 1] = t;
                s = 1;
            }
        }
    }

    float averageWait = 0;

    float averageTurn = 0;

    int toki = 0;

    for(int i = 0; i < length; i++){
        averageWait += toki;

        queue[i]->startTime = toki;

        queue[i]->endTime = queue[i]->burstTime + toki;

        toki = queue[i]->endTime;

        averageTurn += queue[i]->endTime;
    }

    runStats * myStats = (runStats*)malloc(sizeof(runStats));

    myStats->averageWaittime       = averageWait/(float)length;
    myStats->averageTurnaroundtime = averageTurn/(float)length;

    return myStats;
}