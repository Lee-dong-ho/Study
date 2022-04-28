#include <stdio.h>
#include "SimpleHeap.h"

static int GetLChildIdx(int idx);
static int GetRChildIdx(int idx);
static int GetParentIdx(int idx);
static int GetChildIdx(Heap *ph, int idx);

void PrintHeap(Heap *ph)
{
    int level = 1;
    for (int i=0; i <= ph->idx; i++) {
        if (i == level) {
            printf("\n");
            level = i*2+1;
        }
        printf("%c[%d] ", ph->heapArr[i].data, ph->heapArr[i].pr);
    }
    printf("\n");
}

static int GetLChildIdx(int idx)
{
    return idx*2+1;
}

static int GetRChildIdx(int idx)
{
    return idx*2+2;
}

static int GetParentIdx(int idx)
{
    return (idx-1)/2;
}

static int GetChildIdx(Heap *ph, int idx)
{
    int l = GetLChildIdx(idx);
    int r = GetRChildIdx(idx);

    if (l > ph->idx)
        return 0;
    else if (l == ph->idx)
        return l;
    else if (ph->heapArr[l].pr <= ph->heapArr[r].pr)
        return l;
    else
        return r;
}

void HeapInit(Heap *ph)
{
    ph->idx = -1;
}

int HIsEmpty(Heap *ph)
{
    if (ph->idx == -1) return TRUE;
    return FALSE;
}

void HInsert(Heap *ph, char data, int pr)
{
    if (ph->idx == HEAP_LEN-1) return;
    ph->idx++;
    EHeap newData = {data, pr};

    int child = ph->idx;
    while(child != 0) {
        int parent = GetParentIdx(child);
        if (ph->heapArr[parent].pr > pr) {
            ph->heapArr[child] = ph->heapArr[parent];
            child = parent;
        }
        else break;
    }
    ph->heapArr[child] = newData;
    printf("[HInsert] %c %d\n", data, pr);
    PrintHeap(ph);
}

char HDelete(Heap *ph)
{
    if (HIsEmpty(ph)) return -1;
    char deldata = ph->heapArr[0].data;
    EHeap lastData = ph->heapArr[ph->idx];
    ph->idx--;

    int parent = 0;
    int child;
    while(child = GetChildIdx(ph, parent)) {
        if (ph->heapArr[child].pr >= lastData.pr)
            break;
        ph->heapArr[parent] = ph->heapArr[child];
        parent = child;
    }
    ph->heapArr[parent] = lastData;

    printf("[HDelete] %c\n", deldata);
    PrintHeap(ph);
    return deldata;
}

