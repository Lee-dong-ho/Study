#include <stdio.h>
#include "ListBaseQueue.h"
#define SIZE    9
#define BUCKET_NUM  10

void RadixSort(int arr[], int size, int maxLen)
{
    int i, j, radix, idx;
    int divfac = 1;
    Queue buckets[BUCKET_NUM];
    for (i=0; i <BUCKET_NUM; i++)
        QueueInit(&buckets[i]);

    for (j=1; j <= maxLen; j++) {
        for (i=0; i < size; i++) {
            radix = arr[i]/divfac%10;
            Enqueue(&buckets[radix], arr[i]);
        }
        for (i=0, idx=0; i < BUCKET_NUM; i++)
            while(!QIsEmpty(&buckets[i]))
                arr[idx++] = Dequeue(&buckets[i]);
        divfac *= 10;
    }
}

int main(void)
{
    int arr[SIZE] = {13, 14, 212, 7141, 10987, 6, 15, 118, 871};

    printf("[Radix Sort]\n");
    for (int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    RadixSort(arr, SIZE, 5);

    for (int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
