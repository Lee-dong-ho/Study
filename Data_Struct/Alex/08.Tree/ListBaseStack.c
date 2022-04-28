#include "ListBaseStack.h"
#include <stdlib.h>
#include <stdio.h>

void PrintList(Stack *pstack)
{
    if (pstack->head == NULL)
    {
        printf("NULL\n");
        return;
    }
    Node *pos = pstack->head;
    printf("%x(%d)", pos, pos->data);
    while(1) {
        if (pos->next == NULL)
        {
            printf(" -> NULL");
            break;
        }
        pos = pos->next;
        printf(" -> %x(%d)", pos, pos->data);
    }
    printf("\n");
}

void StackInit(Stack *pstack)
{
    pstack->head = NULL;
}

int SIsEmpty(Stack *pstack)
{
    if (pstack->head == NULL) return TRUE;
    return FALSE;
}

void SPush(Stack *pstack, int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->head;

    pstack->head = newNode;
}

int SPop(Stack *pstack)
{
    if (SIsEmpty(pstack)) {
        printf("[Error] Stack is empty!\n");
        exit(-1);
    }

    Node *rnode = pstack->head;
    int rdata = rnode->data;

    free(rnode);
    pstack->head = pstack->head->next;
    return rdata;
}

int SPeek(Stack *pstack)
{
    if (SIsEmpty(pstack)) {
        printf("[Error] Stack is empty!\n");
        exit(-1);
    }

    return pstack->head->data;
}
