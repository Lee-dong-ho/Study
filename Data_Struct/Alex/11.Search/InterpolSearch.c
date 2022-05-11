#include <stdio.h>

int BSearchRecur(int arr[], int first, int last, int target)
{
	if(arr[first] > target || target > arr[last])
		return -1;
	int s = (double)((target - arr[first]) * (last - first)) / (arr[last] - arr[first]) + first;

	if(arr[s] == target)
		return s;
	else if(target < arr[s])
		return BSearchRecur(arr, first, s-1, target);
	else
		return BSearchRecur(arr, s+1, last, target);
}

int main(void)
{
	int arr[] = {1, 3, 5, 7, 9};
	int idx;

	idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 7);
	if(idx == -1)
		printf("Search Fail!!\n");
	else
		printf("Result Index : %d\n", idx);

	idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 2);
	if(idx == -1)
		printf("Search Fail!!\n");
	else
		printf("Result Index : %d\n", idx);

	return 0;
}
