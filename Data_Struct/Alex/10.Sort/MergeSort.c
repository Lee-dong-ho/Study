#include <stdio.h>
#define SIZE    9

void PrintArr(int arr[], char* str)
{
    printf("[%s] ", str);
    for (int i=0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void MergeArr(int arr[], int left, int mid, int right)
{
    int i, j, temp;
    for (i=mid+1; i <= right; i++) {
        temp = arr[i];
        //PrintArr(arr, "Before");
        for (j=mid; j >= left; j--) {
            if (arr[j] > temp)
                arr[j+1] = arr[j];
            else
                break;
        }
        if (j == mid) continue;
        arr[j+1] = temp;
        printf("i=%d j=%d left=%d mid=%d right=%d\n", i, j, left, mid, right);
        PrintArr(arr, "After ");
        i--;
        mid++;
    }
}
/*void MergeArr(int arr[], int left, int mid, int right)
{
    int fidx = left;
    int ridx = mid+1;
    int sidx = left;
    int *sortArr = malloc(sizeof(int)*(right+1));

    while(fidx <= mid && ridx <= right) {
        if (arr[fidx] <= arr[ridx])
            sortArr[sidx++] = arr[fidx++];
        else
            sortArr[sidx++] = arr[ridx++];
    }

    if (fidx > mid) {
        for (int i=ridx; i <= right; i++, sidx++)
            sortArr[sidx] = arr[i];
    }
    else {
        for (int i=fidx; i <= mid; i++, sidx++)
            sortArr[sidx] = arr[i];
    }

    for (int i=left; i <= right; i++)
        arr[i] = sortArr[i];

    free(sortArr);
}*/

void MergeSort(int arr[], int left, int right)
{
    if (left == right) return;

    int mid = (left+right)/2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);
    MergeArr(arr, left, mid, right);
}

int main(void)
{
    int arr[SIZE] = {3, 4, 5, 2, 7, 6, 9, 1, 8};

    printf("[Merge Sort]\n");
    for (int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    MergeSort(arr, 0, SIZE-1);

    for (int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
