#include "RR.h"



runStats * RRscheduler(Process ** queue, int length){

    int i, s = 1;
    Process * t;

    while (s) {

        s = 0;

        for (i = 1; i < length; i++) {

            if (queue[i]->arrivalTime < queue[i - 1]->arrivalTime) {

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

    int finished = 0;

    while(finished < length){

        for(int i = 0; i < length; i++){

            if(queue[i]->done != 't'){

                averageWait += toki - queue[i]->stopTime;

                if(queue[i]->burstTime == queue[i]->remainingTime)
                    queue[i]->startTime = toki;

                if(queue[i]->remainingTime > QUANTUM){

                    queue[i]->remainingTime = queue[i]->remainingTime - QUANTUM;

                    toki += QUANTUM;

                    queue[i]->stopTime = toki;
                }
                else if(queue[i]->remainingTime == QUANTUM){

                    queue[i]->done = 't';

                    finished++;

                    toki += QUANTUM;

                    queue[i]->endTime = toki;

                    averageTurn += toki;
                }
                else{

                    queue[i]->done = 't';

                    finished++;

                    toki += queue[i]->remainingTime;

                    queue[i]->endTime = toki;

                    averageTurn += toki;
                }
            }
        }
    }

    runStats * myStats = (runStats*)malloc(sizeof(runStats));

    myStats->averageWaittime       = averageWait/(float)length;
    myStats->averageTurnaroundtime = averageTurn/(float)length;

    return myStats;
}


runStats * RRPscheduler(Process ** queue, int length){

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

    int finished = 0;

    while(finished < length){

        for(int i = 0; i < length; i++){

            if(queue[i]->done != 't'){

                averageWait += toki - queue[i]->stopTime;

                if(queue[i]->burstTime == queue[i]->remainingTime)
                    queue[i]->startTime = toki;

                if(queue[i]->remainingTime > QUANTUM){

                    queue[i]->remainingTime = queue[i]->remainingTime - QUANTUM;

                    toki += QUANTUM;

                    queue[i]->stopTime = toki;
                }
                else if(queue[i]->remainingTime == QUANTUM){

                    queue[i]->done = 't';

                    finished++;

                    toki += QUANTUM;

                    queue[i]->endTime = toki;

                    averageTurn += toki;
                }
                else{

                    queue[i]->done = 't';

                    finished++;

                    toki += queue[i]->remainingTime;

                    queue[i]->endTime = toki;

                    averageTurn += toki;
                }
            }
        }
    }

    runStats * myStats = (runStats*)malloc(sizeof(runStats));

    myStats->averageWaittime       = averageWait/(float)length;
    myStats->averageTurnaroundtime = averageTurn/(float)length;

    return myStats;
}
