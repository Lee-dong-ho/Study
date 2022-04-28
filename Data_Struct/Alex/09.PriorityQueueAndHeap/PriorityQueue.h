#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

#include "UsefulHeap.h"

typedef Heap PQueue;

void PQueueInit(PQueue *ppq, PriorityComp pc);
int PQIsEmpty(PQueue *ppq);
void PEnqueue(PQueue *ppq, int data);
int PDequeue(PQueue *ppq);

#endif /* ifndef __PRIORITYQUEUE_H__ */
