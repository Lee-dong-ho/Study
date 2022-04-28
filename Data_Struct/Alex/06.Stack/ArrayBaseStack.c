#include "ArrayBaseStack.h"
#include <stdio.h>

void PrintList(Stack *pstack)
{
    for (int i=0; i <= pstack->idx; i++) {
        printf("[%d]", pstack->data[i]);
    }
    printf("\n");
}

void StackInit(Stack *pstack)
{
    pstack->idx = -1;
}

int SIsEmpty(Stack *pstack)
{
    if (pstack->idx == -1) return TRUE;
    else return FALSE;
}

void SPush(Stack *pstack, int data)
{
    if (pstack->idx == SIZE-1-1)
    {
        printf("[Error] Stack have been full!\n");
        return;
    }

    pstack->idx++;
    pstack->data[pstack->idx] = data;
    printf("SPush(%d): ", data);
    PrintList(pstack);
}

int SPop(Stack *pstack)
{
    if (SIsEmpty(pstack))
    {
        printf("[Error] Stack is empty!\n");
        return -1;
    }

    int res = pstack->data[pstack->idx];
    pstack->idx--;
    printf("SPop(%d) : ", res);
    PrintList(pstack);
    return res;
}

int SPeek(Stack *pstack)
{
    if (SIsEmpty(pstack))
    {
        printf("[Error] Stack is empty!\n");
        return -1;
    }

    return pstack->data[pstack->idx];
}
