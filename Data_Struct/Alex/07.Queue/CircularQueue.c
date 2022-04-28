#include "CircularQueue.h"
#include <stdio.h>

void PrintQueue(Queue *pq)
{
    int idx = pq->front;
    while(idx != pq->rear) {
        idx = (idx+1)%SIZE;
        printf("[%d]", pq->data[idx]);
    }
    printf("\n");
}

void QueueInit(Queue *pq)
{
    pq->front = -1;
    pq->rear = -1;
}

int QIsEmpty(Queue *pq)
{
    if (pq->rear == pq->front) return TRUE;
    return FALSE;
}

void Enqueue(Queue *pq, int data)
{
    if ((pq->rear+1)%SIZE == pq->front
            || pq->rear == SIZE-1 && pq->front == -1) return;
    pq->rear = (pq->rear+1)%SIZE;
    pq->data[pq->rear] = data;
    printf("Enqueue(%d): ", data);
    PrintQueue(pq);
}

int Dequeue(Queue *pq)
{
    if (QIsEmpty(pq)) {
        printf("[Error] Queue Memory Empty!\n");
        return;
    }
    pq->front = (pq->front+1)%SIZE;
    printf("Dequeue(%d): ", pq->data[pq->front]);
    PrintQueue(pq);
    return pq->data[pq->front];
}

int Qpeek(Queue *pq)
{
    if (QIsEmpty(pq)) {
        printf("[Error] Queue Memory Empty!\n");
        return;
    }
    return pq->data[(pq->front+1)%SIZE];
}
