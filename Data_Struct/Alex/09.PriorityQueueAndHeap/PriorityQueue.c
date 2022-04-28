#include <stdio.h>
#include "PriorityQueue.h"

void PQueueInit(PQueue *ppq, PriorityComp pc)
{
    HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue *ppq)
{
    return HIsEmpty(ppq);
}

void PEnqueue(PQueue *ppq, int data)
{
    HInsert(ppq, data);
}

int PDequeue(PQueue *ppq)
{
    return HDelete(ppq);
}

