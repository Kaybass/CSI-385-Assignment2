#include "../Process.h"


#ifndef RR
#define RR

#define QUANTUM 10

runStats * RRscheduler(Process ** queue, int length);


runStats * RRPscheduler(Process ** queue, int length);

#endif
