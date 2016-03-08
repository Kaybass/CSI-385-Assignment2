#include "RR.h"



runStats * RRscheduler(Process ** queue, int length){

    //sort the processes into the order they should be processed in
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

    int toki = 0; //time

    int finished = 0;

    //run the processes
    while(finished < length){

        for(int i = 0; i < length; i++){

            if(queue[i]->done != 't'){

                //add to wait time calculation
                averageWait += toki - queue[i]->stopTime;

                //If this is the first time running the process make the current time the start time
                if(queue[i]->burstTime == queue[i]->remainingTime)
                    queue[i]->startTime = toki;

                //If the process will not finish within the allocated time quantum
                if(queue[i]->remainingTime > QUANTUM){

                    queue[i]->remainingTime = queue[i]->remainingTime - QUANTUM;

                    toki += QUANTUM;

                    queue[i]->stopTime = toki;
                }

                //The process will exactly finish within the allocated time quantum
                else if(queue[i]->remainingTime == QUANTUM){

                    queue[i]->done = 't';

                    finished++;

                    toki += QUANTUM;

                    queue[i]->endTime = toki;

                    averageTurn += toki;
                }

                //the process will finish before the time quantum ends
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

    //setup to return run stats
    runStats * myStats = (runStats*)malloc(sizeof(runStats));

    myStats->averageWaittime       = averageWait/(float)length;
    myStats->averageTurnaroundtime = averageTurn/(float)length;

    return myStats;
}


runStats * RRPscheduler(Process ** queue, int length){


    //Sort processes by priority
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

    int toki = 0; //time

    int finished = 0;

    //run the processes
    while(finished < length){

        for(int i = 0; i < length; i++){

            if(queue[i]->done != 't'){

                //add to wait time calculation
                averageWait += toki - queue[i]->stopTime;

                //If this is the first time running the process make the current time the start time
                if(queue[i]->burstTime == queue[i]->remainingTime)
                    queue[i]->startTime = toki;

                //If the process will not finish within the allocated time quantum
                if(queue[i]->remainingTime > QUANTUM){

                    queue[i]->remainingTime = queue[i]->remainingTime - QUANTUM;

                    toki += QUANTUM;

                    queue[i]->stopTime = toki;
                }

                //The process will exactly finish within the allocated time quantum
                else if(queue[i]->remainingTime == QUANTUM){

                    queue[i]->done = 't';

                    finished++;

                    toki += QUANTUM;

                    queue[i]->endTime = toki;

                    averageTurn += toki;
                }

                //the process will finish before the time quantum ends
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

    //setup to return run stats
    runStats * myStats = (runStats*)malloc(sizeof(runStats));

    myStats->averageWaittime       = averageWait/(float)length;
    myStats->averageTurnaroundtime = averageTurn/(float)length;

    return myStats;
}
