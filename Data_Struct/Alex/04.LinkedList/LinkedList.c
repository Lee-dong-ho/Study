#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

void PrintList(List *plist)
{
    Node *pos = plist->head;
    printf("%x(head)", pos);
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

void ListInit(List *plist)
{
    plist->head = malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->tail = plist->head;
    plist->numOfData = 0;
}

void LInsert(List *plist, int data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    plist->tail->next = new_node;
    plist->tail = new_node;
    plist->numOfData++;
    printf("LInsert: ");
    PrintList(plist);
}

int LFirst(List *plist, int *pdata)
{
    if (plist->head->next == NULL) return FALSE;
    plist->before = plist->head;
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, int *pdata)
{
    if (plist->cur->next == NULL) return FALSE;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LRemove(List *plist)
{
    Node *rnode = plist->cur;
    int rdata = rnode->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rnode);
    plist->numOfData--;
    printf("LInsert: ");
    PrintList(plist);
    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}
