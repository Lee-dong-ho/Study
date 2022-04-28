#include <stdio.h>
#include "UsefulHeap.h"
#define SIZE    9

int PriComp(int n1, int n2)
{
    return n2-n1;
}

void HeapSort(int arr[], int size)
{
    Heap heap;
    HeapInit(&heap, PriComp);

    for(int i=0; i < size; i++)
        HInsert(&heap, arr[i]);
    for(int i=0; i < size; i++)
        arr[i] = HDelete(&heap);
}

int main(void)
{
    int arr[SIZE] = {3, 4, 5, 2, 7, 6, 9, 1, 8};

    printf("[Heap Sort]\n");
    for (int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    HeapSort(arr, SIZE);

    for (int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
