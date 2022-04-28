#ifndef __LISTBASEQUEUE_H__
#define __LISTBASEQUEUE_H__

#define TRUE  1
#define FALSE 0

typedef struct _node {
  int data;
  struct _node *next;
}Node;

typedef struct _queue{
  Node *tail;
}Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);
void Enqueue(Queue *pq, int data);
int Dequeue(Queue *pq);
int Qpeek(Queue *pq);

#endif /* ifndef __LISTBASEQUEUE_H__*/
