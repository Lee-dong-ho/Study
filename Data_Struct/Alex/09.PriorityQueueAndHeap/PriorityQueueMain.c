#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2-ch1;
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	PDequeue(&pq);

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	PDequeue(&pq);

	while(!PQIsEmpty(&pq))
    PDequeue(&pq);

	return 0;
}
