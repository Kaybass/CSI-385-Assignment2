#include "STF.h"

runStats * STFscheduler(Process ** queue, int length){

    int i, s = 1;
    Process * t;

    //sort process according to algorithm spec
    while (s) {

        s = 0;

        for (i = 1; i < length; i++) {

            if (queue[i]->burstTime < queue[i - 1]->burstTime){

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

    //run processes
    for(int i = 0; i < length; i++){
        averageWait += toki;

        queue[i]->startTime = toki;

        queue[i]->endTime = queue[i]->burstTime + toki;

        toki = queue[i]->endTime;

        averageTurn += queue[i]->endTime;
    }

    //Collect Statistics
    runStats * myStats = (runStats*)malloc(sizeof(runStats));

    myStats->averageWaittime       = averageWait/(float)length;
    myStats->averageTurnaroundtime = averageTurn/(float)length;

    return myStats;
}
