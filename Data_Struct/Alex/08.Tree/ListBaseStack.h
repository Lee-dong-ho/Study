#ifndef __LISTBASESTACK_H__
#define __LISTBASESTACK_H__

#define TRUE  1
#define FALSE 0

typedef struct _node{
  int data;
  struct _node *next;
}Node;

typedef struct _stack{
  Node *head;
}Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);
void SPush(Stack *pstack, int data);
int SPop(Stack *pstack);
int SPeek(Stack *pstack);

#endif
