#pragma once

/*
	//Insertion_sort¡ª¡ª²åÈëÅÅĞò
*/
template <class T>
void insertion(T* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int p = i - 1;
		T temp = arr[i];
		while (arr[p] > temp && p >= 0 )
		{
			arr[p + 1] = arr[p];
			p--;
		}
		arr[p + 1] = temp;
	}
}