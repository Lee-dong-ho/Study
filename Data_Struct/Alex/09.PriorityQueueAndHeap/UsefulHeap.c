#include <stdio.h>
#include "UsefulHeap.h"

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
        printf("%c ", ph->heapArr[i]);
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
    else if (ph->comp(ph->heapArr[l], ph->heapArr[r]) < 0)
        return r;
    else
        return l;
}

void HeapInit(Heap *ph, PriorityComp pc)
{
    ph->idx = -1;
    ph->comp = pc;
}

int HIsEmpty(Heap *ph)
{
    if (ph->idx == -1) return TRUE;
    return FALSE;
}

void HInsert(Heap *ph, char data)
{
    if (ph->idx == HEAP_LEN-1) return;
    ph->idx++;

    int child = ph->idx;
    while(child != 0) {
        int parent = GetParentIdx(child);
        if (ph->comp(ph->heapArr[parent], data) < 0) {
            ph->heapArr[child] = ph->heapArr[parent];
            child = parent;
        }
        else break;
    }
    ph->heapArr[child] = data;
    printf("[HInsert] %c\n", data);
    PrintHeap(ph);
}

char HDelete(Heap *ph)
{
    if (HIsEmpty(ph)) return -1;
    char deldata = ph->heapArr[0];
    char lastData = ph->heapArr[ph->idx];
    ph->idx--;

    int parent = 0;
    int child;
    while(child = GetChildIdx(ph, parent)) {
        if (ph->comp(ph->heapArr[child], lastData) <= 0)
            break;
        ph->heapArr[parent] = ph->heapArr[child];
        parent = child;
    }
    ph->heapArr[parent] = lastData;

    printf("[HDelete] %c\n", deldata);
    PrintHeap(ph);
    return deldata;
}

