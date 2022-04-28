#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE  1
#define FALSE 0

typedef struct _node {
  int data;
  struct _node *next;
}Node;

typedef struct _deque {
  Node *front;
  Node *rear;
}Deque;

void DequeInit(Deque *pdeq);
int DQIsEmpty(Deque *pdeq);
void DQAddFirst(Deque *pdeq, int data);
void DQAddLast(Deque *pdeq, int data);
int DQRemoveFirst(Deque *pdeq);
int DQRemoveLast(Deque *pdeq);
int DQGetFirst(Deque *pdeq);
int DQGetLast(Deque *pdeq);

#endif /* ifndef __DEQUE_H__*/
