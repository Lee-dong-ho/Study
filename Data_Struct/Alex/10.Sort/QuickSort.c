#include <stdio.h>
#define SIZE    9

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void QuickSort(int arr[], int left, int right)
{
    if (left > right) return;
    int pivot = left;
    int low = left+1;
    int high = right;

    while(low <= high) {
        while(arr[pivot] > arr[low] && low <= right)
            low++;
        while(arr[pivot] < arr[high] && high > left)
            high--;
        if (low <= high)
            swap(&arr[low], &arr[high]);
    }
    swap(&arr[pivot], &arr[high]);
    QuickSort(arr, left, high-1);
    QuickSort(arr, high+1, right);
}

int main(void)
{
    int arr[SIZE] = {3, 4, 5, 2, 7, 6, 9, 1, 8};

    printf("[Quick Sort]\n");
    for (int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    QuickSort(arr, 0, SIZE-1);

    for (int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
