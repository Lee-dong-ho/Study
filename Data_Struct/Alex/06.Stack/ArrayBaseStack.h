#ifndef __ARRAYBASESTACK_H__
#define __ARRAYBASESTACK_H__

#define TRUE  1
#define FALSE 0
#define SIZE  100

typedef struct _stack{
  int idx;
  int data[SIZE];
}Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);
void SPush(Stack *pstack, int data);
int SPop(Stack *pstack);
int SPeek(Stack *pstack);

#endif
