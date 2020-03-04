#pragma once
/*
	//In order to find —— 顺序查找
	/*
			对于任意一个序列以及一个给定的元素，将给定元素与序列中元素依次比较，
		直到找出与给定关键字相同的元素，或者将序列中的元素与其都比较完为止。

		顺序查找
		时间复杂度：O(n)
		条件：无序或有序队列
		按顺序比较每个元素，直到找到关键字为止
*/

template<class T>
int order(T *arr, int arr_size, T x)
{
	int i;
	for (i = 0; i < arr_size; i++)	//按顺序遍历序列
	{
		if (arr[i] == x)
			return i;	//顺利与给定元匹配时返回元素所属下标；
	}
	if (i == arr_size)
		return -1;	//整个序列没有指定元素时，返回-1；
}
