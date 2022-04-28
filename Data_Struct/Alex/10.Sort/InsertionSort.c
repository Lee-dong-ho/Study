#include <stdio.h>
#define SIZE    9

void InsertionSort(int arr[], int size)
{
    int i,j,temp;
    for (i=1; i < size; i++) {
        temp = arr[i];
        for (j=i-1; j >= 0; j--) {
            if(arr[j] > temp)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = temp;
    }
}

int main(void)
{
    int arr[SIZE] = {3, 4, 5, 2, 7, 6, 9, 1, 8};

    printf("[Insertion Sort]\n");
    for (int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    InsertionSort(arr, SIZE);

    for (int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
