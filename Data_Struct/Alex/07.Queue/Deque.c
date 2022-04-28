#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void PrintDeque(Deque *pdeq)
{
    if (pdeq->front == NULL) {
        printf("NULL\n");
        return;
    }
    Node *pos = pdeq->front;
    printf("%x(%d)", pos, pos->data);
    pos = pos->next;

    while(1) {
        if (pos == NULL) {
            printf(" -> NULL");
            break;
        }
        printf(" -> %x(%d)", pos, pos->data);
        pos = pos->next;
    }
    printf("\n");
}

void DequeInit(Deque *pdeq)
{
    pdeq->front = NULL;
    pdeq->rear = NULL;
}

int DQIsEmpty(Deque *pdeq)
{
    if (pdeq->front == NULL) return TRUE;
    return FALSE;
}

void DQAddFirst(Deque *pdeq, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;

    if (pdeq->front == NULL) {
        newNode->next = NULL;
        pdeq->rear = newNode;
    }
    else
        newNode->next = pdeq->front;
    pdeq->front = newNode;
    printf("DQAddFirst(%d): ", data);
    PrintDeque(pdeq);
}

void DQAddLast(Deque *pdeq, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (pdeq->rear == NULL)
        pdeq->front = newNode;
    else
        pdeq->rear->next = newNode;
    pdeq->rear = newNode;
    printf("DQAddLast(%d):  ", data);
    PrintDeque(pdeq);
}

int DQRemoveFirst(Deque *pdeq)
{
    Node *delNode = pdeq->front;
    int deldata = delNode->data;

    if (pdeq->front == pdeq->rear)
        pdeq->rear = NULL;
    pdeq->front = pdeq->front->next;

    printf("DQRemoveFirst(%d): ", deldata);
    PrintDeque(pdeq);
    free(delNode);
    return deldata;
}

int DQRemoveLast(Deque *pdeq)
{
    Node *delNode = pdeq->rear;
    int deldata = delNode->data;

    if (pdeq->front == pdeq->rear) {
        pdeq->rear = NULL;
        pdeq->front = NULL;
    }
    else {
        Node *pos = pdeq->front;
        while(1) {
            if (pos->next == pdeq->rear) break;
            pos = pos->next;
        }
        pdeq->rear = pos;
        pdeq->rear->next = NULL;
    }

    printf("DQRemoveLast(%d):  ", deldata);
    PrintDeque(pdeq);
    free(delNode);
    return deldata;
}

int DQGetFirst(Deque *pdeq)
{
    return pdeq->front->data;
}

int DQGetLast(Deque *pdeq)
{
    return pdeq->rear->data;
}
