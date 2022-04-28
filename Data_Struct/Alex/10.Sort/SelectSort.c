#include <stdio.h>
#define SIZE    9

void SelectSort(int arr[], int size)
{
    for (int i=0; i < size-1; i++) {
        int min = i;
        for (int j=i+1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min == i) continue;
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main(void)
{
    int arr[SIZE] = {3, 4, 5, 2, 7, 6, 9, 1, 8};

    printf("[Select Sort]\n");
    for (int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    SelectSort(arr, SIZE);

    for (int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
