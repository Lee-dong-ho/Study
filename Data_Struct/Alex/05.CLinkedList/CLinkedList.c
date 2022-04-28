#include "CLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

void PrintList(List *plist)
{
    Node *pos = plist->tail->next;
    printf("%x(%d)", pos, pos->data);
    while(1) {
        if (pos->next == plist->tail->next)
        {
            printf(" -> %x(head)", pos->next);
            break;
        }
        pos = pos->next;
        printf(" -> %x(%d)", pos, pos->data);
    }
    printf("\n");
}

void ListInit(List *plist)
{
    plist->tail = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, int data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    if (plist->tail == NULL) {
        plist->tail = new_node;
        new_node->next = new_node;
    }
    else {
        new_node->next = plist->tail->next;
        plist->tail->next = new_node;
        plist->tail = new_node;
    }
    plist->numOfData++;
    printf("LInsert: ");
    PrintList(plist);
}

void LInsertFront(List *plist, int data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;

    if (plist->tail == NULL) {
        plist->tail = new_node;
        new_node->next = new_node;
    }
    else {
        new_node->next = plist->tail->next;
        plist->tail->next = new_node;
    }

    plist->numOfData++;
    printf("LInsertSront: ");
    PrintList(plist);
}

int LFirst(List *plist, int *pdata)
{
    if (plist->tail == NULL) return FALSE;

    plist->before = plist->tail;
    plist->cur = plist->tail->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, int *pdata)
{
    if (plist->tail == NULL) return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LRemove(List *plist)
{
    Node *rnode = plist->cur;
    int rdata = rnode->data;

    if (rnode == plist->tail) {
        if (plist->tail == plist->tail->next) plist->tail = NULL;
        else plist->tail = plist->before;
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rnode);
    plist->numOfData--;
    printf("LRemove: ");
    PrintList(plist);
    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}
