#include "ListBaseQueue.h"
#include <stdio.h>
#include <stdlib.h>

void PrintQueue(Queue *pq)
{
    if (pq->tail == NULL)
    {
        printf("NULL\n");
        return;
    }
    Node *pos = pq->tail->next;
    Node *head = pq->tail->next;

    printf("%x(%d)", pos, pos->data);
    pos = pos->next;
    while(pos != head) {
        printf(" -> %x(%d)", pos, pos->data);
        pos = pos->next;
    }
    printf("\n");
}

void QueueInit(Queue *pq)
{
    pq->tail = NULL;
}

int QIsEmpty(Queue *pq)
{
    if (pq->tail == NULL) return TRUE;
    return FALSE;
}

void Enqueue(Queue *pq, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    if (pq->tail == NULL) {
        newNode->next = newNode;
    }
    else {
        newNode->next = pq->tail->next;
        pq->tail->next = newNode;
    }
    pq->tail = newNode;
    printf("Enqueue(%d): ", data);
    PrintQueue(pq);
}

int Dequeue(Queue *pq)
{
    if (QIsEmpty(pq)) {
        printf("[Error] Queue Memory Empty!\n");
        return -1;
    }
    Node *dqnode = pq->tail->next;
    int dqdata = dqnode->data;

    if (pq->tail == pq->tail->next) pq->tail = NULL;
    else pq->tail->next = pq->tail->next->next;
    printf("Dequeue(%d): ", dqdata);
    PrintQueue(pq);
    free(dqnode);
    return dqdata;
}

int Qpeek(Queue *pq)
{
    if (QIsEmpty(pq)) {
        printf("[Error] Queue Memory Empty!\n");
        return -1;
    }
    return pq->tail->next->data;
}
