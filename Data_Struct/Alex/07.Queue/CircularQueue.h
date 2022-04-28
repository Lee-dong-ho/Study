#ifndef __CIRCULARQUEUE_H__
#define __CIRCULARQUEUE_H__

#define TRUE  1
#define FALSE 0
#define SIZE  100

typedef struct _queue{
  int front;
  int rear;
  int data[SIZE];
}Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);
void Enqueue(Queue *pq, int data);
int Dequeue(Queue *pq);
int Qpeek(Queue *pq);

#endif /* ifndef __CIRCULARQUEUE_H__*/
