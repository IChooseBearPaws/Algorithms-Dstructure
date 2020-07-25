#pragma once
/*
 *	Binary Search 折半查找(二分查找)
 *
 *	时间复杂度：O(log2n)
 *	条件：有序队列
*/

template<class T>
int binary(T *arr, int arr_size, T x)
{
	int mid, Low = 0, High = arr_size - 1;

	while (Low <= High)
	{
		mid = (Low + High) / 2;
		if (arr[mid] == x)
			return mid;
		else if (arr[mid] > x)
		{
			High = mid - 1;
		}
		else if (arr[mid] < x)
		{
			Low = mid + 1;
		}
	}
	return -1;
}