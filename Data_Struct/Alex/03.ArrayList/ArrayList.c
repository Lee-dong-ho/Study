#include "ArrayList.h"
#include <stdio.h>

void PrintList(List *plist)
{
    printf("{ ");
    for (int i=0; i < plist->idx; i++) {
        printf("%d:%d ", i, plist->data[i]);
    }
    printf("}\n");
}

void ListInit(List *plist)
{
    plist->cur = 0;
    plist->idx = 0;
}

void LInsert(List *plist, int data)
{
    if (plist->idx >= LIST_LEN) return;
    plist->data[plist->idx] = data;
    plist->idx++;
    printf("LInsert: ");
    PrintList(plist);
}

int LFirst(List *plist, int *pdata)
{
    if (plist->idx < 1) return FALSE;
    *pdata = plist->data[0];
    plist->cur = 1;
    return TRUE;
}

int LNext(List *plist, int *pdata)
{
    if (plist->idx < plist->cur + 1) return FALSE;
    *pdata = plist->data[plist->cur];
    plist->cur++;
    return TRUE;
}

int LRemove(List *plist)
{
    plist->cur--;
    int temp = plist->data[plist->cur];
    for (int i=plist->cur; i < plist->idx-1; i++)
    {
        plist->data[i] = plist->data[i+1];
    }
    plist->idx--;
    printf("LRemove: ");
    PrintList(plist);
    return temp;
}

int LCount(List *plist)
{
    return plist->idx;
}
